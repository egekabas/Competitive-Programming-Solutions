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
ll n, m;
vector<pll> g[200009];
ll dis[200009][2][2];
priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll>>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    while(m--){
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    for(ll i = 1; i <= n; ++i)
        dis[i][0][0] = dis[i][0][1] = dis[i][1][0] = dis[i][1][1] = 1e18+9;
    
    dis[1][0][0] = 0;
    pq.push({{0, 0}, {0, 1}});
    while(pq.size()){
        ll t1 = pq.top().ff.ff;
        ll t2 = pq.top().ff.ss;
        ll d = pq.top().ss.ff;
        ll v = pq.top().ss.ss;
        pq.pop();
        if(d > dis[v][t1][t2])
            continue;
        for(auto it : g[v]){
            ll u = it.ff;
            ll road = it.ss;
            if(dis[u][t1][t2] > d+road){
                dis[u][t1][t2] = d+road;
                pq.push({{t1, t2}, {d+road, u}});
            }
            if(t1 == 0 && dis[u][1][t2] > d){
                dis[u][1][t2] = d;
                pq.push({{1, t2}, {d, u}});
            }
            if(t2 == 0 && dis[u][t1][1] > d+2*road){
                dis[u][t1][1] = d+2*road;
                pq.push({{t1, 1}, {d+2*road, u}});
            }
        }
    }
    for(ll i = 2; i <= n; ++i)
        cout << min(dis[i][0][0], dis[i][1][1]) << ' ';
}