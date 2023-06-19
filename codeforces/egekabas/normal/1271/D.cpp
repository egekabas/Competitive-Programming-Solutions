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
ll n, m, k;
ll a[5009], b[5009], c[5009];
ll inc[5009];
vector<ll> out[5009];
ll sfunc(ll x, ll y){
    return c[x] > c[y];
}
ll dp[5009][5009];
ll f(ll idx, ll army){
    if(idx == n+1)
        return 0;
    if(army < a[idx])
        return -1e18;
    if(dp[idx][army] != -1e18)
        return dp[idx][army];
    ll newarmy = army + b[idx];
    dp[idx][army] = f(idx+1, newarmy);
    ll tmp = 0;
    for(auto u : out[idx]){
        --newarmy;
        tmp += c[u];
        dp[idx][army] = max(dp[idx][army], tmp+f(idx+1, newarmy));
    }
    return dp[idx][army];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    while(m--){
        ll t1, t2;
        cin >> t1 >> t2;
        inc[t2] = max(inc[t2], t1);
    }
    for(ll i = 1; i <= n; ++i){
        if(inc[i] != 0)
            out[inc[i]].pb(i);
        else
            out[i].pb(i);
    }
    for(ll i = 1; i <= n; ++i){
        sort(out[i].begin(), out[i].end(), sfunc);
    }
    for(ll i = 0; i <= 5004; ++i)
        for(ll j = 0; j <= 5004; ++j)
            dp[i][j] = -1e18;
    
    cout << max((ll)-1, f(1, k)) << "\n";
}