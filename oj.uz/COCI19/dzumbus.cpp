#include <bits/stdc++.h>
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
const ll inf = 1e18+7;
int n, m;
int val[1009];
ll dp[1009][1009][2];
int vis[1009];
int sz[1009];
vector<int> g[1009];
void dfs(int v, int prt){
    sz[v] = 1;
    vis[v] = 1;
    for(int i = 1; i <= n; ++i)
        dp[v][i][0] = dp[v][i][1] = inf;
    dp[v][0][1] = inf;
    for(auto u : g[v])
        if(u != prt){
            dfs(u, v);
            sz[v] += sz[u];
        }
    for(int j = sz[prt]; j >= 0; --j)
        for(int i = 0; i+j<=n && i <= sz[v]; ++i){
            dp[prt][j+i][0] = min(dp[prt][j+i][0], dp[prt][j][0]+min(dp[v][i][0], dp[v][i][1]));
            dp[prt][j+i][1] = min(dp[prt][j+i][1], dp[prt][j][1]+min(dp[v][i][0], dp[v][i][1]));
            dp[prt][j+i+2][1] = min(dp[prt][j+i+2][1], dp[prt][j][0]+dp[v][i][0] + val[v] + val[prt]);
            dp[prt][j+i+1][1] = min(dp[prt][j+i+1][1], dp[prt][j][0]+dp[v][i][1] + val[prt]);
            dp[prt][i+j+1][1] = min(dp[prt][i+j+1][1], dp[prt][j][1]+dp[v][i][0]+val[v]);
        }
}
ll ans[1009];
int main(){
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    for(int i = 0; i < m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
 
    for(int i = 1; i <= n; ++i) ans[i] = inf;
    for(int v = 1; v <= n; ++v){
        if(vis[v]) continue;
        dfs(v, 0);
        for(int j = n; j >= 0; --j)
            for(int i = 0; i+j <= n && i <= sz[v]; ++i)
                ans[i+j] = min(ans[i+j], ans[j]+min(dp[v][i][0], dp[v][i][1]));
    }
    for(int i = n-1; i >= 0; --i){
        ans[i] = min(ans[i], ans[i+1]);
    }
    int maxval = n;
    for(int i = 0; i <= n; ++i)
        if(ans[i] > 1e9){
            maxval = i-1;
            break;
        }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        int l = 0, r = maxval;
        while(l < r){
            int mid = (l+r+1)/2;
            if(ans[mid] > x)
                r = mid-1;
            else
                l = mid;
        }
        printf("%d\n", l);
    }
}
