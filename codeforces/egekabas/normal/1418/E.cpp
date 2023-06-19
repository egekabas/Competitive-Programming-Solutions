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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
const ll mod = 998244353;
ll exp(ll x, ll y = mod-2){
    ll ret = 1;
    while(y){
        if(y%2)
            ret = ret*x%mod;
        y /= 2;
        x = x*x%mod;
    }
    return ret;
}
vector<ll> mons;
vector<ll> pre;
ll n, m;
ll fact[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    mons.resize(n);
    fact[0] = 1;
    for(ll i = 1; i <= n+5; ++i)
        fact[i] = i*fact[i-1]%mod;
    for(ll i = 0; i < n; ++i)
        cin >> mons[i];
    sort(all(mons));
    pre.resize(n, mons[0]%mod);
    for(ll i = 1; i < n; ++i)
        pre[i] = (mons[i]+pre[i-1])%mod;
    while(m--){
        ll a, b;
        cin >> a >> b;
        ll idx = lower_bound(all(mons), b)-mons.begin();
        ll num = n-idx;
        ll sum = pre[n-1];
        if(idx > 0)
            sum -= pre[idx-1];
        sum = (sum+mod)%mod;
        ll ans = sum*fact[num-1]%mod*max(num-a, 0LL)%mod*exp(fact[num])%mod;
        ans %= mod;
        ans += (pre[n-1]-sum+mod)%mod*fact[num]%mod*max(num+1-a, 0LL)%mod*exp(fact[num+1])%mod;
        ans %= mod;
        cout << ans%mod << '\n';
    }

}