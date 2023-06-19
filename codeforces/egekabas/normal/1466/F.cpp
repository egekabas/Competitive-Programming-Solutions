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
ll prt[500009];
ll sz[500009];
ll all[500009];
ll findprt(ll x){
    if(prt[x] == x) return x;
    return prt[x] = findprt(prt[x]);
}
const ll mod = 1e9+7;
ll pw[500009];
ll n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    pw[0] = 1;
    for(ll i = 1; i <= m; ++i){
        prt[i] = i;
        sz[i] = 1;
        pw[i] = pw[i-1]*2%mod;
    }
    vector<ll> v;
    for(ll i = 1; i <= n; ++i){
        ll k;
        cin >> k;
        if(k == 1){
            ll x;
            cin >> x;
            x = findprt(x);
            if(all[x] == 0){
                v.pb(i);
                all[x] = 1;
            }
        }
        else{
            ll x, y;
            cin >> x >> y;
            x = findprt(x);
            y = findprt(y);
            if(x != y && (all[x] == 0 || all[y] == 0)){
                v.pb(i);
                sz[x] += sz[y];
                all[x] |= all[y];
                prt[y] = x;
            }
        }
    }
    ll ans = 1;
    for(ll i = 1; i <= m; ++i)
        if(prt[i] == i){
            ans = ans*pw[sz[i]-(!all[i])]%mod;
        }
    cout << ans << ' ' << v.size() << '\n';
    for(auto u : v)
        cout << u << ' ';
}