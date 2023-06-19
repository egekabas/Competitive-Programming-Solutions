#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;

int seg[400009];
void upd(int v, int tl, int tr, int idx, int val){
    if(idx < tl || idx > tr) return;
    if(idx == tl && idx == tr)
        seg[v] = val;
    else{
        int tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx, val);
        upd(2*v+1, tm+1, tr, idx, val);
        seg[v] = max(seg[2*v], seg[2*v+1]);
    }
}
int get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l) return 0;
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        int tm = (tl+tr)/2;
        return max(get(2*v, tl, tm, l, r),get(2*v+1, tm+1, tr, l, r));
    }
}
int n, m;
int bit[400009];
int getbit(int idx){
    int ret = 1e9;
    for(; idx <= n; idx += idx&(-idx))
        ret = min(ret, bit[idx]);
    return ret;
}
void updbit(int idx, int val){
    for(; idx > 0; idx -= idx&(-idx))
        bit[idx] = min(val, bit[idx]);
}
int a[400009];
int ans[400009];
vector<pii> qs[400009];

void solve(){
    for(int i = 1; i <= 4*n; ++i)
        seg[i] = 0;
    vector<pii> v;
    for(int i = 1; i <= n; ++i){
        v.pb({a[i], i});
        bit[i] = 1e9;
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; ++i){
        int aidx = lower_bound(v.begin(), v.end(), mp(a[i], 0))-v.begin();
        int cur = get(1, 0, n-1, aidx, n-1);
        while(cur != 0){
            updbit(cur, a[cur]-a[i]);
            //cout << a[cur]-a[i] << ' ' << getbit(cur) << '\n';
            int bidx = upper_bound(v.begin(), v.end(), mp(min(a[cur]-1, (a[i]+a[cur]-1)/2), int(1e9)))-v.begin();
            --bidx;
            cur = get(1, 0, n-1, aidx, bidx);
        }
        for(auto u : qs[i])
            ans[u.ss] = min(ans[u.ss], getbit(u.ff));
        upd(1, 0, n-1, lower_bound(v.begin(), v.end(), mp(a[i], i))-v.begin(), i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        qs[r].pb({l, i});
        ans[i] = 1e9;
    }
    solve();
    for(int i = 1; i <= n; ++i)
        a[i] *= -1;
    solve();
    for(int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
}