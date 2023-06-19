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
ll fen[200000];
ll fac[200000];
ll n;
ll mod = 1000000007;
ll fact(ll x){
    if(x == 0 || x == 1) return 1;
    if(fac[x] != 0) return fac[x];
    return fac[x] = (x*fact(x-1))%mod; 
}
void update(ll idx, ll val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&(-idx);
    }
}
ll get(ll idx){
    ll ret = 0;
    while(idx > 0){
        ret += fen[idx];
        idx -= idx&(-idx);
    }
    return ret;
}
void cons(){
    for(ll i = 1; i <= n; ++i)
        fen[i] = 0;
    for(ll i = 1; i <= n; ++i)
        update(i, 1);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        cons();
        ll tmp;
        ll ans = 1;
        for(ll i = 0; i < n; ++i){
            cin >> tmp;
            ans += ((get(tmp)-1)*fact(n-i-1))%mod;
            ans %= mod;
            update(tmp, -1);
        }
        cout << ans << endl;
    }
