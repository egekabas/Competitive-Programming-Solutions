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
ll n, sum;
ll a[200009];
ll sumb[200009];
vector<ll> g[200009];
ll dp[200009];
ll vis[200009];
ll dfs1(ll v, ll dis){
    dp[1] += dis*a[v];
    sumb[v] = a[v];
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 1)continue;
        sumb[v] += dfs1(u, dis+1);
    }
    return sumb[v];
}
void dfs2(ll v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 1)continue;
        dp[u] = dp[v]-2*sumb[u]+sum;
        dfs2(u);
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
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    ll tmp1, tmp2;
    for(ll i = 0; i < n-1; ++i){
        cin >> tmp1 >> tmp2;
        g[tmp1].pb(tmp2);
        g[tmp2].pb(tmp1);
    }
    dfs1(1, 0);
    for(ll i = 1; i <= n; ++i) vis[i] = 0;
    dfs2(1);
    ll ans = -1e9;
    for(ll i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << ans << endl;
}