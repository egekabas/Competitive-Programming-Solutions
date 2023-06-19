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
ll n, lg;
vector<ll> v;
ll bin(ll x){
    ll ret = 0;
    while(x > 1){
        ++ret;
        x/= 2;
    }
    return ret;
}
ll dp[1000009][20];
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll neg = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i){
        ll t1;
        cin >> t1;
        if(t1 == -1){
            neg = 1;
        }
        else if(neg == 0){
            v.pb(0);
        }
        else{
            v.pb(t1);
        }
    }
    lg = bin(n);
    --n;
    for(ll i = 0; i <= n; ++i)
        for(ll j = 0; j <= lg; ++j)
            dp[i][j] = 1e18;
    dp[0][0] = v[0];
    for(ll i = 1; i < n; ++i)
        for(ll j = 0; j < lg; ++j){
            dp[i][j] = dp[i-1][j];
            if(j == 0)
                dp[i][j] = min(dp[i][j], v[i]);
            ll need = (1<<(j+1))-1;
            if(i+1 >= need && j > 0)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+v[i]);
        //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    ll ans = 1e18;
    for(ll i = 0; i < n; ++i)
        ans = min(ans, dp[i][lg-1]);
    cout << ans << "\n";
}