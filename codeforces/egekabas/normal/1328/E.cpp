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
int n, m;
vector<int> g[200009];
int d[200009];
int dad[200009][30];
void dfs(int v, int prt){
    dad[v][0] = prt;
    for(int i = 1; i < 30; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v])
        if(prt != u){
            d[u] = d[v]+1;
            dfs(u, v);
        }
}
int lca(int x, int y){
    if(d[y] > d[x])
        swap(y, x);
    for(int i = 29; i >= 0; --i)
        if(d[dad[x][i]] >= d[y])
            x = dad[x][i];
    if(x == y) return x;
    for(int i = 29; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}
int sfunc(int x, int y){return d[x] < d[y];}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    d[1] = 1;
    dfs(1, 0);
    while(m--){
        int k;
        vector<int> v;
        cin >> k;
        for(int i = 0; i < k; ++i){
            int tmp;
            cin >> tmp;
            v.pb(tmp);
        }
        sort(v.begin(), v.end(), sfunc);
        int ok = 1;
        int bef = 0;
        for(auto u : v){
            if(lca(u, bef) != bef && lca(u, bef) != dad[u][0]){
                ok = 0;
                break;
            }
            bef = dad[u][0];
        }
        if(ok == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}