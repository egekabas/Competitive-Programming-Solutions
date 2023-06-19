#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;

int d[10009];
vector<pair<int, int>>g[10009];
//priority_queue(pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>);
bool vis[10009];
int n, e, t, m;
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> e >> t >> m;
    int x, y, z;
    for(int i = 0; i < m; ++i){
        cin >> x >> y >> z;
        g[y].pb(mp(x, z));
    }
    for(int i = 1; i <= n; ++i)
        d[i] = 10000000;
    d[e] = 0;
    for(int i = 1; i <= n; ++i){
        int v = -1;
        for(int j = 1; j <= n; ++j)
            if(vis[j] == 0 && (v == -1 || d[j] < d[v]))
                v = j;
        vis[v] = 1;
        for(auto u : g[v])
            d[u.ff] = min(d[v] + u.ss, d[u.ff]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(d[i] <= t){
            ++ans;
        }
    }
    cout << ans;

}
