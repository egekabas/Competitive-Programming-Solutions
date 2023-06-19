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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n;
ll a[3009];
ll dp[3009][3009];
ll pre[3009][3009];
void solve(){
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        for(ll j = 0; j <= n; ++j){
            dp[i][j] = 1e18;
            pre[i][j] = 0;
        }
    }
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j <= n; ++j)
            if(i+a[i] >= j)
                pre[i][j]++;
    for(ll i = 1; i < n; ++i)
        for(ll j = 0; j <= n; ++j)
            pre[i][j] += pre[i-1][j];
    for(ll j = 0; j < n; ++j)
        dp[0][j] = 0;
    for(ll i = 0; i < n; ++i){
        for(ll j = i+1; j <= i+a[i]; ++j){
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if(dp[i][j] == 1e18) continue;
            
            dp[j][i+a[i]+1] = min(dp[j][i+a[i]+1], dp[i][j]+pre[j-1][j]-pre[i][j]);

        }
    }
    cout << dp[n-1][n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}