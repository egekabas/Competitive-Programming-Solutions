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
int n, m;
int vis[100009];
map<int, int> mpp[100009];
int ans = -1;
set<int> s;
void dfs(int v){
    vis[v] = 1;
    vector<int> vtmp;
    for(auto u : s){
        if(mpp[v][u] == 0){
            mpp[v].erase(u);
            vtmp.pb(u);
        }
    }
    for(auto u : vtmp)
        s.erase(u);
    for(auto u : vtmp)
        dfs(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        mpp[t1][t2] = mpp[t2][t1] = 1;
    }
    for(int i = 1; i <= n; ++i)
        s.insert(i);
    for(int i = 1; i <= n; ++i){
        if(vis[i] == 0){
            ++ans;
            s.erase(i);
            dfs(i);
        }
    }
    cout << ans << "\n";
}