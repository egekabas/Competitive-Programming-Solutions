#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
ll mod = 1e9+7;
ll n;
vector<ll> g[100009];
ll col[100009];
ll dp[100009][2];
void dfs(ll v, ll prt){
    dp[v][col[v]] = 1;
    for(auto u : g[v]){
        if(u == prt) continue;
        dfs(u, v);
        
        dp[v][1] *= (dp[u][0]+dp[u][1])%mod;
        dp[v][1] %= mod;

        dp[v][1] += dp[v][0]*dp[u][1]%mod;
        dp[v][1] %= mod;

        dp[v][0] *= (dp[u][0]+dp[u][1])%mod;
        dp[v][0] %= mod;
    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i < n; ++i){
        ll prt;
        cin >> prt;
        g[prt].pb(i);
        g[i].pb(prt);
    }
    for(ll i = 0; i < n; ++i)
        cin >> col[i];
    dfs(0, -1);
    cout << dp[0][1] << '\n';
}