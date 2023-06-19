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
vector<ll> g[100009];
ll n, k;
ll dis[50009][509];
ll ans = 0;
void dfs(ll v, ll prt){
    dis[v][0] = 1;
    for(auto u : g[v]){
        if(u == prt) continue;
        dfs(u, v);

        for(ll i = 0; i < k; ++i){
            ans += dis[u][i]*dis[v][k-i-1];
        }

        for(ll i = 0; i < k; ++i)
            dis[v][i+1] += dis[u][i];
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, 0);
    cout << ans << '\n';
}