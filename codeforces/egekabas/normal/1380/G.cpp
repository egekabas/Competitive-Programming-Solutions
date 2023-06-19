#include <bits/stdc++.h>
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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
const ll mod = 998244353;
ll pw(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
ll n;
ll a[300009];
ll pre[300009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll invn = pw(n, mod-2);
    sort(a, a+n);
    pre[0] = a[0];
    for(ll i = 1; i < n; ++i)
        pre[i] = (a[i]+pre[i-1])%mod;
    for(ll k = 1; k <= n; ++k){
        ll ans = 0;
        ll idx = n-1-k;
        while(idx >= 0){
            ans += pre[idx];
            ans %= mod;
            idx -= k;
        }
        cout << ans*invn%mod << ' ';
    }
}