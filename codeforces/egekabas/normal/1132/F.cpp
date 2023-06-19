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
ll n, dp[509][509];
int aft[509];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> s;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = 1e9;
    aft[n-1] = n-1;
    for(int i = n-2; i >= 0; --i)
        aft[i] = ((s[i] == s[i+1])?aft[i+1]:i);

    for(int i = n-1; i >= 0; --i)
        for(int j = i; j < n; ++j){
            if(i == j){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i+1][j]+(s[i]!=s[i+1]);
            for(ll k = i+1; k <= j; ++k)
                if(s[i] == s[k]){
                    dp[i][j] = min(dp[i][j], dp[i+1][k]+dp[k+1][j]);
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k][j]);
                }
        }
    cout << dp[0][n-1] << "\n";
}