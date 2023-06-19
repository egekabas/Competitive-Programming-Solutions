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
ll n;
vector<ll> g[200009];
ll dp[200009];
ll ans[200009];
ll sz[200009];
ll vis[200009];
ll val;

void fin(ll v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 1) continue;
        ans[u] = ans[v]+n-2*sz[u];
        fin(u);
    }
    val = max(ans[v], val);
}

ll func(ll v){
    vis[v] = 0;
    if(dp[v] != 0) return dp[v];
    if(g[v].size() == 1 && v != 1) return dp[v] = 1;
    dp[v] = sz[v];
    for(auto u : g[v]){
        if(vis[u] == 1){
            dp[v] += func(u);
        }
    }
    return dp[v];
}

void dfs(ll v){
    sz[v] = vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 0){
            dfs(u);
            sz[v] += sz[u];
        }
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

    cin >> n;
    ll t1, t2;
    for(ll i = 0; i < n-1; ++i){
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
    }
    dfs(1);
    func(1);
    ans[1] = dp[1];
    fin(1);
    cout << val << endl;
}