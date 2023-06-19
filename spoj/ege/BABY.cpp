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
ll dp[20][1<<17];
ll a[20];
ll b[20];
ll func(ll cur, ll bit){
    if(dp[cur][bit] != -1)
        return dp[cur][bit];
    if(cur == n)
        return dp[cur][bit] = 0;
    dp[cur][bit] = 1e9;
    for(ll i = 0; i < n; ++i){
        if(((1<<i)&bit) == 0)
            continue;
        dp[cur][bit] = min(dp[cur][bit], abs(i-cur)+abs(a[i]-b[cur])+func(cur+1, bit-(1<<i)));
    }
    return dp[cur][bit];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(1){
        cin >> n;
        if(n == 0)
            break;
        for(ll i = 0; i <= n; ++i)
            for(ll j = 0; j < (1<<n); ++j)
                dp[i][j] = -1;
        
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        for(ll i = 0; i < n; ++i)
            cin >> b[i];
        
        cout << func(0, (1<<n)-1) << "\n";
    }
