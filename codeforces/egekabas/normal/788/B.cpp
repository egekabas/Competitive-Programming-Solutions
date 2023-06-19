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
int n, m;
vector<int> g[1000009];
int vis[1000009];
void dfs(int v){
    vis[v] = 1;
    for(auto u : g[v])
        if(vis[u] == 0)
            dfs(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        if(x != y)
            g[y].pb(x);
    }
    for(int i = 1; i <= n; ++i)
        if(g[i].size()){
            dfs(i);
            break;
        }
    for(int i = 1; i <= n; ++i)
        if(vis[i] == 0 && g[i].size()){
            cout << 0;
            return 0;
        }
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ll sz = g[i].size();
        ll self = 0;
        for(auto u : g[i])
            if(u == i)
                self = 1;
        sz -= self;
        ans += sz*(sz-1)/2;
        if(self){
            --m;
            ans += m;
        }
    }
    cout << ans << '\n';
}