#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
const ll inf = 1e18;
struct edge{
    ll x, y, z, d, id;
};
struct simple{
    ll x, y, id;
};
ll n, m;
edge e[50009];
vector<simple> out[209];
void dijkstra1(ll beg, ll used[], vector<simple> g[], ll end){
    for(ll i = 0; i < m; ++i)
        used[i] = 0;
    vector<pll> prt(n+5);
    vector<ll> dis(n+5, inf);
    dis[beg] = 0;
    priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll>>> pq;
    pq.push({{0, beg}, {-1, -1}});
    while(!pq.empty()){
        ll d = pq.top().ff.ff;
        ll v = pq.top().ff.ss;
        ll comeid = pq.top().ss.ff;
        ll comev = pq.top().ss.ss;
        pq.pop();
        if(dis[v] < d) continue;
        if(comeid != -1)
            prt[v] = {comeid, comev};
        for(auto u : g[v]){
            if(dis[u.x] > u.y + d){
                dis[u.x] = u.y + d;
                pq.push({{dis[u.x], u.x}, {u.id , v}});
            }
        }
    }
    if(dis[end] >= inf) return;
    ll cur = end;
    while(cur != beg){
        used[prt[cur].ff] = 1;
        cur = prt[cur].ss;
    }
}
ll dijkstra2(ll beg, ll dont, vector<simple> g[], ll end){
    
    vector<ll> dis(n+5, inf);
    dis[beg] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, beg});
    while(!pq.empty()){
        ll d = pq.top().ff;
        ll v = pq.top().ss;
        pq.pop();
        if(dis[v] < d) continue;
        for(auto u : g[v]){
            if(u.id == dont) continue;
            if(dis[u.x] > u.y + d){
                dis[u.x] = u.y + d;
                pq.push({dis[u.x], u.x});
            }
        }
    }
    return dis[end];
}
ll used[50009];
ll ans[50009];
ll dis[209][209];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    //freopen("in.txt", "r", stdin);                                                                                             
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            if(i != j)
                dis[i][j] = inf;
    for(ll i = 0; i < m; ++i){
        cin >> e[i].x >> e[i].y >> e[i].z >> e[i].d;
        e[i].id = i;
        out[e[i].x].pb({e[i].y, e[i].z, e[i].id});
        dis[e[i].x][e[i].y] = min(dis[e[i].x][e[i].y], e[i].z);
        ans[i] += e[i].d;
    }
    for(ll k = 1; k <= n; ++k)
        for(ll i = 1; i <= n; ++i)
            for(ll j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    
    ll fin = dijkstra2(1, -1, out, n)+dijkstra2(n, -1, out, 1);
 
    dijkstra1(1, used, out, n);
    for(ll i = 0;  i < m; ++i){
        if(used[i])
            ans[i] += dijkstra2(1, i, out, n);
        else
            ans[i] += min(dis[1][n], dis[1][e[i].y]+e[i].z+dis[e[i].x][n]);
    }
    dijkstra1(n, used, out, 1);
    for(ll i = 0;  i < m; ++i){
        if(used[i])
            ans[i] += dijkstra2(n, i, out, 1);
        else
            ans[i] += min(dis[n][1], dis[n][e[i].y]+e[i].z+dis[e[i].x][1]);
    }
 
    for(ll i = 0; i < m; ++i)
        fin = min(fin, ans[i]);
    if(fin >= inf)
        cout << -1;
    else
        cout << fin;
 
}
