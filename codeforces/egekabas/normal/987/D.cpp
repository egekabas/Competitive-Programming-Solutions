#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;

int n, m, k, s;
vector<int> g[100009];
vector<int> place[109];
int cost[100009][109];
bool vis[100009];
queue<pii> q;

int main(){
    cin >> n >> m >> k >> s;
    int p;
    for(int i = 1; i <= n; ++i){
        cin >> p;
        place[p].pb(i);
    }
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= k; ++i){
        while(!q.empty())
            q.pop();
        for(int j = 1; j <= n; ++j)
            vis[j] = 0;
        for(auto u : place[i]){
            q.push(mp(u, 0));
            vis[u] = 1;
            cost[u][i] = 0;
        }
        pii tmp;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            for(auto u : g[tmp.ff]){
                if(!vis[u]){
                    cost[u][i] = tmp.ss+1;
                    vis[u] = 1;
                    q.push(mp(u, tmp.ss+1));
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        int count = 0;
        for(int y = 0; y < s; ++y){
            int mini = (int)1e9;
            int idx = -1;
            for(int j = 1; j <= k; ++j){
                if(cost[i][j] <= mini){
                    idx = j;
                    mini = cost[i][j];
                }
            }
            count += mini;
            cost[i][idx] = (int)1e9 + 1;
        }
        cout << count << " ";
    }
}