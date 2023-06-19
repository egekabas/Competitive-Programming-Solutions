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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n;
ll p[200009];
ll a[200009];
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
        ll tm = (tl+tr)/2;
        push(v);
        upd(2*v, tl, tm, l, r, val);
        upd(2*v+1, tm+1, tr, l, r, val);
        seg[v] = min(seg[2*v], seg[2*v+1]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> p[i];
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        upd(1, 0, n, p[i], n, a[i]);
    }
    ll ans = 1e18;
    for(ll i = 1; i < n; ++i){
        
        upd(1, 0, n, 0, p[i]-1, a[i]);
        upd(1, 0, n, p[i], n, -a[i]);
        ans = min(ans, seg[1]);

    }
    cout << ans << '\n';
}