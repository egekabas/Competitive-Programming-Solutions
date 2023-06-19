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
struct tree{
    vector<ll> seg;
    vector<ll> lazy;
    int maxn;
    void init(int n){
        maxn = n-1;
        seg.resize(4*n);
        lazy.resize(4*n);
    }
    void push(int v){
        seg[2*v] += lazy[v];
        seg[2*v+1] += lazy[v];
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
    void upd(int v, int tl, int tr, int l, int r, ll val){
        if(r < tl || tr < l)
            return;
        if(l <= tl && tr <= r){
            seg[v] += val;
            lazy[v] += val;
        }
        else{
            push(v);
            upd(2*v, tl, (tl+tr)/2, l, r, val);
            upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
            seg[v] = max(seg[2*v], seg[2*v+1]);
        }
    }
    ll get(int v, int tl, int tr, int l, int r){
        if(r < tl || tr < l)
            return -1e18;
        if(l <= tl && tr <= r){
            return seg[v];
        }
        else{
            push(v);
            return max(
            get(2*v, tl, (tl+tr)/2, l, r),
            get(2*v+1, (tl+tr)/2+1, tr, l, r));
        }
    }
};
struct edge{
    ll x, y, z;
};
vector<pii> g[100009];
edge e[100009];
    
int sz[100009];
int block[100009];
void findsz(int v, int prt){
    sz[v] = 1;
    for(auto u : g[v]){
        if(block[u.ff] || u.ff == prt) continue;
        findsz(u.ff, v);
        sz[v] += sz[u.ff];
    }
}
int findcentroid(int v, int prt, int totsz){
    for(auto u : g[v]){
        if(block[u.ff] || u.ff == prt) continue;
        if(sz[u.ff]*2 > totsz)
            return findcentroid(u.ff, v, totsz);
    }
    return v;
}
int curtime = 0;
int root;
vector<pii> tin[100009];
vector<int> tout[100009];
vector<int> change[100009];
vector<pii> entry[100009];
set<pair<ll, pll>, greater<pair<ll, pll>>> centmax[100009];
ll centans[100009];
tree seg[100009];
set<pll, greater<pll>> totmax;
void dfs(int v, int prt){
    int mytime = curtime++;
    tin[root].pb({v, mytime});
    ll distoprt;
    for(auto u : g[v]){
        if(block[u.ff])
            continue;
        if(u.ff == prt){
            change[u.ss].pb(root);
            distoprt = e[u.ss].z;
            continue;
        }
        dfs(u.ff, v);
    }
    tout[root][mytime] = curtime-1;
    seg[root].upd(1, 0, seg[root].maxn, mytime, curtime-1, distoprt);
}
void decomp(){
    findsz(root, 0);
    int totsz = sz[root];
    root = findcentroid(root, 0, totsz);
    seg[root].init(totsz);
    tin[root].pb({root, -1});
    tout[root].resize(totsz);
    curtime = 0;
    for(auto u : g[root]){
        if(block[u.ff]) continue;
        int enter = curtime;
        dfs(u.ff, root);
        entry[root].pb({enter, curtime-1});
        centmax[root].insert({seg[root].get(1, 0, seg[root].maxn, enter, curtime-1), {enter, curtime-1}});
    }
    sort(all(tin[root]));
    if(centmax[root].empty()) return;
    auto it = centmax[root].begin();
    centans[root] = it->ff;    
    if(centmax[root].size() >= 2){
        ++it;
        centans[root] += it->ff;
    }
    totmax.insert({centans[root], root});
    block[root] = 1;
    int v = root;
    for(auto u : g[v]){
        if(block[u.ff]) continue;
        root = u.ff;
        decomp();
    }
}
    
ll n, q, w;
ll last = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q >> w;
    for(int i = 0; i < n-1; ++i){
        cin >> e[i].x >> e[i].y >> e[i].z;
        g[e[i].x].pb({e[i].y, i});
        g[e[i].y].pb({e[i].x, i});
    }
    root = 1;
    decomp();
    
    for(int i = 0; i < q; ++i){
        ll d, val;
        cin >> d >> val;
        d = (d+last)%(n-1);
        val = (val+last)%w;
        ll ch = val - e[d].z;
        for(auto root : change[d]){
            int v;
            
            if(lower_bound(all(tin[root]), mp((int)e[d].x, -1))->ss > lower_bound(all(tin[root]), mp((int)e[d].y, -1))->ss)
                v = e[d].x;
            else
                v = e[d].y;
            //cout << v << ' ' << root << '\n';
            int in = lower_bound(all(tin[root]), mp(v, -1))->ss;
            int out = tout[root][in];

            pii cursub = entry[root][upper_bound(all(entry[root]), mp(in, (int)1e9))-entry[root].begin()-1];
            centmax[root].erase({seg[root].get(1, 0, seg[root].maxn, cursub.ff, cursub.ss), cursub});
            seg[root].upd(1, 0, seg[root].maxn, in, out, ch);
            centmax[root].insert({seg[root].get(1, 0, seg[root].maxn, cursub.ff, cursub.ss), cursub});
            totmax.erase({centans[root], root});
            auto it = centmax[root].begin();
            centans[root] = it->ff;               
            if(centmax[root].size() >= 2){  
                ++it;
                centans[root] += it->ff;
            }
            totmax.insert({centans[root], root});
        }
        last = totmax.begin()->ff;
        cout << last << '\n';
        e[d].z = val;
    }
}