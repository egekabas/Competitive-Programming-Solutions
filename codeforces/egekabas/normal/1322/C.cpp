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
const ll mod = 1e9+7;
const ll p = 7;
ll pw[500009];
ll val[500009];
vector<ll> g[500009];
map<ll, ll> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    pw[0] = 1;
    for(ll i = 1; i <= 500000; ++i)
        pw[i] = pw[i-1]*p%mod;

    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i){
            g[i].clear();
            cin >> val[i];    
        }
        mpp.clear();
        while(m--){
            ll x, y;
            cin >> x >> y;
            g[y].pb(x);
        }
        for(ll i = 1; i <= n; ++i){
            if(g[i].empty()) continue;
            ll hsh = 0;
            for(auto u : g[i])
                hsh = (hsh+pw[u])%mod;
            mpp[hsh] += val[i];
        }
        ll ret = 0;
        for(auto u : mpp)
            ret = __gcd(ret, u.ss);
        cout << ret << '\n';
    }
}