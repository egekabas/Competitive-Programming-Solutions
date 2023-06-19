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
pii edge[200009];
set<int> g[200009];
int vis[200009];
int ar[200009];
int ans;
int n, m, k;
void dfs(int v){
    if(g[v].size() >= k || vis[v] == 1) return;
    --ans;
    vis[v] = 1;
    for(auto u : g[v]){
        g[u].erase(v);
        dfs(u);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m >> k;
    int x, y;
    ans = n;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        edge[i] = {x, y};
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i = 1; i <= n; ++i)
        dfs(i);
    for(int i = m-1; i >= 0; --i){
        ar[i] = ans;
        g[edge[i].ff].erase(edge[i].ss);
        g[edge[i].ss].erase(edge[i].ff);
        dfs(edge[i].ff);
        dfs(edge[i].ss);
    }
    for(int i = 0; i < m; ++i)
        cout << ar[i] << "\n";
    
}