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
const ll mod = 998244353;
string s, t;
ll dp[3009][3009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //aaa

    cin >> s >> t;
    for(ll j = 0; j <= t.size(); ++j)
        dp[0][j] = 1;
    for(ll i = 0; i < s.size(); ++i){
        for(ll j = 0; j <= t.size(); ++j){
            if(j+i >= t.size())
                dp[i+1][j] = (dp[i][j]+dp[i+1][j])%mod;
            else if(t[j+i] == s[i])
                dp[i+1][j] = (dp[i][j]+dp[i+1][j])%mod;
            if(j != 0 && s[i] == t[j-1]){
                dp[i+1][j-1] = (dp[i][j]+dp[i+1][j-1])%mod;
            }
            if(i == 0 && j != t.size() && s[i] == t[j]){
                --dp[i+1][j];
                if(dp[i+1][j] < 0) dp[i+1][j] += mod;
            }
            if(j == t.size() && i != 0){
                dp[i+1][j] = (dp[i][j]+dp[i+1][j])%mod;
            }
        }
    }
    ll ans = 0;
    for(ll i = t.size(); i <= s.size(); ++i)
        ans = (ans+2*dp[i][0]%mod)%mod;
    cout << ans << '\n';
}