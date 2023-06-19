#include "stations.h"
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
vector<int> g[1009];
vector<int> ans;
int curt = 0;
void dfs(int v, int prt, int depth){
    if(depth%2 == 0)
        ans[v] = curt++;
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v, depth+1);
    if(depth%2 == 1)
        ans[v] = curt++;
}
std::vector<int> label(int n, int k, std::vector<int> u, std::vector<int> v) {
    ans = vector<int>(n);
    for(int i = 0; i < n; ++i)
        g[i].clear();
    for(int i = 0; i < n-1; ++i){
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    curt = 0;
    dfs(0, -1, 0);
    return ans;
}
 
int find_next_station(int s, int t, std::vector<int> c) {
    int smaller = 0;
    for(auto u : c)
        if(u < s)
            smaller = 1;
    if(smaller == 0){
        sort(all(c));
        if(t < s)
            return c.back();
        for(auto u : c)
            if(t <= u)
                return u;
        return c.back();
    }
    else{
        
        sort(all(c), greater<int>());
        if(t > s)
            return c.back();
        for(auto u : c)
            if(t >= u)
                return u;
        return c.back();
    }
}
