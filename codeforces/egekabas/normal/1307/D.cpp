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
int n, m, k;
int spe[200009];
vector<int> g[200009];

void bfs(int start, int ar[]){
    for(int i = 1; i <= n; ++i)
        ar[i] = 1e9;
    ar[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : g[v]){
            if(ar[u] == 1e9){
                ar[u] = ar[v]+1;
                q.push(u); 
            }
        }
    }
}
int dist1[200009];
int distn[200009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i)
        cin >> spe[i];
    while(m--){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs(1, dist1);
    bfs(n, distn);
    int curans = dist1[n];
    int ans = 0;
    vector<pii> v;
    for(int i = 0; i < k; ++i)
        v.pb({dist1[spe[i]], distn[spe[i]]});
    sort(v.begin(), v.end(), greater<pii>());
    int maxss = v[0].ss;
    for(int i = 1; i < k; ++i){
        ans = max(ans, min(curans, v[i].ff+maxss+1));
        maxss = max(maxss, v[i].ss);
    }
    cout << ans << '\n';
}