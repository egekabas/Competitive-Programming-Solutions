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
const ll mod = 998244353;
ll n;

ll dp[5009][2*5009], tmp[5009];
ll sum[3*5009];
ll add = -5005;


ll fact[5009];
ll exp(ll x, ll y= mod-2){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}

void calc(){
    add = -5005;

    cin >> n;

    map<ll, ll> mpp;
    for(ll i = 0; i < n; ++i){
        ll x;
        cin >> x;
        mpp[x]++;
    }

    vector<ll> vec;
    for(auto u : mpp)
        vec.pb(u.ss);

    ll pre = 0;
    for(auto u : vec){
    
        for(ll j = 1; j <= n; ++j){
            dp[j-1][(u-1)-(add+u)] += u*sum[j-add]%mod;
            dp[j-1][(u-1)-(add+u)] %= mod;

            tmp[j-1] = u*sum[j-add]%mod;
        }

        add += u;

        for(ll j = 0; j < n; ++j){
            sum[j+(u-1)-add] += j*tmp[j]%mod;
            sum[j+(u-1)-add] %= mod;
        }

        if(pre > 0){///////////////////change this
            dp[pre-1][(u-1)-add] += u*pre%mod;
            dp[pre-1][(u-1)-add] %= mod;

            sum[(pre-1)+(u-1)-add] += (pre-1)*u*pre%mod;
            sum[(pre-1)+(u-1)-add] %= mod;
        }
        pre += u;

    }
    ll ans = dp[0][0-add];
    for(auto u : vec)
        ans = ans*fact[u]%mod;
    cout << ans << '\n';

    for(ll i = 0; i <= n; ++i)
        for(ll j = 0-add; j <= n+5005; ++j)
            dp[i][j] = 0;
    for(ll j = 0-add; j <= 2*n+5005; ++j)
        sum[j] = 0;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fact[0] = 1;
    for(ll i = 1; i <= 5000; ++i)
        fact[i] = fact[i-1]*i%mod;
    for(ll i = 1; i <= 5000; ++i)
        fact[i] = exp(fact[i]);

    ll t;
    cin >> t;


    while(t--)
        calc();
}