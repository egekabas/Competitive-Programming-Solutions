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
struct Line{
    mutable ll k, m, p;
    bool operator<(const Line &oth) const{
        return k > oth.k;
    }
    bool operator<(ll o) const{
        return p < o;
    }
};
struct LineContainer:multiset<Line, less<>>{
    ll inf = 1e18+9;
    ll div(ll x, ll y){
        return x/y-((x^y) < 0 && x%y);
    }
    ll isect(iterator x, iterator y){
        if(y == end()){
            x->p = inf;
            return 0;
        }
        if(x->k == y->k){
            if(x->m <= y->m)
                x->p = inf;
            else
                x->p = -inf;
        }
        else
            x->p = div(x->m - y->m, y->k - x->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m){
        auto z = insert({k, m, 0});
        auto y = z++;
        auto x = y;
        while(isect(y, z)) z = erase(z);
        if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll val){
        auto o = *lower_bound(val);
        return o.k*val+o.m;
    }
};
void merge(LineContainer &x, LineContainer &y){
    if(y.size() > x.size())
        swap(x, y);
    for(auto u : y)
        x.add(u.k, u.m);
}
ll n;
ll a[100009];
ll b[100009];
vector<ll> g[100009];
ll ans[100009];
LineContainer s[100009];
void dfs(ll v, ll prt){
    if(g[v].size() == 1 && prt != 0){
        s[v].add(b[v], 0);
        return;
    }
    for(auto u : g[v]){
        if(u == prt) continue;
        dfs(u, v);
        merge(s[v], s[u]);
    }
    ans[v] = s[v].query(a[v]);
    s[v].add(b[v], ans[v]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    for(ll i = 1; i <= n; ++i)
        cin >> b[i];
    for(ll i = 1; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    for(ll i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}