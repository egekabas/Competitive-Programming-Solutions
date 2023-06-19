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
ll n;
ll a[509];
ll dp[509][100009];
ll tot;
ll f(ll x, ll y){
    if(y > 100000)
        return 1e18;
    if(dp[x][y] != -1)
        return dp[x][y];
    if(x == 0){
        if(y == 0)
            return dp[x][y] = a[x];
        else if(y == a[x])
            return dp[x][y] = 0;
        else
            return dp[x][y] = 1e18;
    }
    dp[x][y] = min(f(x-1, y)+a[x], f(x-1, abs(y-a[x])));
    dp[x][y] = min(dp[x][y], f(x-1, abs(y+a[x])));
    return dp[x][y];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        tot += a[i];
    }
    for(ll i = 0; i <= 500; ++i)
        for(ll j = 0; j <= 100000; ++j)
            dp[i][j] = -1;
    ll left = f(n-1, 0);
    cout << left+(tot-left)/2 << "\n";
}
