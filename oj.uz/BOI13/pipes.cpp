#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
ll n, m;
ll vert[100009];
ll deg[100009];
vector<pll> g[100009];
ll vis[100009];
ll ans[500009];
pll val[500009];
void dfs1(ll v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u.ff])
            continue;
        ans[u.ss] = vert[v];
        vert[v] -= ans[u.ss];
        vert[u.ff] -= ans[u.ss];
        deg[v]--;
        deg[u.ff]--;
        if(deg[u.ff] <= 1)
            dfs1(u.ff);
    }
}
void dfs2(ll v, pll curval){
    vis[v] = 1;
    for(auto u : g[v]){
        if(deg[u.ff] == 0)
            continue;
        if(val[u.ss].ff == 0)
            val[u.ss] = curval;
        if(vis[u.ff])
            continue;
        dfs2(u.ff, {-curval.ff, vert[u.ff]-curval.ss});
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    if(m > n){
        cout << "0\n";
        return 0;
    }
    for(ll i = 1; i <= n; ++i)
        cin >> vert[i];
    for(ll i = 0; i < m; ++i){
        ll x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    for(ll i = 1; i <= n; ++i)
        if(vis[i] == 0 && deg[i] == 1)
            dfs1(i);
    ll var;
    for(ll i = 1; i <= n; ++i)
        if(vis[i] == 0){
            vector<ll> ed;
            for(auto u : g[i])
                if(vis[u.ff] == 0)
                    ed.pb(u.ss);
            dfs2(i, {1, 0});
            pll curval = {val[ed[0]].ff+val[ed[1]].ff, val[ed[0]].ss+val[ed[1]].ss};
            if(curval.ff == 0){
                cout << "0\n";
                return 0;
            }
            var = (vert[i]-curval.ss)/curval.ff;
        }
    for(int i = 0; i < m; ++i){
        if(val[i].ff != 0)
            ans[i] = var*val[i].ff+val[i].ss;
        cout << 2*ans[i] << '\n';
    }
}
