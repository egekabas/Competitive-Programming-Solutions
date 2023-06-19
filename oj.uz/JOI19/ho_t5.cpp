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
int n, m;
vector<int> g[200009];
int col[200009];
int curans;
int cnt[200009];
vector<int> added;
void add(int v){
    added.pb(v);
    cnt[col[v]]++;
    if(cnt[col[v]] == 1) ++curans;
}
void del(int v){
    cnt[col[v]]--;
    if(cnt[col[v]] == 0) --curans;
}
int depth[200009];
void deluntil(int d){
    while(added.size() && depth[added.back()] >= d){
        del(added.back());
        added.pop_back();
    }
}
int len[200009];
int maxlen[200009][2];
void dfs1(int v, int prt){
    depth[v] = depth[prt]+1;
    len[v] = maxlen[v][0] = maxlen[v][1] = 0;
    for(auto u : g[v]){
        if(u == prt) continue;
        dfs1(u, v);
        len[v] = max(len[v], len[u]+1);
        if(len[u]+1 >= maxlen[v][0]){
            maxlen[v][1] = maxlen[v][0];
            maxlen[v][0] = len[u]+1;
        }
        else if(len[u]+1 > maxlen[v][1])
            maxlen[v][1] = len[u]+1;
    }
}
pii maxi = {0, 0};
void findfar(int v, int prt, int dis){
    maxi = max(maxi, {dis, v});
    for(auto u : g[v])
        if(u != prt)
            findfar(u, v, dis+1);
}
pii dia(){
    maxi = {0, 0};
    findfar(1, 0, 0);
    int v1 = maxi.ss;
    maxi = {0, 0};
    findfar(v1, 0, 0);
    return {v1, maxi.ss};
}
int ans[200009];
void dfs2(int v, int prt){
    deluntil(depth[v]-maxlen[v][1]);
    add(v);
    int deep = -1;
    for(auto u : g[v])
        if(u != prt && len[u]+1 == maxlen[v][0]){
            deep = u;
            dfs2(u, v);
            break;
        }
    deluntil(depth[v]-maxlen[v][0]);
    ans[v] = max(ans[v], curans);
    for(auto u : g[v]){
        if(u == prt || u == deep) continue;
        if(added.empty() || added.back() != v) add(v);
        dfs2(u, v);
    }
    deluntil(depth[v]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n; ++i)
        cin >> col[i];
    pii di = dia();
    dfs1(di.ff, 0);
    dfs2(di.ff, 0);
    
    dfs1(di.ss, 0);
    dfs2(di.ss, 0);
    
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
}
