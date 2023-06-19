#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ll mod = 1e9+7;
const ll bitsz = 63;

ll exp(ll x, ll y = mod-2){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}

ll fact[1009];
ll invfact[1009];
ll comb(ll x, ll y){
    if(y > x) return 0;
    return fact[x]*invfact[y]%mod*invfact[x-y]%mod;
}

ll n, l, r, z;

ll dp[bitsz+2][2][2][2009];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> l >> r >> z;

    l *= 2;
    r *= 2;
    z *= 2;

    fact[0] = invfact[0] = 1;
    for(ll i = 1; i <= n; ++i){
        fact[i] = fact[i-1]*i%mod;
        invfact[i] = exp(fact[i]);
    }

    dp[bitsz][0][0][0] = 1;


    for(ll i = bitsz; i >= 1; --i){
        ll lbit = (l&(1LL<<i)) > 0;
        ll rbit = (r&(1LL<<i)) > 0;
        ll zbit = (z&(1LL<<i)) > 0;
            for(ll bigl = 0; bigl < 2; ++bigl)
                for(ll smallr = 0; smallr < 2; ++smallr)
                    for(ll need = 0; need <= 2*n; ++need){
                        
                        ll curval = dp[i][bigl][smallr][need];

                        //if(curval)
                        //    cout << (1LL<<(i-1)) << ' ' << bigl << ' ' << smallr << ' ' << need << ' ' << curval << '\n';
                        
                        for(ll curuse = zbit; curuse <= need; curuse += 2)
                            if((need-curuse)*2 <= 2*n){
                                
                                if(bigl || lbit == 0){
                                    dp[i-1][bigl][rbit ? 1 : smallr][(need-curuse)*2] += curval*comb(n, curuse)%mod;
                                    dp[i-1][bigl][rbit ? 1 : smallr][(need-curuse)*2] %= mod;
                                }

                                if(smallr || rbit == 1)
                                    if((need-curuse+1)*2 <= 2*n){

                                        dp[i-1][!lbit ? 1 : bigl][smallr][(need-curuse+1)*2] += curval*comb(n, curuse)%mod;
                                        dp[i-1][!lbit ? 1 : bigl][smallr][(need-curuse+1)*2] %= mod;
                                    }
                            }

                        if(need+1 <= 2*n && (need+1)%2 == zbit)
                            if(smallr || rbit == 1){
                                dp[i-1][!lbit ? 1 : bigl][smallr][0] += curval*comb(n, need+1)%mod;
                                dp[i-1][!lbit ? 1 : bigl][smallr][0] %= mod;
                            }
                    }
    }

    ll ans = 0;
    for(ll i = 0; i < 2; ++i)
        for(ll j = 0; j < 2; ++j)
            ans = (ans+dp[0][i][j][0])%mod;
    
    cout << ans << '\n';
}