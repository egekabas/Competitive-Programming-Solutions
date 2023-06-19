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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n;
ll a[200009];
ll mod = 998244353;
ll inv(ll x){
    ll y = mod-2;
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
ll dp[200009];
ll func(ll x){
    if(dp[x] != 0)
        return dp[x];
    if(x == 0){
        return dp[x] = 100*inv(a[x])%mod; 
    }
    else{
        dp[x] = (func(x-1)+1)*100%mod*inv(a[x])%mod;
        return dp[x];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << func(n-1) << "\n";
}