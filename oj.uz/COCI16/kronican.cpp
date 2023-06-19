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
ll val[25][25];
ll n, k;
ll dp[(1<<21)];
ll bitcnt(ll x){
    ll ret = 0;
    while(x > 0){
        ret += x%2;
        x /= 2;
    }
    return ret;
}
ll f(ll bit){
    if(dp[bit] != -1)
        return dp[bit];
    if(bitcnt(bit) <= k)
        return dp[bit] = 0;
    
    dp[bit] = 1e9;
    vector<int> v;
    for(int i = 0; i < n; ++i)
        if((bit&(1<<i)) > 0)
            v.pb(i);
    for(int i = 0; i < v.size(); ++i){
        ll mini = 1e9;
        for(int j = 0; j < v.size(); ++j){
            if(i == j) continue;
            mini = min(mini, val[v[i]][v[j]]);
        }
        dp[bit] = min(dp[bit], f(bit-(1<<v[i])) + mini);
    }
    return dp[bit];
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < n; ++j){
            cin >> val[i][j];
        }
    for(ll i = 0; i < (1<<n); ++i)
        dp[i] = -1;    
    cout << f((1<<n)-1) << "\n";
}
