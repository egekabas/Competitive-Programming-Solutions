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
int n, m;
vector<pii> g[200009];
vector<pii> edges;
int dir[200009];
bool vis[200009];
void dfs(int v, int come){
    vis[v] = 1;
    for (auto u : g[v]){
        if(come == 1){
            if((dir[u.ss] == 1 && edges[u.ss].ff == v) || (dir[u.ss] == -1 && edges[u.ss].ss == v)){
                cout << "NO\n";
                exit(0);
            }
            else{
                if(edges[u.ss].ff == v) dir[u.ss] = -1;
                else dir[u.ss] = 1;
                if(!vis[u.ff])
                    dfs(u.ff, 0);
            }
        }
        else if(come == 0){
            if((dir[u.ss] == 1 && edges[u.ss].ss == v) || (dir[u.ss] == -1 && edges[u.ss].ff == v)){
                cout << "NO\n";
                exit(0);
            }
            else{
                if(edges[u.ss].ss == v) dir[u.ss] = -1;
                else dir[u.ss] = 1;
                if(!vis[u.ff])
                    dfs(u.ff, 1);
            }
        }    
    } 
}
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        edges.pb({x, y});
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    dfs(1, 1);
    cout << "YES\n";
    for(int i = 0; i < m; ++i){
        if(dir[i] == 1) cout << "0";
        else cout << "1";
    }
}