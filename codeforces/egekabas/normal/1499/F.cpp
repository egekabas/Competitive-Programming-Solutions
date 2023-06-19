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
ll n, k;
const ll mod = 998244353;

ll bit[5009];
ll get(ll idx){
    ll ret = 0;
    for(++idx; idx > 0; idx -= idx&(-idx)){
        ret += bit[idx];
        if(ret >= mod)
            ret -= mod;
    }
    return ret;
}
void upd(ll idx, ll val){
    for(++idx; idx <= n; idx += idx&(-idx)){
        bit[idx] += val;
        bit[idx] = (bit[idx]+mod)%mod;
    }
}

ll dp[5009][5009];
vector<ll> g[5009];
ll global[5009];
ll ngo[5009];
void dfs(ll v, ll prt){
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v);
    for(ll i = 0; i < n; ++i)
        global[i] = 1;
    for(auto u : g[v])
        if(u != prt){
            for(ll i = 0; i <= n; ++i)
                bit[i] = 0;
            for(ll i = 0; i < n; ++i){
                ll l = i+1;
                ll r = k-1-i;
                if(l <= r){
                    upd(l, dp[u][i]);
                    upd(r+1, -dp[u][i]);
                }
            }
            for(ll i = 0; i < n; ++i){
                ngo[i] = 0;
                if(k-1-i >= 0)
                    ngo[i] += global[min(i, k-1-i)]*dp[u][i]%mod;
                if(i == 0)
                    ngo[i] += global[0]*get(i)%mod;
                else
                    ngo[i] += (global[i]-global[i-1])*get(i)%mod;
                ngo[i] = (ngo[i]+mod)%mod;
            }
            for(ll i = 0; i < n; ++i)
                global[i] = ngo[i];
            for(ll i = 1; i < n; ++i){
                global[i] += global[i-1];
                if(global[i] >= mod)
                    global[i] -= mod;
            }
        }
    dp[v][0] = global[n-1];
    for(ll i = 1; i < n; ++i){
        if(i == 1)
            dp[v][i] = global[i-1];
        else
            dp[v][i] = (global[i-1]-global[i-2]+mod)%mod;
    }
    //cout << v << ' ' << dp[v][0] << ' ' << dp[v][1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    ++k;
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    cout << dp[1][0] << '\n';
}