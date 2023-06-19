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
int n, m;
string a, b;
int dp[5009][5009];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> a >> b;

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j){
            if(i > 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
            if(j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
            if(i > 0 && j > 0 && a[i-1] == b[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
            ans = max(ans, dp[i][j]);
        }
    cout << ans << '\n';
}