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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n, k;
ll p[100009];
vector<ll> g[100009];
ll dpup[100009][109];
ll dpdown[100009][109][2];
ll ans;
void dfs(ll v, ll prt){
    ll neig = 0;
    for(auto u : g[v]){
        neig += p[u];
        if(u != prt){
            dfs(u, v);
            for(ll i = 0; i <= k; ++i)
                dpdown[u][i][1] -= p[v];
        }
    }
 
 
    dpup[v][1] = neig;
    dpdown[v][1][1] = neig;
    for(auto u : g[v])
        if(u != prt){
            for(ll i = 0; i <= k; ++i){
                ans = max(ans, dpup[v][k-i]+dpdown[u][i][0]);
                ans = max(ans, dpup[v][k-i]+dpdown[u][i][1]);
            
                ans = max(ans, dpdown[v][k-i][0]+dpup[u][i]);
                ans = max(ans, dpdown[v][k-i][1]+dpup[u][i]-p[u]);
            }
            
            for(ll i = 0; i <= k; ++i){
                dpup[v][i] = max(dpup[v][i], dpup[u][i]);
                if(i){
                    dpup[v][i] = max(dpup[v][i], dpup[u][i-1]+neig-p[u]);
                    dpup[v][i] = max(dpup[v][i], dpup[v][i-1]);
                }
            }
            for(ll i = 0; i <= k; ++i){
                dpdown[v][i][0] = max({dpdown[v][i][0], dpdown[u][i][0], dpdown[u][i][1]});
                if(i){
                    dpdown[v][i][0] = max(dpdown[v][i][0], dpdown[v][i-1][0]);
                    dpdown[v][i][1] = max({dpdown[v][i][1], dpdown[v][i-1][1], dpdown[u][i-1][0]+neig, dpdown[u][i-1][1]+neig});
                }
            }
        }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i)
        cin >> p[i];
    for(ll i = 1; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0);
    cout << ans << '\n';   
}
