#include <bits/stdc++.h>
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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
vector<ll> g[100009];
ll sz[100009];
void calcsz(ll v, ll prt){
    sz[v] = 1;
    for(auto u : g[v])
        if(u != prt){
            calcsz(u, v);
            sz[v] += sz[u];
        }
}
ll ans = 0;
void calcans(ll v, ll prt, ll top){
    ans += 2*min(top, sz[v]);
    ++top;
    for(auto u : g[v])
        if(u != prt)
            top += sz[u];
    for(auto u : g[v])
        if(u != prt)
            calcans(u, v, top-sz[u]);
}
ll n;

ll findcentroid(ll v, ll prt){
    for(auto u : g[v])
        if(sz[u] > n/2 && u != prt)
            return findcentroid(u, v);
    return v;
}
vector<ll> av[100009];
vector<ll> used[100009];
void dfs(ll v, ll prt, ll root){
    av[root].pb(v);
    used[root].pb(v);
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v, root);
}
int sfunc(int x, int y){
    return av[x].size() > av[y].size();
}
int val[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    calcsz(1, 0);
    calcans(1, 0, 0);
    ll root = findcentroid(1, 0);
    
    vector<ll> v;
    v.pb(root);
    av[root] = used[root] = {root};
    for(auto u : g[root]){
        v.pb(u);
        dfs(u, root, u);
    }
    sort(v.begin(), v.end(), sfunc);
    ll bef = 0;
    ll aft = 1;
    for(ll i = 0; i < v.size(); ++i){
        while(aft < v.size() && used[v[i]].size()){
            while(used[v[i]].size() && av[v[aft]].size()){
                val[used[v[i]].back()] = av[v[aft]].back();
                used[v[i]].pop_back();
                av[v[aft]].pop_back();
            }
            if(av[v[aft]].empty()) ++aft;
        }
        while(bef < i && used[v[i]].size()){
            while(used[v[i]].size() && av[v[bef]].size()){
                val[used[v[i]].back()] = av[v[bef]].back();
                used[v[i]].pop_back();
                av[v[bef]].pop_back();
            }
            if(av[v[bef]].empty()) ++bef;
        }
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i)
        cout << val[i] << ' ';
}