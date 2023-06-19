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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll depth[10009];
vector<ll> g[10009];
ll subsz[10009];
ll dad[10009][35];
ll eul[10009];
ll chain[10009];
ll n;
void dfs1(ll v, ll prt){
    dad[v][0] = prt;
    for(ll i = 1; i < 30; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    subsz[v] = 1;
    for(auto u : g[v]){
        if(u == prt)
            continue;
        depth[u] = depth[v] + 1;
        dfs1(u, v);
        subsz[v] += subsz[u];
    }
}
ll tim = 0;
void dfs2(ll v, ll prt){
    eul[v] = tim++;
    if(prt != -1 && eul[prt] == eul[v]-1)
        chain[v] = chain[prt];
    else
        chain[v] = v;
    ll heavy = -1;
    ll id = -1;
    for(auto u : g[v]){
        if(u == prt)
            continue;
        if(subsz[u] >= heavy)
            id = u;
        heavy = max(heavy, subsz[u]);
    }
    if(id != -1)
        dfs2(id, v);
    for(auto u : g[v]){
        if(u == prt || u == id)
            continue;
        dfs2(u, v);
    }
}
ll goup(ll x, ll num){
    for(ll i = 29; i >= 0; --i)
        if((1<<i) <= num){
            num -= (1<<i);
            x = dad[x][i];
        }
    return x;
}
pll lca(ll x, ll y){
    if(x == y)
        return {-1, -1};
    if(depth[x] > depth[y]){
        x = goup(x, depth[x]-depth[y]-1);
        if(dad[x][0] == y)
            return {x, -1};
        x = dad[x][0];
    }
    else if(depth[y] > depth[x]){
        y = goup(y, depth[y]-depth[x]-1);
        if(dad[y][0] == x)
            return {-1, y};
        y = dad[y][0];
    }
    for(ll i = 29; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return {x, y};
}
ll seg[40009];
void upd(ll v, ll tl, ll tr, ll id, ll val){
    if(id > tr || tl > id)
        return;
    else if(tl == id && tr == id)
        seg[v] = val;
    else{
        ll tm = (tl+tr)/2;
        upd(2*v, tl, tm, id, val);
        upd(2*v+1, tm+1, tr, id, val);
        seg[v] = max(seg[2*v], seg[2*v+1]);
    }
}
ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || r < tl)
        return -1e9;
    else if(l <= tl && tr <= r)
        return seg[v];
    else{
        ll tm = (tl+tr)/2;
        return max(get(2*v, tl, tm, l, r),
        get(2*v+1, tm+1, tr, l, r));
    }
}
ll goprt(ll x, ll y){
    if(y == -1)
        return 0;
    ll ret = -1e9;
    while(depth[x] >= depth[y]){ 
        if(depth[chain[x]] > depth[y]){
            ret = max(ret, get(1, 0, n-1, eul[chain[x]], eul[x]));
            x = dad[chain[x]][0];
        }
        else{
            ret = max(ret, get(1, 0, n-1, eul[y], eul[x]));
            break;
        }
    }
    return ret;
}
ll query(ll x, ll y){
    if(x == y) return 0;
    pll tmp = lca(x, y);
    return max(goprt(x, tmp.ff), goprt(y, tmp.ss));
}
ll edge[10009];
char c[100];    
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    //freopen("out.txt", "w", stdout);
    //freopen("in.txt", "r", stdin);

    ll t;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(ll i = 0; i <= n; ++i){
            g[i].clear();
        }
        for(ll i = 0; i <= 4*n; ++i)
            seg[i] = -1e9;
        
        memset(depth, sizeof(depth), 0);
        memset(subsz, sizeof(subsz), 0);
        memset(dad, sizeof(dad), 0);
        memset(eul, sizeof(eul), 0);
        memset(chain, sizeof(chain), 0);
        memset(c, sizeof(c), 0);
        memset(edge, sizeof(edge), 0);

        tim = 0;
        vector<pair<pll, ll>> edges(n-1);
        for(ll i = 0; i < n-1; ++i){
            scanf("%lld %lld %lld", &edges[i].ff.ff, &edges[i].ff.ss, &edges[i].ss);
            g[edges[i].ff.ff].pb(edges[i].ff.ss);
            g[edges[i].ff.ss].pb(edges[i].ff.ff);
        }
        dfs1(1, -1);
        dfs2(1, -1);
        for(ll i = 0; i < n-1; ++i){
            ll x;
            if(depth[edges[i].ff.ff] > depth[edges[i].ff.ss])
                x = edges[i].ff.ff;
            else
                x = edges[i].ff.ss;
            edge[i+1] = x;
            upd(1, 0, n-1, eul[x], edges[i].ss);
        }
        while(1){
            scanf("%s", c);
            if(c[0] == 'D')
                break;
            ll x, y;
            scanf("%lld %lld", &x, &y);
            if(c[0] == 'Q')
                printf("%lld\n", query(x, y));
            else{
                upd(1, 0, n-1, eul[edge[x]], y);
            }
        }
    }
    return 0;
