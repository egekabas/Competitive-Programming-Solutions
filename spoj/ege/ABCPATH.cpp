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
vector<int> dir = {-1, 0, 1};

int ar[55][55], vis[55][55];
int n, m;
void dfs(int x, int y){
    vis[x][y] = 1;
    
    for(auto u1 : dir)
        for(auto u2 : dir){
            int nx = u1+x;
            int ny = u2+y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] == 0 && ar[nx][ny] == ar[x][y]+1)
                dfs(nx, ny);
            
        }
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int caseno = 0;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            for(int j = 0; j < m; ++j)
                ar[i][j] = s[j]-'A';
            
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                vis[i][j] = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(vis[i][j] == 0 && ar[i][j] == 0)
                    dfs(i, j);
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(vis[i][j])
                    ans = max(ans, ar[i][j]+1);
        ++caseno;
        cout <<"Case " << caseno << ": " << ans << '\n';
    }

