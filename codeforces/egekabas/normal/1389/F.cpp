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
pair<pii, int> a[200009];
int n;
int ans;
struct seg{
    vector<int> t, lazy;
    void init(int x){
        t.resize(4*x+5);
        lazy.resize(4*x+5);
    }
    void push(int v){
        t[2*v] += lazy[v];
        t[2*v+1] += lazy[v];
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
    void upd(int v, int tl, int tr, int l, int r, int val){
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r){
            t[v] += val;
            lazy[v] += val;
        }
        else{
            push(v);
            upd(2*v, tl, (tl+tr)/2, l, r, val);
            upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
            t[v] = max(t[2*v], t[2*v+1]);
        }
    }
    void change(int v, int tl, int tr, int idx, int val){
        if(idx < tl || tr < idx) return;
        if(idx == tl && idx == tr){
            t[v] = max(val, t[v]);
        }
        else{
            push(v);
            change(2*v, tl, (tl+tr)/2, idx, val);
            change(2*v+1, (tl+tr)/2+1, tr, idx, val);
            t[v] = max(t[2*v], t[2*v+1]);
        }
    }
    int get(int v, int tl, int tr, int l, int r){
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r){
            return t[v];
        }
        else{
            push(v);
            return max(get(2*v, tl, (tl+tr)/2, l, r), get(2*v+1, (tl+tr)/2+1, tr, l, r));
        }
    }
};
seg s[2];
vector<int> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].ff.ss >> a[i].ff.ff >> a[i].ss;
        a[i].ss--;
        mpp.pb(a[i].ff.ff);
        mpp.pb(a[i].ff.ss);
    }
    mpp.pb(-1);
    sort(mpp.begin(), mpp.end());
    mpp.resize(unique(mpp.begin(), mpp.end())-mpp.begin());
    for(int i = 0; i < n; ++i){
        a[i].ff.ff = lower_bound(mpp.begin(), mpp.end(), a[i].ff.ff)-mpp.begin();
        a[i].ff.ss = lower_bound(mpp.begin(), mpp.end(), a[i].ff.ss)-mpp.begin();
    }
    int on = mpp.size();
    s[0].init(on);
    s[1].init(on);
    sort(a, a+n);
    for(int i = 0; i < n; ++i){
        swap(a[i].ff.ff, a[i].ff.ss);
        s[a[i].ss^1].upd(1, 0, on-1, 0, a[i].ff.ff-1, 1);
        int val = s[a[i].ss^1].get(1, 0, on-1, 0, a[i].ff.ff-1);
        s[a[i].ss].change(1, 0, on-1, a[i].ff.ss, val);
        ans = max(ans, val);
    }
    cout << ans << '\n';
}