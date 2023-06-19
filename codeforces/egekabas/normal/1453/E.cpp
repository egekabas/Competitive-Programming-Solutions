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
vector<int> g[200009];
int n;
int val[200009];
int ans = 0;
void dfs(int v, int prt){
    vector<int> vec;
    for(auto u : g[v])
        if(u != prt){
            dfs(u, v);
            vec.pb(val[u]);
        }
    if(vec.size() == 1)
        val[v] = vec[0]+1;
    else if(vec.size()){
        if(v == 1){
            sort(all(vec), greater<int>());
            val[v] = vec[0]+1;
            for(int i = 1; i < vec.size(); ++i)
                ans = max(ans, vec[i]+2);
        } 
        else{
            sort(all(vec));
            for(auto u : vec)
                ans = max(ans, u+2);
            val[v] = vec[0]+1;
        }
    }
    ans = max(ans, val[v]);
}
void solve(){
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; ++i){
        g[i].clear();
        val[i] = 0;
    }
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}