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
int a[4009][4009];
int vis[4009][4009];
vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pii> q[2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j){
            if(s[j] == 'F')
                a[i][j] = 0;
            else if(s[j] == 'R')
                a[i][j] = 1;
            else
                a[i][j] = -1;
        }
    }
    q[a[0][0]].push({0, 0});
    int cur = a[0][0];
    vis[0][0] = 1;
    int ans = 0;
    while(q[0].size() || q[1].size()){
        ++ans;
        while(q[cur].size()){
            pii x = q[cur].front();
            q[cur].pop();
            for(auto u : dir){
                int x1 = x.ff + u.ff;
                int y1 = x.ss + u.ss;
                if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
                    continue;
                if(a[x1][y1] != -1 && vis[x1][y1] == 0){
                    q[a[x1][y1]].push({x1, y1});
                    vis[x1][y1] = 1;
                }
            }
        }
        cur ^= 1;
    }
    cout << ans << '\n';
}
