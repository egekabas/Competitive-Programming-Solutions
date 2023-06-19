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
const ll mod = 1e9+7;
ll n, m;
ll dp[3009][3009];
ll f(ll x, ll y){
    if(x < 0 || y < 0) return 0;
    if(dp[x][y] != 0) return dp[x][y];
    if(x == 0 || y == 0) return dp[x][y] = 1;
    dp[x][y] = y*(y-1)/2*f(x-1, y-2)%mod + y*(x-1)*f(x-2, y-1)%mod + 4*y*f(x-1, y-1)%mod + f(x-1, y);
    dp[x][y] %= mod;
    return dp[x][y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    cout << f(n, m)-1 << '\n';
}
