#include <bits/stdc++.h>
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
int n, m;
vector<int> ans;
vector<pii> g[200009];
int val[200009];
int vis[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
        --val[x];
        --val[y];
    }
    queue<int> ok;
    int fine = 0;
    for(int i = 1; i <= n; ++i)
        if(val[i] >= 0){
            ok.push(i);
            ++fine;
        }
    while(ok.size()){
        int v = ok.front();
        ok.pop();
        for(auto u : g[v]){
            if(vis[u.ss])
                continue;
            ans.pb(u.ss);
            vis[u.ss] = 1;
            val[u.ff]++;
            if(val[u.ff] == 0){
                ok.push(u.ff);
                ++fine;
            }
        }
    }
    if(fine != n){
        cout << "DEAD\n";
        return 0;
    }
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u+1 << ' ';
}