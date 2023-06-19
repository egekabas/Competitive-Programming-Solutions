#include "dreaming.h"
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
vector<pii> g[100009];
int vis[100009];
int depth[100009];
int ans = 0;
void dfs1(int v, int prt){
    vis[v] = 1;
    for(auto u : g[v])
        if(u.ff != prt){
            dfs1(u.ff, v);
            depth[v] = max(depth[v], depth[u.ff]+u.ss);
        }
}
int mindepth;
int maxdepth;
void dfs2(int v, int prt){
    mindepth = min(mindepth, depth[v]);
    maxdepth = max(maxdepth, depth[v]);
    multiset<int, greater<int>> s;
    for(auto u : g[v])
        s.insert(depth[u.ff]+u.ss);
    s.insert(0);
    for(auto u : g[v])
        if(u.ff != prt){
            int val = depth[u.ff]+u.ss;
            int befdepth = depth[u.ff];
            s.erase(s.lower_bound(val));
            depth[v] = *s.begin();
            depth[u.ff] = max(depth[u.ff], depth[v]+u.ss);
            dfs2(u.ff, v);
            s.insert(val);
            depth[v] = *s.begin();
            depth[u.ff] = befdepth;
        }
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for(int i = 0; i < M; ++i){
        g[A[i]].pb({B[i], T[i]});
        g[B[i]].pb({A[i], T[i]});
    }
    int ans = 0;
    vector<int> vec;
    for(int i = 0; i < N; ++i)
        if(vis[i] == 0){
            mindepth = 1e9+7;
            maxdepth = 0;
            dfs1(i, -1);
            dfs2(i, -1);
            ans = max(ans, maxdepth);
            vec.pb(mindepth);
        }
    if(vec.size() == 1) return ans;
    sort(all(vec), greater<int>());
    for(int i = 1; i < vec.size(); ++i)
        vec[i] += L;
    sort(all(vec), greater<int>());
    return max(ans, vec[0]+vec[1]);
}
