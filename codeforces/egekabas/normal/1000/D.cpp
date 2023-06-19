#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n;
ll mod = 998244353;
ll a[1009];
ll dp[1009];
ll c[1009][1009];

int f(int ind){
    if(dp[ind] != -1) return dp[ind];
    if(a[ind] <= 0 || ind >= n) return dp[ind] = 0;
    ll sum = 0;
    for(int i = ind+a[ind]+1 ; i <= n; ++i){
        sum = (sum+(f(i))*c[i-ind-1][a[ind]]%mod)%mod;
    }
    if(ind + a[ind] < n)
        sum = (sum+c[n-ind-1][a[ind]])%mod;
    
    return dp[ind] = sum;
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[i] = -1;
    }
    
    for(ll i = 0; i <= 1000; ++i)
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
        }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans = (ans+f(i))%mod;
        //cout << i << " " << f(i) << endl;
    }
    cout << ans << endl;
}