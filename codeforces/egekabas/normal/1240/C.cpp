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
vector<pll> g[500009];
ll n, k;
ll dpone[500009];
ll dptwo[500009];
void dfs(ll v, ll p){
    ll ret = 0;
    vector<ll> vec;
    for(auto u : g[v]){
        if(u.ff == p)
            continue;
        dfs(u.ff, v);
        ret += max(dpone[u.ff], dptwo[u.ff]);
        vec.pb(dpone[u.ff]+u.ss-dptwo[u.ff]);
    }
    sort(vec.begin(), vec.end(), greater<long long>());
    dpone[v] = dptwo[v] = ret;
    for(ll i = 0; i < min((ll)vec.size(), k-1); ++i)
        if(vec[i] > 0)
            dpone[v] += vec[i];
    for(ll i = 0; i < min((ll)vec.size(), k); ++i)
        if(vec[i] > 0)
            dptwo[v] += vec[i];
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll q;
    cin >> q;
    while(q--){
        cin >> n >> k;
        for(ll i = 1; i <= n; ++i)
            g[i].clear();
        for(ll i = 0; i < n-1; ++i){
            ll t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g[t1].pb({t2, t3});
            g[t2].pb({t1, t3});
            
        }
        dfs(1, -1);
        cout << max(dpone[1], dptwo[1]) << "\n";
    }
}