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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll n, a, b;
    ll mod;
    cin >> n >> a >> b;
    ll na = a/__gcd(a, b+1);
    
    if(na > (ll(1e18+5))/b+1)
        mod = 1e18+5;
    else
        mod = min(b*na, ll(1e18+5));
 
    vector<pll> seg;
    for(ll i = 0; i < n; ++i){
        pll tmp;
        cin >> tmp.ff >> tmp.ss;
        if(tmp.ss - tmp.ff + 1 >= mod){
            cout << mod << '\n';
            return 0;
        }
        tmp.ff %= mod;
        tmp.ss %= mod;
        //cout << i << ' ' << tmp.ff << ' ' << tmp.ss << '\n';
        if(tmp.ss >= tmp.ff)
            seg.pb({tmp.ff, tmp.ss});
        else{
            seg.pb({tmp.ff, mod-1});
            seg.pb({0, tmp.ss});
        }
    }
    //for(auto u : seg)
    //    cout << u.ff << ' ' << u.ss << '\n';
    sort(seg.begin(), seg.end());
    vector<pll> v;
    for(auto u : seg){
        //cout << u.ff << ' ' << u.ss << '\n';
        if(!v.empty() && v.back().ss >= u.ff)
            v.back().ss = max(v.back().ss, u.ss);
        else
            v.pb(u);
    }
    ll ans = 0;
    for(auto u : v){
        ans += u.ss-u.ff+1;
        //cout << u.ff << ' ' << u.ss << '\n';
    }
    cout << ans << '\n';
}
