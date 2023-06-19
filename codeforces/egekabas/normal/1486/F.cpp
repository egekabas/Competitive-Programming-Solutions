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
ll n, m;
ll ans = 0;
ll dad[300009][25];
ll depth[300009];
vector<ll> g[300009];
void dfs(ll v, ll prt){
    dad[v][0] = prt;
    depth[v] = depth[prt]+1;
    for(ll i = 1; i < 25; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v);
}
ll lca(ll x, ll y){
    if(depth[y] > depth[x]) swap(x, y);
    for(ll i = 24; i >= 0; --i)
        if(depth[dad[x][i]] >= depth[y])
            x = dad[x][i];
    if(x == y) return x;
    for(ll i = 24; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}
ll goup(ll x, ll val){
    for(ll i = 24; i >= 0; --i)
        if((1<<i) <= val){
            val -= (1<<i);
            x = dad[x][i];
        }
    return x;
}

vector<pii> twobot[300009];
vector<ll> onebot[300009];
ll totop[300009];
ll sttotop[300009];
ll pnt[300009];
void getans(ll v, ll prt){
    for(auto u : g[v]){
        if(u == prt) continue;
        getans(u, v);
    }
    ll befval = ans;
    ans += ll(twobot[v].size())*ll(twobot[v].size()-1)/2;
    map<ll, ll> mpp1;
    for(auto u : twobot[v]){
        if(u.ff > u.ss) swap(u.ff, u.ss);
        ans -= mpp1[u.ff];
        ans -= mpp1[u.ss];
        mpp1[u.ff]++;
        mpp1[u.ss]++;
        totop[u.ff]--;
        totop[u.ss]--;
    }
    map<pll, ll> mpp2;
    for(auto u : twobot[v]){
        if(u.ff > u.ss) swap(u.ff, u.ss);

        ans += mpp2[u];
        mpp2[u]++;
    }
    
    ll onebef = 0;
    for(auto u : onebot[v]){
        mpp1[u]++;
        ++onebef;
        ans += twobot[v].size()+onebef-mpp1[u];
        totop[u]--;
        sttotop[v]--;
    }
    for(auto u : g[v]){
        if(u == prt) continue;
        totop[v] += totop[u];

        ans += ll(totop[u])*(onebot[v].size()+twobot[v].size()-mpp1[u]);
    }
    ans += sttotop[v]*(onebot[v].size()+twobot[v].size());
    totop[v] += sttotop[v];
    ans += ll(pnt[v])*(pnt[v]-1)/2;
    ans += ll(pnt[v])*(onebot[v].size()+twobot[v].size()+totop[v]);
}
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
    dfs(1, 0);
    cin >> m;
    while(m--){
        ll x, y;
        cin >> x >> y;
        if(depth[x] > depth[y])
            swap(x, y);
        if(x == y){
            pnt[x]++;
            continue;
        }
        ll lc = lca(x, y);
        //cout << x << ' ' << y << ' ' << lc << '\n';
        if(x != lc){
            twobot[lc].pb({goup(x, depth[x]-depth[lc]-1), goup(y, depth[y]-depth[lc]-1)});
        }
        else{
            onebot[lc].pb(goup(y, depth[y]-depth[lc]-1));
        } 
        sttotop[x]++;
        sttotop[y]++;
    }
    getans(1, 0);
    cout << ans << '\n';
}