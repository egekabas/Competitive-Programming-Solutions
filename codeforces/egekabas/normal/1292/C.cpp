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
vector<ll> g[3009];
ll n;
ll sz[3009];
ll depth[3009];
ll dad[3009][3009];
void precalc(ll v, ll prt){
    sz[v] = 1;
    dad[v][0] = v;
    for(ll i = 1; i <= n; ++i)
        dad[v][i]= dad[prt][i-1];
    for(auto u : g[v]){
        if(u == prt)
            continue;
        depth[u] = depth[v]+1;
        precalc(u, v);
        sz[v] += sz[u];
    }
}
ll dp[3009][3009];
ll f(ll x, ll y){
    if(dp[x][y] != -1) return dp[x][y];
    ll &cur = dp[x][y];
    cur = 0;
    if(depth[y] > depth[x])
        swap(y, x);
    ll dif = depth[x]-depth[y];
    if(x == y){
        for(auto u : g[x]){
            if(u == dad[x][1])
                cur = max(cur, sz[x]*(sz[1]-sz[x])+f(u, x));
            else
                cur = max(cur, sz[u]*(sz[1]-sz[u])+f(u, x));
        }
    }
    else if(dad[x][dif] != y){
        for(auto u : g[x]){
            if(u == dad[x][1])
                continue;
            cur = max(cur, sz[y]*sz[u]+f(u, y));
        }
        for(auto u : g[y]){
            if(u == dad[y][1])
                continue;
            cur = max(cur, sz[x]*sz[u]+f(u, x));
        }
    }
    else{
        for(auto u : g[x]){
            if(u == dad[x][1])
                continue;
            cur = max(cur, (sz[1]-sz[dad[u][dif]])*sz[u]+f(u, y));
        }
        for(auto u : g[y]){
            if(u == dad[x][dif-1])
                continue;
            if(u != dad[y][1])
                cur = max(cur, sz[x]*sz[u]+f(u, x));
            else
                cur = max(cur, sz[x]*(sz[1]-sz[y])+f(u, x));
        }
    }
    //cout << x << ' ' << y << ' ' << cur << '\n';
    return cur;
}
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);;
        g[y].pb(x);;
    }
    precalc(1, 0);
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            dp[i][j] = -1;
    //f(5, 1);return 0;
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        ans = max(ans, f(i, i));
    }
    cout << ans << '\n';
}