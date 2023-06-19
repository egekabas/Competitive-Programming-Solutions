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
int n;
vector<int> g[200009];
int dis[200009];
void dfs(int v){
    for(auto u : g[v]){
        if(dis[u] != 1e9)
            continue;
        dis[u] = dis[v]+1;
        dfs(u);
    }
}
int mark[200009];
void dfs2(int v, int p, int goal){
    if(v == goal){
        mark[v] = 1;
        return;
    }
    for(auto u : g[v]){
        if(u == p)
            continue;
        dfs2(u, v, goal);
        if(mark[u]){
            mark[v] = 1;
            return;
        }    
    }
}
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
    }
    for(int i = 1; i <= n; ++i)
        dis[i] = 1e9;
    dis[1] = 0;
    dfs(1);
    int id1 = 0, d = 0;
    for(int i = 1; i <= n; ++i)
        if(dis[i] > d){
            d = dis[i];
            id1 = i;
        }
    for(int i = 1; i <= n; ++i)
        dis[i] = 1e9;
    dis[id1] = 0;
    dfs(id1);
    int id2;
    d = 0;
    for(int i = 1; i <= n; ++i)
        if(dis[i] > d){
            d = dis[i];
            id2 = i;
        }
    ans = d;
    dfs2(id1, -1, id2);
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(mark[i]){
            dis[i] = 0;
            q.push(i);
            continue;
        }
        dis[i] = 1e9;
    }
    d = 0;
    int id3;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(dis[v] >= d && v != id1 && v != id2){
            d = dis[v];
            id3 = v;
        }
        for(auto u : g[v]){
            if(dis[u] != 1e9)
                continue;
            dis[u] = dis[v]+1;
            q.push(u);
        }
    }
    ans += d;
    cout << ans << '\n';
    cout << id1 << " " << id2 << " " << id3 << "\n";
}