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
ll n;
vector<ll> g[100009];
ll depth[100009];
ll dad[100009][30];
void dfs(ll v, ll prt){
    dad[v][0] = prt;
    for(ll i = 1; i < 30; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v]){
        if(u == prt)
            continue;
        depth[u] = depth[v]+1;
        dfs(u, v);
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
    return dad[y][0];
}
ll dist(ll x, ll y){
    ll lc = lca(x, y);
    return depth[x]-depth[lc]+depth[y]-depth[lc];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    ll q;
    cin >> q;
    while(q--){
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        if(dist(a, b) <= k && (k-dist(a, b)) % 2 == 0)
            cout << "YES\n";
        else if(dist(a, x)+dist(b, y)+1 <= k && (k-(dist(a, x)+dist(b, y)+1)) % 2 == 0)
            cout << "YES\n";
        else if(dist(a, y)+dist(b, x)+1 <= k && (k-(dist(a, y)+dist(b, x)+1)) % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}