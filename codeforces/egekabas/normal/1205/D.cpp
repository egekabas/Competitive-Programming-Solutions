#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int n;
vector<int> g[1009];

int sz[1009];
void calcsz(int v, int prt){
    sz[v] = 1;
    for(auto u : g[v])
        if(u != prt){
            calcsz(u, v);
            sz[v] += sz[u];
        }
}
int getc(int v, int prt){
    for(auto u : g[v])
        if(u != prt && sz[u] > n/2)
            return getc(u, v);
    return v;
}

int curupd = 0;
int curprev = 0;
int curans = 0;

void dfs(int v, int prt, int d, int st){
    if(st == 1)
        curupd++;
    
    curans = d+curprev;
    
    for(auto u : g[v])
        if(u != prt){
            if(curupd*curupd < 2*n*n/9 && st){
                cout << u << ' ' << v << ' ' << curupd+1-d << '\n';
                dfs(u, v, curupd+1, 1);
            }
            else{
                cout << u << ' ' << v << ' ' << curans+1-d << '\n';
                dfs(u, v, curans+1, 0);
            }
        }
}

int sf(int x, int y){
    return sz[x] < sz[y];
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    calcsz(1, 0);
    int v = getc(1, 0);
    calcsz(v, 0);

    sort(all(g[v]), sf);

    for(auto u : g[v]){
        if(curprev*curprev < 2*n*n/9){
            cout << u << ' ' << v << ' ' << curprev+1 << '\n';
            dfs(u, v, curprev+1, 1);
        }
        else{
            cout << u << ' ' << v << ' ' << curans+1 << '\n';
            dfs(u, v, curans+1, 0);
        }
        curprev = curupd;
    }

    if(curans < 2*n*n/9)
        for(auto u : g[v])
            cout << sz[u] << '\n';
}