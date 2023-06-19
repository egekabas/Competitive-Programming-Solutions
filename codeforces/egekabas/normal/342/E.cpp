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
int n, m;
vector<int> g[100009];
int depth[100009];
int dad[100009][30];
void dfs(int v, int prt){
    dad[v][0] = prt;
    for(int i = 1; i < 30; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v]){
        if(u == prt) continue;
        depth[u] = depth[v]+1;
        dfs(u, v);
    }
}
int lca(int x, int y){
    if(depth[y] > depth[x]) swap(x, y);
    for(int i = 29; i >= 0; --i)
        if(depth[dad[x][i]] >= depth[y])
            x = dad[x][i];
    if(x == y) return y;
    for(int i = 29; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}
inline int dist(int x, int y){
    return depth[x]+depth[y]-2*depth[lca(x, y)];
}
int d[100009];
vector<int> red;
void bfs(){
    queue<int> q;
    for(auto u : red)
        if(d[u] != 0){
            d[u] = 0;
            q.push(u);
        }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : g[v]){
            if(d[u] > d[v]+1){
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
    red.clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n; ++i)
        d[i] = 1e9;
    depth[1] = 1;
    dfs(1, 0);
    red.pb(1);
    while(m--){
        if(red.size() > 100)
            bfs();
        int x, y;
        cin >> x >> y;
        if(x == 1)
            red.pb(y);
        else{
            int ans = d[y];
            for(auto u : red)
                ans = min(ans, dist(u, y));
            cout << ans << '\n';
        }
    }
}