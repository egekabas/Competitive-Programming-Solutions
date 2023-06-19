#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n, m, s;
ll score[200009];
map<pll, ll> mpp;
vector<ll> g[200009];
ll curtime = 1;
ll tim[200009];
ll low[200009];

ll col[200009];
ll vis[200009];

ll cur = 1;
ll cnt = 0;

ll cyclic[200009];
ll sub[200009];
ll subcyclic[200009];

ll newscore[200009];
vector<ll> newg[200009];
ll sgroup;

void bridge(ll v, ll p){
    vis[v] = 1;
    low[v] = tim[v] = curtime++;
    for(auto u : g[v]){
        if(u == p)
            continue;
        if(vis[u])
            low[v] = min(low[v], tim[u]);
        else{
            bridge(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] > tim[v])
                mpp[{u, v}] = mpp[{v, u}] = 1;
        }
    }
}
ll findunion(ll v){
    ++cnt;
    col[v] = cur;
    if(v == s)
        sgroup = cur;
    vis[v] = 1;
    ll ret = score[v];
    for(auto u : g[v]){
        if(vis[u] == 1 || mpp[{u, v}] == 1)
            continue;
        ret += findunion(u);
    }
    return ret;
}
void findedge(ll v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[u] == 1)
            continue;
        if(col[v] != col[u]){
            newg[col[v]].push_back(col[u]);
            newg[col[u]].push_back(col[v]);
        }
        findedge(u);
    }
}
void dp(ll v){
    vis[v] = 1;
    ll fir = 0;
    for(auto u : newg[v]){
        if(vis[u])
            continue;
        dp(u);
        if(cyclic[u] == 1)
            cyclic[v] = 1;
        sub[v] += subcyclic[u];
        subcyclic[v] += subcyclic[u];
        fir = max(fir, sub[u]-subcyclic[u]);
    }
    if(cyclic[v] == 1)
        subcyclic[v] += newscore[v];
    sub[v] += newscore[v]+fir;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        cin >> score[i];
    for(ll i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> s;
    bridge(1, -1);

    for(ll i = 1; i <= n; ++i)
        vis[i] = 0;
    for(ll i = 1; i <= n; ++i){
        if(vis[i] == 1)
            continue;
        cnt = 0;
        newscore[cur] = findunion(i);
        if(cnt > 1){
            cyclic[cur] = 1;
        }
        ++cur;
    }
    //cout << cur-1 << "\n";
    for(ll i = 1; i <= n; ++i)
        vis[i] = 0;
    findedge(1);

    for(ll i = 1; i <= n; ++i)
        vis[i] = 0;
    dp(sgroup);
    cout << sub[sgroup] << "\n";
}