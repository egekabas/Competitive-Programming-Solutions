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
struct Line{
    mutable ll k, m, p;
    bool operator<(const Line &o) const{
        return k < o.k;
    }
    bool operator<(ll o) const{
        return p < o;
    }
};
struct LineContainer:multiset<Line, less<>>{
    const ll inf = 1e18;
    ll div(ll x, ll y){
        return x/y - ((x^y) < 0 && x%y);
    }
    bool isect(iterator x, iterator y){
        if(y == end()){ 
            x->p = inf;
            return 0;
        }
        if(x->k == y->k)
            x->p = (x->m >= y->m)?inf : -inf;
        else
            x->p = div(x->m - y->m, y->k - x->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m){
        auto z = insert({k, m, 0});
        auto y = z++;
        auto x = y;
        while(isect(y, z)) z = erase(z);
        while((y = x) != begin() && isect(--x, y))
            isect(x, erase(y)); 
    }
    ll query(ll x){
        if(empty()) return -1e18;
        auto l = *lower_bound(x);
        return l.k*x + l.m;
    }
};
struct path{
    ll sz = 0, sum = 0, go = 0, come = 0;
};
vector<ll> g[200009];
ll n;
ll a[200009];
ll subsz[200009];
ll blocked[200009];
void calcsz(ll v, ll prt){
    subsz[v] = 1;
    for(auto u : g[v]){
        if(u == prt || blocked[u])
            continue;
        calcsz(u, v);
        subsz[v] += subsz[u];
    }
    return;
}
ll findcentroid(ll v, ll prt, ll totsize){
    for(auto u : g[v]){
        if(u == prt || blocked[u])
            continue;
        if(2*subsz[u] >= totsize)
            return findcentroid(u, v, totsize);
    }
    return v;
}
vector<path> cur;
void dfs(ll v, ll prt, path p){
    p.go += (p.sz+1)*a[v];
    p.come += p.sum + a[v];
    p.sum += a[v];
    p.sz++;
    cur.pb(p);
    for(auto u : g[v]){
        if(u == prt || blocked[u])
            continue;
        dfs(u, v, p);
    }
}
ll ans = 0;
void calcmain(ll v){
    calcsz(v, 0);
    v = findcentroid(v, 0, subsz[v]);
    LineContainer come, go;
    for(auto u : g[v]){
        if(blocked[u]) continue;
        cur.clear();
        dfs(u, v, {0, 0, 0, 0});
        for(auto u : cur){
            ans = max(ans, come.query(u.sum+a[v])+(u.go+a[v]+u.sum));
            ans = max(ans, go.query(u.sz)+u.come);
            ans = max(ans, (u.go+a[v]+u.sum));
            ans = max(ans, (u.come+a[v]*(u.sz+1)));
            
        }
        for(auto u : cur){
            go.add(a[v]+u.sum , u.go+a[v]+u.sum);
            come.add(u.sz, u.come);
        }
    }
    blocked[v] = 1;
    for(auto u : g[v])
        if(blocked[u] == 0)
            calcmain(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 1; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    calcmain(1);
    cout << ans << '\n';
}