#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
struct fen{
    vector<int> v;
    vector<int> bit;
    void add(int x){
        v.pb(x);
    }
    void init(){
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end())-v.begin());
        bit.resize(v.size()+1);
    }
    int getid(int x){
        return lower_bound(v.begin(), v.end(), x)-v.begin()+1;
    }
    void upd(int x, int y){
        x = getid(x);
        for(; x > 0; x -= x&(-x))
            bit[x] += y;
    }
    int get(int x){
        x = getid(x);
        int ret = 0;
        for(; x < bit.size(); x += x&(-x))
            ret += bit[x];
        //cout << ret << " HEY\n";
        return ret;
    }
};
fen seg[1200000];
void add(int v, int tl, int tr, int idx, int val){
    seg[v].add(val);
    if(idx == tl && idx == tr) return;
    if(idx <= (tl+tr)/2)
        add(2*v, tl, (tl+tr)/2, idx, val);
    else
        add(2*v+1, (tl+tr)/2+1, tr, idx, val);
}
void init(int v, int tl, int tr){
    seg[v].init();
    if(tl == tr) return;
    init(2*v, tl, (tl+tr)/2);
    init(2*v+1, (tl+tr)/2+1, tr); 
}
void upd(int v, int tl, int tr, int idx, int place, int val){
    seg[v].upd(place, val);
    if(idx == tl && idx == tr) return;
    if(idx <= (tl+tr)/2)
        upd(2*v, tl, (tl+tr)/2, idx, place, val);
    else
        upd(2*v+1, (tl+tr)/2+1, tr, idx, place, val);
}
int get(int v, int tl, int tr, int l, int r, int place){
    if(r < tl || tr < l) return 0;
    if(l <= tl && tr <= r){
        return seg[v].get(place);
    }
    else{
        return get(2*v, tl, (tl+tr)/2, l, r, place)+
        get(2*v+1, (tl+tr)/2+1, tr, l, r, place);
    }
}
bitset<300009> lbeg;
set<pii> beg;
int n, q;
pair<int, pii> qu[300009];
vector<pair<pii, int>> erased;
void addlight(int idx, set<pair<pii, int>> &s, int time){
    int l = idx;
    int r = idx;
    auto it = s.upper_bound({{idx,1e9}, 1e9});
    if(it != s.end() && (*it).ff.ff == idx+1){
        erased.pb(*it);
        r = (*it).ff.ss;
        s.erase(it);
    }
    it = s.upper_bound({{idx,1e9}, 1e9});
    if(it != s.begin()){
        --it;
        if((*it).ff.ss == idx-1){
            erased.pb(*it);
            l = (*it).ff.ff;
            s.erase(it);
        }
    }
    s.insert({{l, r}, time});
}
void eraselight(int idx, set<pair<pii, int>> &s, int time){
    auto it = s.upper_bound({{idx, 1e9}, 1e9});
    --it;
    
    if(idx != (*it).ff.ff)
        s.insert({{(*it).ff.ff, idx-1}, time});
    if(idx != (*it).ff.ss)
        s.insert({{idx+1, (*it).ff.ss}, time});
    erased.pb(*it);
    s.erase(it);
}
bitset<300009> st;
set<pair<pii, int>> s;
void initall(){
    s.clear();
    for(auto u : beg)
        s.insert({u, 0});
    st = lbeg;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> q;
    string str;
    cin >> str;
    for(int i = 0; i < n; ++i){
        lbeg[i] = (str[i]=='1');
    }
    int last = n;
    for(int i = n-1; i >= 0; --i){
        if(lbeg[i] == 0)
            last = i;
        else if(i == 0 || lbeg[i-1] == 0)
            beg.insert({i, last-1});
    }
 
    initall();
 
    for(int i = 1; i <= q; ++i){
        string str;
        cin >> str;
        if(str == "toggle"){
            int x;
            cin >> x;
            --x;
            qu[i].ff = 0;
            qu[i].ss.ff = x;
            if(st[x])
                eraselight(x, s, i);
            else
                addlight(x, s, i);
            st[x] = (!st[x]);
 
        }
        else{
            int x, y;
            cin >> x >> y;
            --x;
            y -= 2;
            qu[i] = {1, {x, y}};
        }
    }
    for(auto u : erased){
        add(1, 0, n-1, u.ff.ff, u.ff.ss);
    }
    erased.clear();
    init(1, 0, n-1);
    initall();
    for(ll i = 1; i <= q; ++i){
        if(qu[i].ff == 0){
            int x = qu[i].ss.ff;
            if(st[x])
                eraselight(x, s, i);
            else
                addlight(x, s, i);
            for(auto u : erased)
                upd(1, 0, n-1, u.ff.ff, u.ff.ss, i-u.ss);
            erased.clear();
            st[x] = (!st[x]);
        }
        else{
            int x = qu[i].ss.ff;
            int y = qu[i].ss.ss;
            int ans = get(1, 0, n-1, 0, x, y);
            auto it = s.upper_bound({{x, 1e9}, 1e9});
            if(it != s.begin()){
                --it;
                if((*it).ff.ss >= y)
                    ans += i-(*it).ss;
            }
            cout << ans << '\n';
        }
    }
}
