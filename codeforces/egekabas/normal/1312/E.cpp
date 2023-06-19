#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int n;
int a[1009];
int dp[509][509];
int ans[509];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = n-1; i >= 0; --i)
        for(int j = i; j < n; ++j){
            if(i == j)
                dp[i][j] = a[i];
            for(int k = i; k < j; ++k)
                if(dp[i][k] == dp[k+1][j] && dp[i][k] != 0)
                    dp[i][j] = dp[i][k]+1;
        }
    
    for(int i = 0; i <= n; ++i) ans[i] = n;
    ans[0] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j)
            if(dp[i][j] != 0){
                ans[j+1] = min(ans[j+1], ans[i]+1);
            }
    cout << ans[n] << '\n';
}