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
struct node{
    ll a, b, c;
};
ll n;
struct bit{
    vector<ll> v;
    ll get(ll idx){
        ll ret = 0;
        for(++idx; idx > 0; idx -= idx&(-idx))
            ret += v[idx];
        return ret;
    }
    void upd(ll idx, ll val){
        for(++idx; idx <= n; idx += idx&(-idx))
            v[idx] += val;
    }
    ll get(ll l, ll r){
        return get(r)-get(l-1);
    }
};

bit seg0, seg1;
node ar[200009];
vector<ll> g[200009];
ll prt[200009];
ll bg[200009], ed[200009];
ll vis[200009];

ll curt = 0;
void dfs(ll v, ll p){
    prt[v] = p;
    bg[v] = curt;
    ++curt;
    for(auto u : g[v]){
        if(u == p)
            continue;
        dfs(u, v);
    }
    ed[v] = curt-1;
    if(ar[v].b == 0 && ar[v].c == 1)
        seg0.upd(bg[v], 1);
    else if(ar[v].b == 1 && ar[v].c == 0)
        seg1.upd(bg[v], 1);
}

void block(ll v){
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u : g[v])
        if(u != prt[v])
            block(u);
}

ll sortf(ll x, ll y){
    return ar[x].a < ar[y].a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    seg0.v.resize(200009);
    seg1.v.resize(200009);
    
    cin >> n;
    vector<ll> ns;
    for(ll i = 1; i <= n; ++i){
        cin >> ar[i].a >> ar[i].b >> ar[i].c;
        ns.pb(i);
    }
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    sort(ns.begin(), ns.end(), sortf);
    if(seg0.get(n-1) != seg1.get(n-1)){
        cout << "-1\n";
        return 0;
    }
    ll ans = 0;
    for(auto v : ns){
        if(vis[v]) continue;
        ll match = min(seg0.get(bg[v], ed[v]), seg1.get(bg[v], ed[v]));
        ans += 2*match*ar[v].a;
        seg0.upd(bg[v], -match);
        seg1.upd(bg[v], -match);
        block(v);
    }
    
    cout << ans << '\n';
}