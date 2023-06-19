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
ll mod = 1000000007;
ll pw(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
ll pwlim(ll x, ll y){
    ll ret = 1;
    while(y > 0 && ret < ll(1e7)){
        if(y%2)
            ret = min(ret*x, ll(1e7));
        x = min(x*x, ll(1e7));
        y /= 2;
    }
    return ret;
}
ll n, p;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> p;
        map<ll, ll> mpp;
        for(ll i = 0; i < n; ++i){
            ll tmp;
            cin >> tmp;
            ++mpp[tmp];
        }
        if(p == 1){
            cout << n%2 << '\n';
            continue;
        }
        vector<pll> v;
        for(auto u : mpp)
            v.pb(u);
        reverse(v.begin(), v.end());
        ll ans = 0;
        ll dif = 0;
        for(ll i = 0; i < v.size(); ++i){
            ll cnt = v[i].ss;
            ll erase = min(dif, cnt);
            ans = (ans - erase*pw(p, v[i].ff)%mod + mod)%mod;
            dif -= erase;
            cnt -= erase;
            if(cnt%2){
                ans = (ans + pw(p, v[i].ff)%mod)%mod;
                dif++;
            }
            if(i != ll(v.size())-1)
                dif = min(dif*pwlim(p, v[i].ff-v[i+1].ff),ll(1e7));
        }
        cout << ans << '\n';
    }
}