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
ll n, m;
ll mod = 1e9+7;
ll fact[100009];
ll facinvdp[100009];

ll factinverse(ll a){
    if(facinvdp[a] != 0)
        return facinvdp[a];
    ll x = fact[a];
    ll y = mod-2;
    ll ret = 1;
    while(y > 0){
        if(y % 2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return facinvdp[a] = ret;
}
ll comb(ll x, ll y){
    return fact[x]*factinverse(y)%mod*factinverse(x-y)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fact[0] = 1;
    for(ll i = 1; i <= 100000; ++i)
        fact[i] = i*fact[i-1]%mod;
    cin >> n >> m;
    ll ans = 2;
    ll two, one;
    for(two = 1; two*2 <= n; ++two){
        one = n-2*two;
        ans += 2*comb(one+two, two);
        ans %= mod;
    }
    for(two = 1; two*2 <= m; ++two){
        one = m-2*two;
        ans += 2*comb(one+two, two);
        ans %= mod;
    }
    cout << ans << "\n";
}