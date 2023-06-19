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
typedef pair<int, int> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n;
int calcval(int a, int b){
    int c = n-a-b;
    return max({abs(a-b), abs(a-c), abs(b-c)});
}
int ans = 1e9;
 
vector<int> g[200009];
multiset<int> s, ins;
int sz[200009];
int uptop = 0;
void dfs1(int v, int prt){
    sz[v] = 1;
 
    for(auto u : g[v])
        if(u != prt){
            dfs1(u, v);
            sz[v] += sz[u];
        }
    s.insert(sz[v]);
}
void calc(int x, multiset<int> &s){
    int opt = (n-x)/2;
    auto it = s.lower_bound(opt);
    if(it != s.end()){
        ans = min(ans, calcval(x, *it));
    }
    if(it != s.begin()){
        --it;
        ans = min(ans, calcval(x, *it));
    }
}
 
void dfs2(int v, int prt, int del){
    s.erase(s.lower_bound(sz[v]));
 
    pii maxi = {0, 0};
    for(auto u : g[v])
        if(u != prt)
            maxi = max(maxi, {sz[u], u});
    
    for(auto u : g[v])
        if(u != prt && u != maxi.ss)
            dfs2(u, v, 0);
    if(maxi.ss){
        dfs2(maxi.ss, v, 1);
    }
    
    calc(sz[v], s);
    calc(n-sz[v], ins);
 
    ins.insert(sz[v]);    
    if(del == 0){
        for(auto u : ins)
            s.insert(u);
        ins.clear();
    }
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << ans << '\n';
    //cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
}
