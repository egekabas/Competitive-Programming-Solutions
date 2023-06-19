#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll mod = 1e9+7;
ll n, m, k;
ll key[500009];
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
map<ll, ll> dsu[500009];
ll findprt(ll x, ll val){
    if(dsu[x][val] == 0 || dsu[x][val] == x)
        return dsu[x][val] = x;
    return dsu[x][val] = findprt(dsu[x][val], val);
}
void merge(ll x, ll y, ll val){
    x = findprt(x, val);
    y = findprt(y, val);
    dsu[x][val] = y;
}
map<ll, ll> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    

    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i)
        cin >> key[i]; 
    while(m--){
        ll x, y;
        cin >> x >> y;
        ll val = key[x]^key[y];
        if(findprt(x, val) != findprt(y, val)){
            ++mpp[val];
            merge(x, y, val);
        }
    }
    ll tot = binpow(2, k);
    ll ans = 0;
    for(auto u : mpp){
        tot--;
        ans += binpow(2, n-u.ss);
        ans %= mod;
    }
    ans += tot*binpow(2, n)%mod;
    ans %= mod;
    cout << ans << '\n';
}