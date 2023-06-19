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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
struct fenwick{
    vector<ll> bit;
    void upd(ll idx, ll val){
        for(++idx; idx < bit.size(); idx += idx&(-idx))
            bit[idx] += val;
    }
    ll get(ll idx){
        ll ret = 0;
        for(++idx; idx > 0; idx -= idx&(-idx))
            ret += bit[idx];
        return ret;
    }
    void updrange(ll l, ll r, ll val){
        if(l > r) return;
        upd(l, val);
        upd(r+1, -val);
    }
};
vector<ll> ng[200009];
ll tin[200009];
ll tout[200009];
fenwick bt;
ll curt = 0;
void dfs2(ll v){
    tin[v] = curt++;
    for(auto u : ng[v])
        dfs2(u);
    tout[v] = curt-1;
}

ll val[200009];
vector<ll> g[200009];
ll n, m;
ll prt[200009];
void dfs1(ll v){
    if(v != 1){
        ng[prt[prt[v]]].pb(v);
    }
    for(auto u : g[v]){
        if(u == prt[v]) continue;
        prt[u] = v;
        dfs1(u);
    }
}
ll othtin[200009];
ll othtout[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    bt.bit.resize(n+2);
    for(ll i = 1; i <= n; ++i)
        cin >> val[i];
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }    
    dfs1(1);
    dfs2(0);
    dfs2(1);
    for(ll i = 0; i <= n; ++i){
        othtin[i] = 1e9+7;
        for(auto u : g[i])
            if(u != prt[i]){
                othtin[i] = min(othtin[i], tin[u]);

                othtout[i] = max(othtout[i], tout[u]);
            }
       //cout << i << ' ' << tin[i] << ' ' << tout[i] << ' ' << othtin[i] << ' ' << othtout[i] << '\n';

    }
    while(m--){
        ll t;
        cin >> t;
        if(t == 1){
            ll x, va;
            cin >> x >> va;
            bt.updrange(tin[x], tout[x], va);
            bt.updrange(othtin[x], othtout[x], -va);
        }
        else{
            ll x;
            cin >> x;
            cout << val[x]+bt.get(tin[x]) << '\n';
        }
    }
}