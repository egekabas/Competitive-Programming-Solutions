#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;
int n, k;
int dp[1009][2][2][8009];
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    int mod = 998244353;
    cin >> n >> k;
    dp[0][0][0][1] = 1;
    dp[0][1][0][2] = 1;
    dp[0][0][1][2] = 1;
    dp[0][1][1][1] = 1;

    for(int i = 1; i < n; ++i)
        for(int j = 1; j <= 4*n; ++j){
            dp[i][0][0][j] = ((dp[i-1][0][0][j] + dp[i-1][1][1][j-1])%mod + (dp[i-1][1][0][j] + dp[i-1][0][1][j])%mod)%mod;
            dp[i][1][1][j] = ((dp[i-1][1][1][j] + dp[i-1][0][0][j-1])%mod + (dp[i-1][1][0][j] + dp[i-1][0][1][j])%mod)%mod;

            if(j >= 2)
                dp[i][1][0][j] = ((dp[i-1][1][0][j] + dp[i-1][0][1][j-2])%mod + (dp[i-1][0][0][j-1] + dp[i-1][1][1][j-1])%mod)%mod;
            else
                dp[i][1][0][j] = ((dp[i-1][1][0][j] +dp[i-1][0][0][j-1])%mod + dp[i-1][1][1][j-1])%mod;
            if(j >= 2)
                dp[i][0][1][j] = ((dp[i-1][0][1][j] + dp[i-1][1][0][j-2])%mod + (dp[i-1][0][0][j-1] + dp[i-1][1][1][j-1])%mod)%mod;
            else
                dp[i][0][1][j] = ((dp[i-1][0][1][j] + dp[i-1][0][0][j-1])%mod + dp[i-1][1][1][j-1])%mod;

        }

    cout << ((dp[n-1][0][0][k] + dp[n-1][1][1][k])%mod + (dp[n-1][1][0][k] + dp[n-1][0][1][k])%mod)%mod;
}