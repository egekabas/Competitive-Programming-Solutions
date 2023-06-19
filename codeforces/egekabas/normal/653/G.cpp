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
ll binpow(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
ll fact[300009];
ll factinv[300009];
ll comb(ll x, ll y){
    return fact[x]*factinv[y]%mod*factinv[x-y]%mod;
}
    
ll n;
ll a[300009];
vector<int> cnt[300009];
ll pre[300009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    
    cin >> n;
    
    fact[0] = factinv[0] = 1;
    for(ll i = 1; i <= 300000; ++i){
        fact[i] = i*fact[i-1]%mod;
        factinv[i] = binpow(fact[i], mod-2);
    }   
    pre[0] = (1-binpow(2, n-1))%mod;
    //cout << pre[0] << '\n';
    for(ll i = 1; i < n; ++i){
        pre[i] = (pre[i-1]+comb(n, i))%mod;
        //cout << pre[i] << '\n';
    }
    
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        ll tmp = a[i];
        for(ll j = 2; j*j <= tmp; ++j){
            if(tmp%j)
                continue;    
            ll cur = 0;
            while(tmp%j == 0){
                ++cur;
                tmp /= j;
            }
            cnt[j].pb(cur);
        }
        if(tmp > 1)
            cnt[tmp].pb(1);
    }
    ll ans = 0;
    for(int u = 0; u <= 300000; ++u){
        if(cnt[u].size() == 0)
            continue;
        sort(cnt[u].begin(), cnt[u].end());
        int add = n-cnt[u].size();
        for(int i = 0; i < cnt[u].size(); ++i){
            //cout << cnt[u][i] << ' ';
            ans = (ans+pre[i+add]*cnt[u][i]%mod)%mod;
            if(ans < 0)
                ans += mod;
        }
    }
    cout << ans << '\n';
}