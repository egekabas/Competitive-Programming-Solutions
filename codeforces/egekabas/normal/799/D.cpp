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
 
ll a, b, h, w, n;
ll ex[100009];
ll dp[50][100009];
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> a >> b >> h >> w >> n;
    for(ll i = 0; i < n; ++i)
        cin >> ex[i];
    sort(ex, ex+n, greater<ll>());
    
    dp[0][h] = w;
    for(ll i = 0; i < n; ++i){
        for(ll j = 1; j <= 1e5; ++j){
            if(j >= a && dp[i][j] >= b){
                cout << i << endl;
                return 0;
            }
            if(j >= b && dp[i][j] >= a){
                cout << i << endl;
                return 0;
            }
            ll nextj = min((ll)1e5, j*ex[i]); 
            ll nextv = min(dp[i][j]*ex[i], (ll)1e5);
 
            dp[i+1][nextj] = max(dp[i][j], dp[i+1][nextj]);
            dp[i+1][j] = max(nextv, dp[i+1][j]);
        }
    }
    for(ll j = 1; j <= 1e5; ++j){
            if(j >= a && dp[n][j] >= b){
                cout << n << endl;
                return 0;
            }
            if(j >= b && dp[n][j] >= a){
                cout << n << endl;
                return 0;
            }
    }
    cout << "-1\n";
}