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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
const ll mod = 998244353;
ll pw(ll x, ll y = mod-2){
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    n *= 2;
    vector<ll> v1, v2;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        if(i < n/2)
            v1.pb(a[i]);
        else
            v2.pb(a[i]);
    }
    sort(all(v1));
    sort(all(v2), greater<ll>());
    ll ans = 0;
    for(ll i = 0; i < n/2; ++i){
        ans = (ans+abs(v1[i]-v2[i]))%mod;
    }
    for(ll i = 1; i <= n; ++i)
        ans = ans*i%mod;

    ll rev = 1;
    for(ll i = 1; i <= n/2; ++i)
        rev = rev*i%mod;
    rev = pw(rev*rev%mod);

    ans = ans*rev%mod;
    cout << ans << '\n';
}