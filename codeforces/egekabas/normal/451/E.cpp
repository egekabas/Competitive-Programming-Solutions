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
ll mod = 1e9+7;
ll factinv[100];
ll binpow(ll x, ll y){
    ll ret = 1;
    x %= mod;
    while(y > 0){
        if(y%2 == 1)
            ret = ret*x%mod;
        y /= 2;
        x = x*x%mod;
    }
    return ret;
}
ll inv(ll x){
    return binpow(x, mod-2);
}
ll fact(ll x){
    if(factinv[x] != 0)
        return factinv[x];
    ll ret = 1;
    for(ll i = 1; i <= x; ++i)
        ret = ret*(i)%mod;
    return factinv[x] = inv(ret);
}
ll comb(ll x, ll y){
    ll ret = 1;
    for(ll i = x-y+1; i <= x; ++i)
        ret = ret*(i%mod)%mod;
    return ret*fact(y)%mod;
}
ll func(ll x, ll y){
    if(y < 0)
        return 0;
    return comb(x+y-1, x-1);
}
ll n, s;
ll a[30];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin >> n >> s;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    for(ll bit = 0; bit < (1<<n); ++bit){
        ll tmpbit = bit;
        ll tmps = s;
        ll cur = 0;
        ll bitcnt = 0;
        while(tmpbit > 0){
            if(tmpbit % 2 == 1){
                ++bitcnt;
                tmps -= a[cur]+1;
                if(tmps < 0)
                    tmps = -1;
            }
            ++cur;
            tmpbit /= 2;
            
        }
        if(bitcnt % 2 == 1)
            ans -= func(n, tmps);
        else
            ans += func(n, tmps);
        if(ans < 0)
            ans += mod;
        ans %= mod;
    }
    cout << ans << "\n";
}