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
ll vis[200009];
ll dp[300009];
ll ans = 1;
ll mod = 998244353;
ll fact(ll x){
    if(dp[x] != 0)
        return dp[x];
    if(x == 0 || x == 1)
        return dp[x] = 1;
    return dp[x] = (x*fact(x-1))%mod;
}
void dfs(ll v){
    vis[v] = 1;
    ll cnt = 0;
    for(auto u : g[v]){
        if(vis[u] == 1) continue;
        ++cnt;
        dfs(u);
    }
    if(v != 1)
        ans = (ans*fact(cnt+1))%mod;
    else if(v == 1)
        ans = (ans*fact(cnt))%mod;
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
        g[t1].pb(t2); g[t2].pb(t1);
    }
    dfs(1);
    cout << (ans*n)%mod << endl;
}