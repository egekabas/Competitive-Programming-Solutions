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
ll n, q;
vector<pll> g[400009];

ll val[400009];

ll dad[400009][30];
ll depth[400009];

ll downdp[400009];
ll updp[400009];
ll upsum[400009];
ll upedge[400009];

ll dfs1(ll v, ll prt){
    dad[v][0] = prt;
    for(ll i = 1; i < 30; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v]){
        if(u.ff == prt) continue;
        depth[u.ff] = depth[v]+1;
        dfs1(u.ff, v);
        downdp[v] += max(0LL, downdp[u.ff]+val[u.ff]-2*u.ss);
        upedge[u.ff] = u.ss;
    }
}
ll dfs2(ll v, ll prt){
    for(auto u : g[v]){
        if(u.ff == prt) continue;
        downdp[v] -= max(0LL, downdp[u.ff]+val[u.ff]-2*u.ss);
        upsum[u.ff] = -u.ss+val[v] + downdp[v] + upsum[v];
        updp[u.ff] = max(0LL, -2*u.ss+val[v]+downdp[v]+updp[v]);
        dfs2(u.ff, v);
        downdp[v] += max(0LL, downdp[u.ff]+val[u.ff]-2*u.ss);
    }
}
ll lca(ll x, ll y){
    if(depth[y] > depth[x])
        swap(x, y);
    for(ll i = 29; i >= 0; --i)
        if(depth[dad[x][i]] >= depth[y])
            x = dad[x][i];
    if(x == y)
        return x;
    for(ll i = 29; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}
ll upto(ll x, ll y){
    for(ll i = 29; i >= 0; --i)
        if(depth[dad[x][i]] > depth[y])
            x = dad[x][i];
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i)
        cin >> val[i];
    for(ll i = 1; i < n; ++i){
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    depth[1] = 1;
    dfs1(1, 0);
    dfs2(1, 0);
    for(ll i = 0; i < q; ++i){
        ll x, y;
        cin >> x >> y;
        ll p = lca(x, y);
        if(y == p)
            swap(x, y);
        ll ans;
        if(x == y){
            ans = updp[x]+val[x]+downdp[x];
        }
        else if(x != p){
            ll uptox = upto(x, p);
            ll uptoy = upto(y, p);
            ans = downdp[x]+downdp[y]+upsum[x]-upsum[uptox]+upsum[y]-upsum[uptoy];
            ans += val[x]+val[y]+val[p]-upedge[uptox]-upedge[uptoy];
            ans += updp[p]+downdp[p]-max(0LL, downdp[uptox]+val[uptox]-2*upedge[uptox])-max(0LL, downdp[uptoy]+val[uptoy]-2*upedge[uptoy]);
        }
        else{
            ll uptoy = upto(y, x);
            ans = upsum[y]-upsum[uptoy]+val[y]+downdp[y]+val[x]-upedge[uptoy];
            ans += updp[x]+downdp[x]-max(0LL, downdp[uptoy]+val[uptoy]-2*upedge[uptoy]);
        }
        cout << ans << '\n';
    }
}