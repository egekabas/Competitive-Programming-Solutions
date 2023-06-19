#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ll inf = 1e18+7;
ll n, m, k, q;

vector<pii> g[300009];
ll dis[300009];
ll col[300009];

struct edge{
    ll x, y, w;
    bool operator<(edge& oth) const{
        return w < oth.w;
    }
};
vector<edge> ng;

vector<pll> qu[300009];
ll ans[300009];

ll prt[300009];
unordered_map<ll, ll> mpp[300009];
void init(){
    for(ll i = 1; i <= k; ++i){
        prt[i] = i;
        mpp[i][i] = 1;
    }
}
ll findprt(ll x){
    if(prt[x] == x) return x;
    return prt[x] = findprt(prt[x]);
}
void merge(ll x, ll y, ll val){
    x = findprt(x);
    y = findprt(y);
    if(x == y) return;

    if(mpp[x].size()+qu[x].size() > mpp[y].size()+qu[y].size())
        swap(x, y);

    prt[x] = y;
    //cout << x << ' ' << y << '\n';
    for(auto u : qu[x]){
        //cout << u.ff << '\n';
        if(mpp[y][u.ff])
            ans[u.ss] = val;
        else
            qu[y].pb(u);
    }
    for(auto u : mpp[x])
        if(u.ss)
            mpp[y][u.ff] = 1;
        
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> k >> q;

    while(m--){
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(ll i = 1; i <= k; ++i){
        col[i] = i;
        pq.push({0, i});
    }
    for(ll i = k+1; i <= n; ++i)
        dis[i] = inf;
    
    ll maxd = 0;
    while(pq.size()){
        ll d = pq.top().ff;
        ll v = pq.top().ss;
        pq.pop();

        if(dis[v] < d)
            continue;

        for(auto edge : g[v]){
            ll nd = d+edge.ss;
            ll u = edge.ff;

            if(dis[u] > nd){
                dis[u] = nd;
                col[u] = col[v];
                pq.push({nd, u});
            }
            if(col[u] && col[v] != col[u]){
                ng.pb({col[v], col[u], nd+dis[u]});
                maxd = max(maxd, nd+dis[u]);
            }
        }
    }

    for(ll i = 0; i < q; ++i){
        ll x, y;
        cin >> x >> y;
        qu[x].pb({y, i});
        qu[y].pb({x, i});
    }


    sort(all(ng));
    init();
    for(auto u : ng)
        merge(u.x, u.y, u.w);
    
    for(ll i = 0; i < q; ++i)
        cout << ans[i] << '\n';

    
}