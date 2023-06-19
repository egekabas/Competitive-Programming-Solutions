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
int n;
vector<int> g[100009][2];
int reach[100009][2];
int dis[1000009][2];
void dfs(int v, int col){
    reach[v][col] = 1;
    for(auto u : g[v][col])
        if(reach[u][col] == 0)
            dfs(u, col);
}
void calcdis(int v, int col){
    for(auto u : g[v][0])
        if(dis[u][col] == 1e9){
            dis[u][col] = dis[v][col]+1;
            calcdis(u, col);
        }
    for(auto u : g[v][1])
        if(dis[u][col] == 1e9){
            dis[u][col] = dis[v][col]+1;
            calcdis(u, col);
        }
}
int st[2];
int winner, loser, draw;
void getans(int v){
    if(reach[v][winner] == 0){
        for(auto u : g[v][loser])
            if(reach[u][winner] == 0)
                draw = 1;
    }
    for(auto u : g[v][loser]){
        if(dis[u][loser] < dis[v][loser]) continue;
        if(!reach[u][winner] || dis[u][loser] < dis[u][winner])
            getans(u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    cin >> st[0] >> st[1];
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        if(s == "plava" || s == "magenta"){
            g[x][0].pb(y);
            g[y][0].pb(x);
        }
        if(s == "crvena" || s == "magenta"){
            g[x][1].pb(y);
            g[y][1].pb(x);
        }
    }
    for(int i = 1; i <= n; ++i)
        dis[i][0] = dis[i][1] = 1e9;
    dfs(st[0], 0);
    dfs(st[1], 1);
    dis[st[0]][0] = 0;
    dis[st[1]][1] = 0;
    calcdis(st[0], 0);
    calcdis(st[1], 1);
 
    if(dis[st[0]][1]%2)
        winner = 1;
    else
        winner = 0;
    loser = winner^1;
    draw = 0;
 
    int ok = 0;
    for(auto u : g[st[0]][0])
        if(u != st[1])
            ok = 1;
    if(!ok){
        cout << "Marin\n";
        return 0;
    }
    
 
    
    getans(st[loser]);
    
    if(g[st[winner]][winner].empty()){
        winner ^= 1;
        draw = 0;
    }
    if(draw)
        cout << "Magenta\n";
    else if(winner == 0)
        cout << "Paula\n";
    else
        cout << "Marin\n";
}
