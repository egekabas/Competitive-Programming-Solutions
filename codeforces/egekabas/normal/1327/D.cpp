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
int n;
vector<int> g;
int c[200009];
int vis[200009];
int ans;
vector<int> v;
void dfs(int x){
    if(vis[x])return;
    v.pb(c[x]);
    vis[x] = 1;
    dfs(g[x]);
}
void calc(int x){
    vector<int> mpp(x);
    for(int i = 0; i < v.size(); ++i){
        if(mpp[i%x] == 0)
            mpp[i%x] = v[i];
        if(mpp[i%x] != v[i])
            mpp[i%x] = -1;
    }
    for(auto u : mpp)
        if(u != -1)
            ans = min(ans, x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        g.clear();
        for(int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;
            g.pb(tmp-1);
        }
        for(int i = 0; i < n; ++i)
            cin >> c[i];
        for(int i = 0; i < n; ++i)
            vis[i] = 0;
        ans = 1e9;
        for(int i = 0; i < n; ++i)
            if(vis[i] == 0){
                v.clear();
                dfs(i);
                for(int i = 1; i*i <= v.size(); ++i){
                    if(v.size()%i == 0){
                        calc(i);
                        calc(v.size()/i);
                    }
                }
            }
        cout << ans << '\n';
    }
}