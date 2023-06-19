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

ll mod = 1e9+7;
ll dp[15][1005][1005][2];
ll n, m;
ll f(ll idx, ll x, ll y, ll up){
    if(dp[idx][x][y][up] != -1)
        return dp[idx][x][y][up];
    if(x > y)
        return dp[idx][x][y][up] = 0;
    if(idx >= m)
        return dp[idx][x][y][up] = 1;
    if(up == 1)
        return dp[idx][x][y][up] = (f(idx, x+1, y, 1)+f(idx, x, y, 0))%mod;
    else
        return dp[idx][x][y][up] = (f(idx+1, x, y, 1)+f(idx, x, y-1, 0))%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(ll i = 0; i <= m; ++i)
        for(ll j = 0; j <= n; ++j)
            for(ll k = 0; k <= n; ++k)
                dp[i][j][k][1] = dp[i][j][k][0] = -1;
    cout << f(0, 1, n, 1) << "\n";
}