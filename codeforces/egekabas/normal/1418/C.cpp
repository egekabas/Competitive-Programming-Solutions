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
int a[200009];
int dp[200009][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i <= n; ++i)
            dp[i][0] = dp[i][1] = 1e9;
        dp[0][1] = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 2; ++j){
                dp[i][j] += (a[i]&j);
                dp[i+1][j^1] = min(dp[i+1][j^1], dp[i][j]);
                dp[i+2][j^1] = min(dp[i+2][j^1], dp[i][j]+(a[i+1]&j));
            }
        cout << min({dp[n-1][0], dp[n-1][1], dp[n][0], dp[n][1]}) << '\n';
    }
}