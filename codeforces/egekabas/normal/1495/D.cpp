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
int n, m;
int dis[409][409];
vector<int> g[409];
const ll mod = 998244353;
vector<int> line[609];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j)
                dis[i][j] = 1e9+7;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        dis[x][y] = dis[y][x] = 1;
    }   
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            ll ans = 1;
            for(int k = 0; k <= dis[i][j]; ++k)
                line[k].clear();
            for(int k = 1; k <= n; ++k){
                if(abs(dis[i][k]-dis[j][k]) == dis[i][j] && i != k && j != k){
                    int cnt = 0;
                    for(auto u : g[k])
                        if(min(dis[i][u], dis[j][u]) == min(dis[i][k], dis[j][k])-1)
                            ++cnt;
                    ans = ans*cnt%mod;
                } 
                else{
                    if(dis[i][k]+dis[k][j] == dis[i][j]){
                        line[dis[i][k]].pb(k);
                        continue;
                    }
                    int cnt = 0;
                    for(auto u : g[k])
                        if(dis[i][u] == dis[i][k]-1 && dis[j][u] == dis[j][k]-1)
                            ++cnt;
                    ans = ans*cnt%mod;
                }
            }
            for(int k = 1; k <= dis[i][j]; ++k){
                if(line[k].size() != 1){
                    ans = 0;
                    break;
                }
                if(dis[line[k][0]][line[k-1][0]] != 1){
                    ans = 0;
                    break;
                }
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }

}
// 5 6