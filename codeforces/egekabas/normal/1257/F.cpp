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
ll a[109];
ll c[109];
ll b[109];
ll n, p;
map<ll, ll> dp;
map<ll, ll> use;
ll bitcnt(ll x){
    ll ret = 0;
    while(x > 0){
        ret += x%2;
        x /= 2;
    }
    return ret;
}
ll hashf(vector<ll> v){
    ll ret = 0;
    ll mult = 1;
    ll mod = 1e16+7;
    for(auto u : v){
        ret += (u+1)*mult%mod;
        ret %= mod;
        mult = mult*p%mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    srand(time(NULL));
    p = rand()%100+31;
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i]/(1<<15);
        c[i] = a[i]-b[i]*(1<<15);
    }
    ll ans = -1;
    for(ll x = 0; x < (1<<15); ++x){
        vector<ll> v;
        ll mini = 1e18;
        for(ll i = 0; i < n; ++i){
            v.pb(bitcnt(b[i]^x));
            mini = min(mini, bitcnt(b[i]^x));
        }
        for(int i = 0; i < n; ++i)
            v[i] -= mini;
        dp[hashf(v)] = x*(1<<15);
        use[hashf(v)] = 1;
    }
    for(ll x = 0; x < (1<<15); ++x){
        vector<ll> v;
        ll maxi = -1e18;
        for(ll i = 0; i < n; ++i){
            v.pb(bitcnt(c[i]^x));
            maxi = max(maxi, bitcnt(c[i]^x));
        }
        for(int i = 0; i < n; ++i)
            v[i] = maxi-v[i];
        maxi = 0;
        for(int i = 0; i < n; ++i){
            maxi = max(maxi, v[i]);
        }
        
        ll curhash = hashf(v);
        if(use[curhash] == 1){
            ans = dp[curhash]+x;
        }
    }
    cout << ans << "\n";

}