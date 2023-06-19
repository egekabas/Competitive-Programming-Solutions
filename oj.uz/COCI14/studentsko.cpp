#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, k;
int dp[2][5009];
pii a[5009];
int team[5009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i].ff;
        a[i].ss = i;
    }
    sort(a, a+n);
    for(int i = 0; i < n; ++i){
        team[a[i].ss] = i/k;
    }
    for(int i = 0; i < n; ++i){
        int mini = 1e9;
        for(int j = 0; j <= (n-1)/k; ++j){
            if(i == 0){
                dp[i%2][j] = 1;
                continue;
            }
            mini = min(mini, dp[(i%2)^1][j]);
            dp[(i%2)][j] = mini+1;
        }
        --dp[(i%2)][team[i]];
    }
    int ans = 1e9;
    for(int j = 0; j <= (n-1)/k; ++j)
        ans = min(ans, dp[(n-1)%2][j]);
    cout << ans << "\n";
}
