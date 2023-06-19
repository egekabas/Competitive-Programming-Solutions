#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
struct seg{
    int n;
    vector<int> vec;
    vector<int> lazy;
    
    seg(){}
    seg(int _n){
        n = _n;
        vec.resize(4*n+4);
        lazy.resize(4*n+4);
    }
    void push(int v, int tl, int tr){
        if(!lazy[v]) return;
        int tm = (tl+tr)/2;
        
        
        lazy[2*v] = lazy[v];
        vec[2*v] = lazy[v] + (tm-tl);

        lazy[2*v+1] = lazy[v]+(tm+1-tl);
        vec[2*v+1] = lazy[v] + (tr-tl);

        lazy[v] = 0;
    }
    int get(int v, int tl, int tr, int val){
        if(vec[v] < val)
            return n;
        if(tl == tr)
            return tl;

        push(v, tl, tr);

        if(vec[2*v] >= val)
            return get(2*v, tl, (tl+tr)/2, val);
        else
            return get(2*v+1, (tl+tr)/2+1, tr, val);
    }
    void upd(int v, int tl, int tr, int l, int r, int val){
        if(tr < l || r < tl)
            return;
        if(l <= tl && tr <= r){
            lazy[v] = val;
            vec[v] = val+(tr-tl);
        }
        else{
            push(v, tl, tr);

            upd(2*v, tl, (tl+tr)/2, l, r, val);

            int oth = max(0, min((tl+tr)/2, r)-max(tl, l)+1);

            upd(2*v+1, (tl+tr)/2+1, tr, l, r, val+oth);
            vec[v] = max(vec[2*v], vec[2*v+1]);

        }
    }
    void build(int v, int tl, int tr, vector<int> &a){
        if(tl > tr)
            return;
        if(tl == tr){
            vec[v] = a[tl];
            return;
        }
        build(2*v, tl, (tl+tr)/2, a);
        build(2*v+1, (tl+tr)/2+1, tr, a);
        vec[v] = max(vec[2*v], vec[2*v+1]);
    }
    void fin(int v, int tl, int tr, vector<int> &a){
        if(tl > tr)
            return;
        //cout  << tl << ' ' << tr << ' ' << vec[v] << '\n';
        if(tl == tr){
            a[tl] = vec[v];
            return;
        }
        push(v, tl, tr);
        fin(2*v, tl, (tl+tr)/2, a);
        fin(2*v+1, (tl+tr)/2+1, tr, a);
    }
};

const int ALP = 'z'-'a'+1;
int n, m;
vector<int> v[ALP];
seg s[ALP];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    
    string str;
    cin >> str;
    for(int i = 0; i < n; ++i)
        v[str[i]-'a'].pb(i+1);

    for(int i = 0; i < ALP; ++i){
        s[i] = seg(v[i].size());
        s[i].build(1, 0, s[i].n-1, v[i]);
    }
    
    while(m--){
        int l, r;
        cin >> l >> r;
        int odd = 0;
        for(int i = 0; i < ALP; ++i){
            int cnt = s[i].get(1, 0, s[i].n-1, r+1)-s[i].get(1, 0, s[i].n-1, l);
            odd += cnt%2;
        }
        if(odd > 1)
            continue;
        int bef = 0;
        for(int i = 0; i < ALP; ++i){
            int tr = s[i].get(1, 0, s[i].n-1, r+1)-1;
            int tl = s[i].get(1, 0, s[i].n-1, l);
            int cnt = tr-tl+1;

            if(!cnt)
                continue;

            s[i].upd(1, 0, s[i].n-1, tl, tl+(cnt)/2-1, l+bef);
            if(cnt%2)
                s[i].upd(1, 0, s[i].n-1, (tl+tr)/2, (tl+tr)/2, (l+r)/2);
            //cout << r-bef-(cnt/2)+1 << '\n';
            s[i].upd(1, 0, s[i].n-1, tr-(cnt)/2+1, tr, r-bef-(cnt)/2+1);
            
            bef += cnt/2;
        }
    }

    //cout << "HEY\n";

    string ans;
    ans.resize(n);
    for(int i = 0; i < ALP; ++i){
        vector<int> v(s[i].n);
        s[i].fin(1, 0, s[i].n-1, v);
        for(auto u : v){
            ans[u-1] = i+'a';
            //cout << u-1 << '\n';
        }
    }

    cout << ans << '\n';

}