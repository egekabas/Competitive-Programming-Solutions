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
int sz[400009];
int mlo[400009];
int n;
vector<int> g[400009];
int ans[400009];
void dfs1(int v, int p){
    sz[v] = 1;
    mlo[v] = 1;
    for(auto u : g[v]){
        if(u == p)
            continue;
        dfs1(u, v);
        sz[v] += sz[u];
        mlo[v] = max(mlo[v], mlo[u]);
    }
    if(sz[v] <= n/2)
        mlo[v] = max(mlo[v], sz[v]);
}
void dfs2(int v, int p){
    ans[v] = 1;
    int cnt = 0;
    multiset<pii> s;
    s.insert({-1, v});
    for(auto u : g[v]){
        //cout << v << " " << u << " " << 
        //sz[u] << " " << mlo[u] << "\n";
        s.insert({-mlo[u], u});
        if(sz[u] > n/2){
            if(sz[u] - mlo[u] <= n/2)
                ++cnt;
            else
                ans[v] = 0;
        }
    }
    if(cnt > 1)
        ans[v] = 0;
    int totsize = sz[v];
    for(auto u : g[v]){
        if(u == p)
            continue;
        sz[v] = totsize-sz[u];
        int lowsize = sz[u];
        int lowval = mlo[u];
        sz[u] += sz[v];
        s.erase({-lowval, u});
        mlo[v] = -(*s.begin()).ff;
        if(sz[v] <= n/2)
            mlo[v] = max(mlo[v], sz[v]);
        mlo[u] = max(mlo[u], mlo[v]);
        dfs2(u, v);
        sz[u] -= sz[v];
        s.insert({-lowval, u});
        sz[u] = lowsize;
        mlo[u] = lowval;
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " ";
    }
    
}