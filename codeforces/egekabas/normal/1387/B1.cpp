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
vector<int> g[100009];
int edge[100009];
int vis[100009];
vector<int> group[100009];
int n;
queue<int> q;
int val[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n; ++i){
        edge[i] = g[i].size();
        if(edge[i] == 1){
            q.push(i);
            vis[i] = 1;
        }
    }
    while(q.size()){
        int v = q.front();
        q.pop();
        vis[v] = 2;
        if(group[v].size()){
            for(auto u : g[v]){
                edge[u]--;
                if(edge[u] <= 1 && vis[u] == 0){
                    vis[u] = 1;
                    q.push(u);
                }
            }
            continue;
        }
        int found = 0;
        for(auto u : g[v]){
            edge[u]--;
            if(vis[u] == 2) continue;
            group[u].pb(v);
            if(edge[u] == 1 && vis[u] == 0){
                q.push(u);
                vis[u] = 1;
            }
            found = 1;
        }
        if(found) continue;
        for(auto u : g[v])
            if(group[u].size()){
                group[u].pb(v);
                break;
            }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(group[i].empty())continue;
        group[i].pb(i);
        ans += 2*group[i].size()-2;
        for(int j = 0; j < group[i].size(); ++j)
            val[group[i][j]] = group[i][(j+1)%group[i].size()];
    }   
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i)
        cout << val[i] << ' ';
}