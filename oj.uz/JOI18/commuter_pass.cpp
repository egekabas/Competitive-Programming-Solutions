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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
const ll inf = 1e18 + 7;
ll n, m;
ll s, t;
ll u, v;
vector<pll> g[100009];
vector<ll> tree[100009];
ll diss[100009];
ll dist[100009];
ll disu[100009];
ll disv[100009];
ll ans;
void dijk(ll beg, ll dis[]){
    for(ll i = 1; i <= n; ++i){
        dis[i] = inf;
    }
    dis[beg] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dis[beg], beg});
    while(pq.size()){
        ll v = pq.top().ss;
        ll d = pq.top().ff;
        pq.pop();
        if(dis[v] < d) continue;
        for(auto u : g[v])
            if(d+u.ss < dis[u.ff]){
                dis[u.ff] = d+u.ss;
                pq.push({dis[u.ff], u.ff});
            }
    }
}
ll vis[100009];
void calctree(ll beg, ll dis[], ll um[], ll vm[], ll bm[], ll addtree){
    for(ll i = 1; i <= n; ++i){
        um[i] = vm[i] = bm[i] = inf;
        vis[i] = 0;
    }
    vis[beg] = 1;
    um[beg] = disu[beg];
    vm[beg] = disv[beg];
    bm[beg] = um[beg]+vm[beg];
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dis[beg], beg});
    while(pq.size()){
        ll v = pq.top().ss;
        pq.pop();
        for(auto u : g[v]){
            if(dis[v]+u.ss != dis[u.ff]) continue;
            um[u.ff] = min({disu[u.ff], um[v], um[u.ff]});
            vm[u.ff] = min({disv[u.ff], vm[v], vm[u.ff]});
            bm[u.ff] = min({disu[u.ff]+vm[u.ff],disv[u.ff]+um[u.ff],bm[v], bm[u.ff]});
            if(addtree)
                tree[u.ff].pb(v);
            if(vis[u.ff] == 0){
                vis[u.ff] = 1;
                pq.push({dis[u.ff], u.ff});
            }
        }
    }
}
ll um1[100009], vm1[100009], bm1[100009];
ll um2[100009], vm2[100009], bm2[100009];
ll clear[100009];
void dfs(ll v){
    clear[v] = 1;
    for(auto u : tree[v])
        if(!clear[u])
            dfs(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    cin >> s >> t;
    cin >> u >> v;
    while(m--){
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    ll empty[1];
    dijk(u, disu);
    dijk(v, disv);
    dijk(s, diss);
    calctree(s, diss, um1, vm1, bm1, 0);
    dijk(t, dist);
    calctree(t, dist, um2, vm2, bm2, 1);
    dfs(s);
    ans = disu[v];
    for(ll i = 1; i <= n; ++i){
        if(clear[i] == 0) continue;
        ans = min({ans, bm1[i], bm2[i], vm1[i]+um2[i], um1[i]+vm2[i]});
    }
    cout << ans;
}
