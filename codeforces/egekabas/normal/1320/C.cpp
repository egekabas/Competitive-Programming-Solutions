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
ll n, m, p;
pll we[200009];
pll ar[200009];
pair<pll, ll> mo[200009];
ll seg[800009];
ll lazy[800009];
void push(ll v){
    seg[2*v] += lazy[v];
    seg[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void upd(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(tr < l || r < tl)
        return;
    if(l <= tl && tr <= r){
        seg[v] += val;
        lazy[v] += val;
    }
    else{
        push(v);
        ll tm = (tl+tr)/2;
        upd(2*v, tl, tm, l, r, val);
        upd(2*v+1, tm+1, tr, l, r, val);
        seg[v] = max(seg[2*v], seg[2*v+1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> p;
    for(ll i = 0; i < n; ++i)
        cin >> we[i].ff >> we[i].ss;
    for(ll i = 0; i < m; ++i)
        cin >> ar[i].ff >> ar[i].ss;
    for(ll i = 0; i < p; ++i)
        cin >> mo[i].ff.ff >> mo[i].ff.ss >> mo[i].ss;
    
    sort(we, we+n);
    sort(ar, ar+m);
    sort(mo, mo+p);
    for(ll i = 0; i < m; ++i)
        upd(1, 0, m-1, i, i, -ar[i].ss);
    ll cur = 0;
    ll ans = -1e18;
    for(ll i = 0; i < n; ++i){
        while(cur != p && mo[cur].ff.ff < we[i].ff){
            ll idx = upper_bound(ar, ar+m, mp(mo[cur].ff.ss, ll(1e18)))-ar;
            upd(1, 0, m-1, idx, m-1, mo[cur].ss);
            ++cur;
        }
        ans = max(ans, seg[1]-we[i].ss);
    }
    cout << ans << '\n';
}