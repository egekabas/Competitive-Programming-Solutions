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
struct edge{
    ll v;
    ll w;
    ll id;
};

set<pll> s;

vector<edge> g[300009];
pll go[300009];
ll dis[300009];
ll es[300009];
ll vs[300009];
ll n, m, k;

void dijk(){
    s.insert({0, 1});
    dis[1] = 0;
    while(!s.empty()){
        auto it = s.begin();
        ll d = (*it).ff;
        ll v = (*it).ss;

        s.erase(it);
        if(d > dis[v])
            continue;
        for(auto u : g[v]){
            if(d + u.w < dis[u.v]){
                go[u.v] = {v, u.id};
                dis[u.v] = d + u.w;
                s.insert({d + u.w, u.v});
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m >> k;
    ll t1, t2, t3;
    for(ll i = 0; i < m; ++i){
        cin >> t1 >> t2 >> t3;
        g[t1].pb({t2, t3, i});
        g[t2].pb({t1, t3, i});
    }
    for(ll i = 1; i <= n; ++i){
        dis[i] = (ll)1e18;
        vs[i] = 1;
    }
    dijk();
    for(ll i = 1; i <= n; ++i){
        s.insert({-dis[i], i});
    }
    for(auto u : s){
        ll k = u.ss;
        if(k == 1) continue;
        vs[go[k].ff] += vs[k];
        es[go[k].ss] += vs[k];
    }
    set<pll> fin;
    for(int i = 0; i < m; ++i){
        fin.insert({-es[i], i});
    }
    cout << k << endl;
    for(auto u : fin){
        if(k-- == 0) break;
        cout << u.ss+1 << " ";
    }
}