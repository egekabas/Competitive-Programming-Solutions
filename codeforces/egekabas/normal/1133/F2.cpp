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

int n, m, d, con;
vector<int> g[200009];
vector<pii> ans;
int vis[200009];
int onecon[200009];

void dfs(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 1)
            continue;
        if(con == 0 && onecon[u] == 1)
            continue;
        ans.pb({u, v});
        if(onecon[u] == 1)
            --con;
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m >> d;
    
    int t1, t2;
    for(int i = 0; i < m; ++i){
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
        if(t1 == 1) onecon[t2] = 1;
        if(t2 == 1) onecon[t1] = 1;
    }
    if(g[1].size() < d){
        cout << "NO\n";
        return 0;
    }
    con = g[1].size()-d;
    vis[1] = 1;
    for(auto u : g[1]){
        if(vis[u] == 1)
            continue;
        ans.pb({u, 1});
        dfs(u);
    }
    if(con != 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << endl;
}