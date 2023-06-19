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
int dp[200009];
int a[200009];
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
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            dp[i] = 0;
        }
        sort(a+1, a+n+1);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(i-a[i] >= 0)
                dp[i] = dp[i-a[i]]+1;
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}