#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;

ll n, k, x;
ll a[209];
ll dp[209][209];

int main(){
    cin >> n >> k >> x;
    for(ll i = 1; i <= n; ++i )
        cin >> a[i];
    if( (x+1)*(k-1)+x < n ){
        cout << -1;
        return 0;
    }
    for(ll i = 0; i <= n; ++i)
        for(ll j = 0; j <= x; ++j)
            dp[i][j] = -(ll)1e9;

    dp[0][0] = 0;
    for(ll i = 1; i <= n; ++i)
        for(ll j = max( (ll)0, i-k); j < i ; ++j)
            for(ll s = 1; s <= x; ++s){
                if(dp[j][s-1] == -(ll)1e9)
                    continue;
                dp[i][s] = max(dp[i][s], dp[j][s-1] + a[i]);
                //cout << i << " " << s << "==>" << dp[i][s] << endl;
            }
    ll ans = -(ll)1e9;
    for(ll i = n-k+1; i <= n; ++i)
        ans = max(ans, dp[i][x]);
    cout << ans;


}