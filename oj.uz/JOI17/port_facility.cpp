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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
set<int> s[1000009];
int prt[1000009];
vector<int> g[1000009];
int findprt(int x){
    if(prt[x] == x) return x;
    return prt[x] = findprt(prt[x]);
}
void merge(int x, int y){
    x = findprt(x);
    y = findprt(y);
    if(x == y) return;
    if(g[y].size() + s[y].size() > g[x].size() + s[x].size())
        swap(x, y);
    for(auto u : g[y])
        if(findprt(u) == x){
            cout << 0;
            exit(0);
        }
    for(auto u : g[y])
        g[x].pb(u);
    for(auto u : s[y])
        s[x].insert(u);
    prt[y] = x;
    g[y].clear();
    s[y].clear();
}
pii a[1000009];
set<pii> ms;
vector<pair<int, pii>> ev;
int n;
int vis[1000009];
int col[1000009];
void dfs(int v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(vis[findprt(u)] == 0){
            col[findprt(u)] = col[v]^1;
            dfs(findprt(u));
        }
        if(col[findprt(u)] == col[v]){
            cout << 0;
            exit(0);
        }
    }
 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    for(int i = 1; i <= n; ++i){
        prt[i] = i;
        cin >> a[i].ff >> a[i].ss;
        ev.pb({a[i].ff, {i, 1}});
        ev.pb({a[i].ss, {i, 0}});
    }
    sort(ev.begin(), ev.end());
    for(auto u : ev){
        int i = u.ss.ff;
        if(u.ss.ss == 0){
            i = findprt(i);
            ms.erase({*s[i].begin(), i});
            s[i].erase(s[i].begin());
            if(s[i].size())
                ms.insert({*s[i].begin(), i});
            continue;
        }
        vector<int> tmp;
        while(ms.size() && ms.begin()->ff < a[i].ss){
            tmp.pb(ms.begin()->ss);
            ms.erase(ms.begin());
        }
        if(tmp.size()){
            for(auto u : tmp)
                merge(u, tmp[0]);
            g[findprt(tmp[0])].pb(i);
            g[i].pb(findprt(tmp[0]));
            ms.insert({*(s[findprt(tmp[0])].begin()) ,findprt(tmp[0])});
        }
        s[i].insert(a[i].ss);
        ms.insert({a[i].ss, i});
    }
    ll ans = 1;
    for(ll i = 1; i <= n; ++i)
        if(vis[findprt(i)] == 0){
            dfs(findprt(i));
            ans = ans*2%ll(1e9+7);
        }
    cout << ans << '\n';
}
