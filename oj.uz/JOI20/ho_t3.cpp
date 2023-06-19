#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
const ll inf = 1e18+9;
ll n, l;
ll a[209];
ll b[209];
ll dp[209][209][209][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    //freopen("in.txt", "r", stdin);                                                                                             
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> l;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    for(ll i = 1; i <= n; ++i)
        cin >> b[i];
    for(ll i1 = 0; i1 <= n+1; ++i1)
        for(ll i2 = 0; i2 <= n+1; ++i2)
            for(ll i3 = 0; i3 <= n+1; ++i3)
                for(ll i4 = 0; i4 < 2; ++i4)
                    dp[i1][i2][i3][i4] = inf;
    a[n+1] = l;
    dp[0][n+1][0][0] = dp[0][n+1][0][1] = 0;
    ll ans = 0;
    for(ll x1 = 0; x1 <= n+1; ++x1)
        for(ll x2 = n+1; x2 >= 0; --x2)
            for(ll get = 0; get <= n+1; ++get)
                for(ll st = 0; st < 2; ++st){
                    if(dp[x1][x2][get][st] == inf) continue;
                    ans = max(ans, get);
                    if(x1+1 >= x2) continue;
                    if(st == 0){
                        ll t1 = dp[x1][x2][get][st] + a[x1+1] - a[x1];
                        if(t1 <= b[x1+1])
                            dp[x1+1][x2][get+1][st] = min(dp[x1+1][x2][get+1][st], t1);
                        else
                            dp[x1+1][x2][get][st] = min(dp[x1+1][x2][get][st], t1);
                        
                        ll t2 = dp[x1][x2][get][st] + a[x1] + l-a[x2-1];
                        if(t2 <= b[x2-1])
                            dp[x1][x2-1][get+1][st^1] = min(dp[x1][x2-1][get+1][st^1], t2);
                        else
                            dp[x1][x2-1][get][st^1] = min(dp[x1][x2-1][get][st^1], t2);
                    }
                    else{
                        ll t1 = dp[x1][x2][get][st] + a[x1+1] + l-a[x2];
                        if(t1 <= b[x1+1])
                            dp[x1+1][x2][get+1][st^1] = min(dp[x1+1][x2][get+1][st^1], t1);
                        else
                            dp[x1+1][x2][get][st^1] = min(dp[x1+1][x2][get][st^1], t1);
                        
                        ll t2 = dp[x1][x2][get][st] + a[x2] - a[x2-1];
                        if(t2 <= b[x2-1])
                            dp[x1][x2-1][get+1][st] = min(dp[x1][x2-1][get+1][st], t2);
                        else
                            dp[x1][x2-1][get][st] = min(dp[x1][x2-1][get][st], t2);
                    }
                }
    cout << ans << '\n';
}
