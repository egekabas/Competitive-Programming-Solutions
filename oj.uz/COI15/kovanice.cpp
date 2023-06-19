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
int n, m, v;
int ans[300009];
int depth[300009];
int prt[300009];
vector<int> g[300009];
int find(int x){
    if(prt[x] == x)
        return x;
    return prt[x] = find(prt[x]);
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    if(g[y].size() > g[x].size())
        swap(x, y);
    for(auto u : g[y]){
        g[x].pb(u);
    }
    g[y].clear();
    prt[y] = x;
}
int dfs1(int v){
    if(depth[v] != 0)
        return depth[v];
    for(auto u : g[v]){
        depth[v] = max(depth[v], dfs1(u));
    }
    depth[v]++;
    return depth[v];
}
void dfs2(int v, int d){
    if(ans[v] != 0)
        return;
    ans[v] = d;
    for(auto u : g[v]){
        if(dfs1(u) == d-1)
            dfs2(u, d-1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> v;
    for(int i = 1; i <= m; ++i)
        prt[i] = i;
    
    while(v--){
        int t1, t2;
        char c;
        cin >> t1 >> c >> t2;
        if(c == '=')
            merge(t1, t2);
        else{
            t1 = find(t1);
            t2 = find(t2);
            g[t2].pb(t1);
        }
    }
    
    for(int i = 1; i <= m; ++i){
        if(i != find(i))
            continue;
        for(int j = 0; j < g[i].size(); ++j)
            g[i][j] = find(g[i][j]);
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end())-g[i].begin());
    }
    for(int i = 1; i <= m; ++i){
        if(i != find(i))
            continue;
        if(dfs1(i) == n)
            dfs2(i, n);
    }
    for(int i = 1; i <= m; ++i){
        int ret = ans[find(i)];
        if(ret != 0)
            cout << "K" << ret << "\n";
        else
            cout << "?\n";
    }
}
