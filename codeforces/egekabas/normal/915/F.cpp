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
vector<ll> g[1000009];
ll n, a[1000009];

ll prt[1000009];
ll sz[1000009];
ll findprt(ll x){
    if(prt[x] == x) return x;
    return prt[x] = findprt(prt[x]);
}
void merge(ll x, ll y){
    x = findprt(x);
    y = findprt(y);
    prt[x] = y;
    sz[y] += sz[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    vector<pll> vec;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        vec.pb({a[i], i});
    }
    for(ll i = 1; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ll ans = 0;
    
    sort(vec.begin(), vec.end());
    for(auto u : vec){
        ll v = u.ss;
        prt[v] = v;
        sz[v] = 1;
        for(auto u : g[v])
            if(prt[u] != 0){
                ans += a[v]*sz[findprt(u)]*sz[findprt(v)];
                merge(u, v);
            }
    }
    reverse(vec.begin(), vec.end());
    for(ll i = 1; i <= n; ++i)
        prt[i] = 0;
    
    for(auto u : vec){
        ll v = u.ss;
        prt[v] = v;
        sz[v] = 1;
        for(auto u : g[v])
            if(prt[u] != 0){
                ans -= a[v]*sz[findprt(u)]*sz[findprt(v)];
                merge(u, v);
            }
    }
    cout << ans << '\n';
}