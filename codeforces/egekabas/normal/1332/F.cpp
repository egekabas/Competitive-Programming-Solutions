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
const ll mod = 998244353;

ll n, m;
vector<ll> g[300009];
ll dp[300009];
ll conno[300009];
ll conyes[300009];
void dfs(ll v, ll prt){
    dp[v] = 1;
    conyes[v] = conno[v] = 1;
    for(auto u : g[v]){
        if(u == prt) continue;
        dfs(u, v);
        dp[v] = dp[v]*dp[u]%mod;
        conno[v] = conno[v]*((conyes[u]+conno[u]+dp[u])%mod)%mod;
        conyes[v] = conyes[v]*((conno[u]+dp[u])%mod)%mod;
    }
    dp[v] += conno[v]+conyes[v];
    dp[v] %= mod;
    int tmp = 1;
    for(auto u : g[v]){
        if(u == prt) continue;
        tmp = tmp*dp[u]%mod;  
    }
    dp[v] -= 2*tmp%mod;
    dp[v] = (dp[v]+mod)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    cout << dp[1]-1 << '\n';
}