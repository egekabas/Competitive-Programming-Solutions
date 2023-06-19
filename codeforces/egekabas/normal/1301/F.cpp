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
int n, m, k;
int a[1009][1009];
int dist[1009][1009][45];
vector<pii> vec[45];
int done[45];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            vec[a[i][j]].pb({i, j});
        }
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int z = 1; z <= k; ++z)
                dist[i][j][z] = 1e9;
    for(int col = 1; col <= k; ++col){
        queue<pll> que;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i][j] == col){
                    dist[i][j][col] = 0;
                    que.push({i, j});
                }
        for(int i = 1; i <= k; ++i)
            done[i] = 0;
        done[col] = 1;
        while(!que.empty()){
            pll x = que.front();
            que.pop();
            if(done[a[x.ff][x.ss]] == 0){
                done[a[x.ff][x.ss]] = 1;
                for(auto u : vec[a[x.ff][x.ss]])
                    if(dist[u.ff][u.ss][col] == 1e9){
                        dist[u.ff][u.ss][col] = dist[x.ff][x.ss][col]+1;
                        que.push(u);
                    }
            }
            if(dist[x.ff+1][x.ss][col] == 1e9){
                dist[x.ff+1][x.ss][col] = dist[x.ff][x.ss][col]+1;
                que.push({x.ff+1, x.ss});
            }
            if(dist[x.ff-1][x.ss][col] == 1e9){
                dist[x.ff-1][x.ss][col] = dist[x.ff][x.ss][col]+1;
                que.push({x.ff-1, x.ss});
            }
            if(dist[x.ff][x.ss-1][col] == 1e9){
                dist[x.ff][x.ss-1][col] = dist[x.ff][x.ss][col]+1;
                que.push({x.ff, x.ss-1});
            }
            if(dist[x.ff][x.ss+1][col] == 1e9){
                dist[x.ff][x.ss+1][col] = dist[x.ff][x.ss][col]+1;
                que.push({x.ff, x.ss+1});
            }
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = abs(x1-x2)+abs(y1-y2);
        for(int i = 1; i <= k; ++i)
            ans = min(ans, dist[x1][y1][i] + dist[x2][y2][i] + 1);
        cout << ans << '\n';
    }
}