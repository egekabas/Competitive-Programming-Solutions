#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, m;
vector<int> g[5009];
int col[5009];
int vis[5009];
int n1, n2, n3;
pii dfs1(int v){
    vis[v] = 1;
    pii ret;
    if(col[v] == 0)
        ret.ff = 1;
    else
        ret.ss = 1;
    for(auto u : g[v]){
        if(vis[u] && col[u] == col[v]){
            cout << "NO\n";
            exit(0);
        }
        if(vis[u] == 0){
            col[u] = col[v]^1;
            pii tmp = dfs1(u);
            ret.ff += tmp.ff;
            ret.ss += tmp.ss;
        }
    }
    return ret;
}
int dp[5009][5009];
int ans[5009];
void dfs2(int v, int two){
    if(col[v] == two)
        ans[v] = 2;
    else if(n1 > 0){
        --n1;
        ans[v] = 1;
    }
    else
        ans[v] = 3;
    vis[v] = 1;
    for(auto u : g[v])
        if(vis[u] == 0)
            dfs2(u, two);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    while(m--){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<pair<int, pii>> v;
    for(int i = 1; i <= n; ++i)
        if(vis[i] == 0){
            v.pb({i, dfs1(i)});
        }
    if(n2-v[0].ss.ff >= 0)
        dp[0][n2-v[0].ss.ff] = 1;
    if(n2-v[0].ss.ss >= 0)
        dp[0][n2-v[0].ss.ss] = 1;
    for(int i = 1; i < v.size(); ++i)
        for(int j = 0; j <= n2; ++j)
            if(dp[i-1][j] == 1){
                if(j-v[i].ss.ff >= 0)
                    dp[i][j-v[i].ss.ff] = 1;
                if(j-v[i].ss.ss >= 0)
                    dp[i][j-v[i].ss.ss] = 1;
            }
    if(dp[int(v.size())-1][0] == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
        vis[i] = 0;
    int cur = 0;
    for(int i = v.size()-1; i > 0; --i){
        if(dp[i-1][cur+v[i].ss.ff] == 1){
            cur += v[i].ss.ff;
            dfs2(v[i].ff, 0);
        }
        else{
            cur += v[i].ss.ss;
            dfs2(v[i].ff, 1);
        }
    }
    if(cur+v[0].ss.ff == n2){
        dfs2(v[0].ff, 0);
    }
    else{
        dfs2(v[0].ff, 1);
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i];
}