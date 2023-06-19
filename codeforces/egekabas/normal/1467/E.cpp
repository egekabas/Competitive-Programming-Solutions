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
int n;
int a[200009];
vector<int> g[200009];
map<int, int> cnt;
map<int, int> val[200009];
int down[200009];
int maybetop[200009];
int top[200009];
void merge(map<int, int> &a, map<int, int> &b){
    if(b.size() > a.size())
        swap(a, b);
    for(auto u : b)
        a[u.ff] += u.ss;
}
void dfs1(int v, int prt){
    val[v][a[v]]++;
    set<int> s;
    for(auto u : g[v])
        if(u != prt){
            dfs1(u, v);
            if(down[u] == 0 || val[u][a[v]])
                s.insert(u);
        }
    for(auto u : g[v])
        if(u != prt)
            if(s.empty() || (s.size() == 1 && *s.begin() == u)){
                if(val[u][a[u]] == cnt[a[u]])
                    maybetop[u] = 1;
            }
    down[v] = 1;
    for(auto u : g[v])
        if(u != prt){
            if(val[u][a[v]])
                down[v] = 0;
            down[v] &= down[u];
            merge(val[v], val[u]);
        }
}
void dfs2(int v, int prt){
    top[v] = 1;
    for(auto u : g[v])
        if(u != prt && maybetop[u])
            dfs2(u, v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += (down[i]&top[i]);
        //cout << i << ' ' << down[i] << ' ' << top[i] << '\n';
    }
    cout << ans << '\n';
}