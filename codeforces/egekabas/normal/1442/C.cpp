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
const ll inf = 1e18+9;
const ll mod = 998244353;
const ll mval = 35;
ll n, m;
vector<ll> g[200009][2];
ll dis[200009][mval+5];
ll pw(ll x, ll y){
    x %= mod;
    ll ret = 1;
    while(y){
        if(y%2)
            ret = ret*x%mod;
        y /= 2;
        x = x*x%mod;
    }
    return ret;
}
void bfs(){
    queue<pll> q;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 0; j <= mval; ++j)
            dis[i][j] = inf;
    dis[1][0] = 0;
    q.push({1, 0});
    while(q.size()){
        ll v = q.front().ff;
        ll lev = q.front().ss;
        q.pop();
        if(lev == mval) continue;
        for(auto u : g[v][lev%2])
            if(dis[u][lev] == inf){
                dis[u][lev] = dis[v][lev]+1;
                q.push({u, lev});
            }
        for(auto u : g[v][(lev+1)%2])
            if(dis[u][lev+1] == inf){
                dis[u][lev+1] = dis[v][lev]+1;
                q.push({u, lev+1});
            }
    }
}
pll d[200009][2];
void dijkstra(){
    priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, greater<pair<pll, ll>>> pq;
    for(ll i = 1; i <= n; ++i)
        d[i][0] = d[i][1] = {inf, inf};
    for(ll i = 1; i <= n; ++i)
        if(dis[i][mval] != inf){
            d[i][mval%2] = {mval, dis[i][mval]};
            pq.push(mp(mp(mval, dis[i][mval]), i));
        }
    while(pq.size()){
        ll v = pq.top().ss;
        pll dis = pq.top().ff;
        pq.pop();
        if(d[v][dis.ff%2] < dis)
            continue;
        if(d[v][(dis.ff+1)%2] > mp(dis.ff+1, dis.ss)){
            d[v][(dis.ff+1)%2] = mp(dis.ff+1, dis.ss);
            pq.push({mp(dis.ff+1, dis.ss), v});
        }
        for(auto u : g[v][dis.ff%2])
            if(d[u][dis.ff%2] > mp(dis.ff, dis.ss+1)){
                d[u][dis.ff%2] = mp(dis.ff, dis.ss+1);
                pq.push({mp(dis.ff, dis.ss+1), u});
            }
    }
    pll ans = min(d[n][0], d[n][1]);
    cout << (pw(2, ans.ff)-1+ans.ss)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    while(m--){
        ll x, y;
        cin >> x >> y;
        g[x][0].pb(y);
        g[y][1].pb(x);
    }
    bfs();
    ll ans = inf;
    for(ll i = 0; i <= mval; ++i)
        ans = min(ans, dis[n][i]+(1LL<<i)-1);
    if(ans != inf){
        ans %= mod;
        cout << ans;
    }
    else
        dijkstra();
}