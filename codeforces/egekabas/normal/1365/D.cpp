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
char grid[55][55];
int vis[55][55];
int n, m;
vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dfs1(int x, int y){
    vis[x][y] = 1;
    int ok = 1;
    int badpeople = 0;
    for(auto u : dir){
        int x1 = x + u.ff;
        int y1 = y + u.ss;
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m)
            continue;
        badpeople |= (grid[x1][y1] == 'B');
    }
    if(badpeople && grid[x][y] == 'G')
        return 0;
    if(badpeople){
        grid[x][y] = '#';
        return 1;
    }
    for(auto u : dir){
        int x1 = x + u.ff;
        int y1 = y + u.ss;
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || vis[x1][y1] || grid[x1][y1] == '#')
            continue;
        ok &= dfs1(x1, y1);
    }
    return ok;
}
int goodseen = 0;
void dfs2(int x, int y){
    if(grid[x][y] == '#') return;
    goodseen += (grid[x][y] == 'G');
    vis[x][y] = 1;
    for(auto u : dir){
        int x1 = x + u.ff;
        int y1 = y + u.ss;
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || vis[x1][y1] || grid[x1][y1] == '#')
            continue;
        dfs2(x1, y1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            for(int j = 0; j < m; ++j){
                grid[i][j] = s[j];
                vis[i][j] = 0;
            }
        }
        if(dfs1(n-1, m-1) == 0){
            cout << "No\n";
            continue; 
        }
        int goodcount = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                goodcount += (grid[i][j] == 'G');
                vis[i][j] = 0;
            }
        goodseen = 0;
        dfs2(n-1, m-1);
        if(goodcount != goodseen)
            cout << "No\n";
        else
            cout << "Yes\n";
        
    }
}