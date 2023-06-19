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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
ll n, mod;
ll dp[(int)4e6+9];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> mod;
    dp[n] = 1;
    for(ll i = n-1; i >= 1; --i){
        dp[i] = dp[i+1];
        for(ll j = 2;; ++j){
            if(i*j > n) break;
            dp[i] = (dp[i]+dp[i*j])%mod;
            if(i*j+j <= n)
                dp[i] = (dp[i]-dp[i*j+j]+mod)%mod;
        }
        if(i == 1)
            break;
        dp[i] = (dp[i]+dp[i+1])%mod;
    }
    cout << dp[1];
}