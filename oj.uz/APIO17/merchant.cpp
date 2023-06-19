#include <bits/stdc++.h>
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
const ll inf = 1e18+9;
ll b[109][1009];
ll s[109][1009];
ll dis[109][109];
pii edge[109][109];
pii dp[109][109][109];
ll n, m, k;
ll check(ll val){
    vector<pair<ld, pll>> edges;
    vector<ld> dis(n+1);
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j){
            if(edge[i][j].ff < 0)
                continue;
            ld len = val*edge[i][j].ss-edge[i][j].ff-0.00000001;
            edges.pb({len, {i, j}});
        }
    ll x = -1;
    for(ll i = 0; i < n; ++i){
        x = -1;
        for(auto u : edges){
            ll v1 = u.ss.ff;
            ll v2 = u.ss.ss;
            ld d = u.ff;
            if(dis[v1] + d < dis[v2]){
                dis[v2] = dis[v1] + d;
                x = v2;
            }
        }
    }
    return (x != -1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 0; j < k; ++j)
            cin >> b[i][j] >> s[i][j];
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            if(i != j)
                dis[i][j] = inf;
    while(m--){
        ll x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = min(dis[x][y], z);
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            for(ll z = 1; z <= n; ++z)
                dis[j][z] = min(dis[j][z], dis[j][i] + dis[i][z]);
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j){
            if(i == j || dis[i][j] == inf){
                edge[i][j] = {-1, -1};
                continue;
            }
            edge[i][j].ss = dis[i][j];
            for(ll z = 0; z < k; ++z)
                if(b[i][z] != -1 && s[j][z] != -1)
                    edge[i][j].ff = max(edge[i][j].ff, s[j][z]-b[i][z]);
        }
    ll l = 0, r = 1e9;
    while(l < r){
        ll m = (l+r+1)/2;
        if(check(m))
            l = m;
        else
            r = m-1;
    }
    cout << l << '\n';
    
}
