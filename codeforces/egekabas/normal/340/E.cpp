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
ll comb[2009][2009];
ll fact[2009];
ll n;
ll a[2009];
ll mark[2009];
ll us, fr;
ll mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i <= n; ++i)
        comb[i][0] = comb[i][i] = 1;
    for(ll i = 2; i <= n; ++i)
        for(ll j = 1; j < i; ++j)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;
    fact[0] = 1;
    for(ll i = 1; i <= n; ++i)
        fact[i] = (fact[i-1]*i)%mod;
    for(ll i = 0; i < n; ++i)
        if(a[i] != -1)
            mark[a[i]] = 1;
    for(ll i = 0; i < n; ++i)
        if(a[i] == -1){
            if(mark[i+1] == 1)
                ++us;
            else
                ++fr;
        }
    ll mult = 1;
    ll ans = 0;
    for(ll i = 0; i <= fr; ++i){
        ans += mult*comb[fr][i]*fact[us + fr-i]%mod;
        ans %= mod;
        if(mult == 1)
            mult = -1;
        else
            mult = 1;
    }
    if(ans < 0)
        ans += mod;
    cout << ans << "\n";
}