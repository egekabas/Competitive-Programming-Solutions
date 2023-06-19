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
ll n, q;
ll init[100009];
vector<ll> g[100009];
ll enter[100009];
ll finish[100009];
ll dad[100009][30];
ll depth[100009];
void dfs(ll v, ll prt){
    static ll cur = 0;
    enter[v] = cur++;
    dad[v][0] = prt;
    for(ll i = 1; i < 30; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v])
        if(u != prt){
            depth[u] = depth[v]+1;
            dfs(u, v);
        }
    finish[v] = cur-1;
}
ll lca(ll x, ll y){
    if(depth[y] > depth[x]) swap(x, y);
    for(ll i = 29; i >= 0; --i)
        if(depth[dad[x][i]] >= depth[y])
            x = dad[x][i];
    if(x == y)
        return x;
    for(ll i = 29; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}
ll lazy[400009];
ll seg[400009];
void push(ll v, ll tl, ll tm, ll tr){
    seg[2*v] += lazy[v]*(tm-tl+1);
    seg[2*v+1] += lazy[v]*(tr-tm);
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(r < tl || tr < l) return 0;
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        ll tm = (tl+tr)/2;
        push(v, tl, tm, tr);
        return get(2*v, tl, tm, l, r)+get(2*v+1, tm+1, tr, l, r);
    }
}
void upd(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(r < tl || tr < l) return;
    if(l <= tl && tr <= r){
        seg[v] += val*(tr-tl+1);
        lazy[v] += val;
    }
    else{
        ll tm = (tl+tr)/2;
        push(v, tl, tm, tr);
        upd(2*v, tl, tm, l, r, val);
        upd(2*v+1, tm+1, tr, l, r, val);
        seg[v] = seg[2*v]+seg[2*v+1];
    }
}
ll goupto(ll x, ll y){
    for(ll i = 29; i >= 0; --i)
        if(depth[dad[x][i]] > depth[y])
            x = dad[x][i];
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> init[i];
    for(int i = 1; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    depth[1] = 1;
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        upd(1, 0, n-1, enter[i], enter[i], init[i]);
    ll root = 1;
    while(q--){
        ll t;
        cin >> t;
        if(t == 1)
            cin >> root;
        else if(t == 2){
            ll u, v, x;
            cin >> u >> v >> x;
            ll vertex;
            if((lca(u, root) == root) != (lca(v, root) == root))
                vertex = root;
            else if(lca(lca(u, v), root) != lca(u, v))
                vertex = lca(u, v);
            else{
                if(depth[lca(u, root)] > depth[lca(v, root)])
                    vertex = lca(u, root);
                else
                    vertex = lca(v, root);
            }
            if(vertex == root)
                upd(1, 0, n-1, 0, n-1, x);
            else if(lca(vertex, root) != vertex)
                upd(1, 0, n-1, enter[vertex], finish[vertex], x);
            else{
                upd(1, 0, n-1, 0, n-1, x);
                upd(1, 0, n-1, enter[goupto(root, vertex)], finish[goupto(root, vertex)], -x);
            }
        }
        else{
            ll v;
            cin >> v;
            if(v == root)
                cout << seg[1] << '\n';
            else if(lca(v, root) != v)
                cout << get(1, 0, n-1, enter[v], finish[v]) << '\n';
            else
                cout << seg[1]-get(1, 0, n-1, enter[goupto(root, v)], finish[goupto(root, v)]) << '\n';
                
        }
    }
}