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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int prt[2000009];
int sz[2000009];
vector<bool> val[2000009];
int find(int x){
    if(prt[x] == x) return x;
    return prt[x] = find(prt[x]);
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    prt[y] = x;
}
int n, m;
char ch[2000009];
int col[2000009];
bool vis[2000009];
int depth[2000009];
int out[2000009];
vector<int> in[2000009];
int ans1, ans2;
void dfs(int v){
    vis[v] = 1;
    int u = out[v];
    if(vis[u] == 0){
        depth[u] = depth[v]+1;
        dfs(u);
    }
    else if(sz[find(v)] == 0){
        sz[find(v)] = abs(depth[v]-depth[u])+1;
        val[find(v)].resize(sz[find(v)]);
        ans1 += sz[find(v)];
    }
    depth[v] = (depth[v]%sz[find(v)]+sz[find(v)])%sz[find(v)];
    if(col[v] == 1 && val[find(v)][depth[v]] == 0){
        ++ans2;
        val[find(v)][depth[v]] = 1;
    }
    for(auto u : in[v]){
        if(vis[u]) continue;
        depth[u] = depth[v]-1;
        dfs(u);
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
        ans1 = ans2 = 0;
        cin >> n >> m;
        for(int i = 0; i < n*m; ++i){
            vis[i] = depth[i] = sz[i] = 0;
            val[i].clear();
            in[i].clear();
            prt[i] = i;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                col[i*m+j] = c-'0';
                col[i*m+j] ^= 1;
            }
            
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                cin >> ch[i*m+j];
                out[i*m+j] = i*m+j;
                if(ch[i*m+j] == 'U')
                    out[i*m+j] -= m;
                else if(ch[i*m+j] == 'D')
                    out[i*m+j] += m;
                else if(ch[i*m+j] == 'L')
                    --out[i*m+j];
                else
                    ++out[i*m+j];
                in[out[i*m+j]].pb(i*m+j);
            }

        for(int i = 0; i < n*m; ++i){
            merge(i, out[i]);
        }

        for(int i = 0; i < n*m; ++i){
            if(vis[i] == 0)
                dfs(i);
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
}