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
ll a[100009][2];
ll dp[100009][2];
ll ans;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i][0];
    for(int i = 0; i < n; ++i)
        cin >> a[i][1];
    
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    ans = max(a[0][0], a[0][1]);
    for(int i = 1; i < n; ++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i][0]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+a[i][1]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << endl;
}