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
int n;
vector<int> g[500009];
int path[500009];
int root = 1;
int changed = 0;
int psize;
int f(int v, int p){
    int cur = 0;
    set<int> dif;
    for(auto u : g[v]){
        if(u == p)continue;
        if(f(u, v))
            return 1;
        if(cur == 0)
            cur = path[u];
        if(v == root)
            dif.insert(path[u]);
        if(cur != path[u] && v != root && changed == 0){
            root = v;
            changed = 1;
            return 1;
        }
        else if(cur != path[u] && v != root && changed == 1){
            cout << "-1\n";
            exit(0);
        }
    }
    if(v != root){
        path[v] = cur+1;
    }
    else{
        if(dif.size() > 2){
            cout << "-1\n";
            exit(0);
        }
        psize = 1;
        for(auto u : dif)
            psize += u;
    }
    return 0;
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i = 1; i <= n; ++i)
        if(g[i].size() > 2)
            root = i;
    if(f(root, -1))
        f(root, -1);
    while(psize % 2 && psize > 1){
        psize = (psize-1)/2+1;
    }
    cout << psize-1 << "\n";
}