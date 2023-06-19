#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

ll n;
ll c[209][209];

ll outcom[209][209];

ll dp[209][209];

ll ans[209];

void getans(ll l, ll r, ll prt){
    if(l > r)
        return;

    for(ll i = l; i <= r; ++i)
        if(dp[l][r] == dp[l][i-1]+outcom[l][i-1]+dp[i+1][r]+outcom[i+1][r]){
            ans[i] = prt;
            getans(l, i-1, i);
            getans(i+1, r, i);
            return;
        }
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            cin >> c[i][j];

    for(ll i = 1; i <= n; ++i){
        
        for(ll j = 1; j <= n; ++j)
            outcom[i][i] += c[i][j];
        
        for(ll j = i+1; j <= n; ++j){
            outcom[i][j] = outcom[i][j-1];

            for(ll k = 1; k <= n; ++k){
                if(i <= k && k < j)
                    outcom[i][j] -= c[j][k];
                else
                    outcom[i][j] += c[j][k];
            }
            
        }
    }

    for(ll i = n; i >= 1; --i)
        for(ll j = i; j <= n; ++j){
            dp[i][j] = 1e18;

            for(ll k = i; k <= j; ++k){
                ll curval = dp[i][k-1]+outcom[i][k-1]+dp[k+1][j]+outcom[k+1][j];
                dp[i][j] = min(dp[i][j], curval);
            }
        }
    //cerr << dp[1][n] << '\n';

    getans(1, n, 0);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}