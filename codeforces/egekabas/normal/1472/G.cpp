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
int n, m;
vector<int> g[200009];
vector<int> e[200009];
int d[200009];
int minval[200009];
int ans[200009];
void calc(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        g[i].clear();
        e[i].clear();
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        e[y].pb(x);
    }
    for(int i = 1; i <= n; ++i)
        d[i] = 1e9+7;
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(q.size()){
        int v = q.front();
        q.pop();
        for(auto u : g[v])
            if(d[u] == 1e9+7){
                d[u] = d[v]+1;
                q.push(u);
            }
    }
    vector<pii> vec;
    for(int i = 1; i <= n; ++i){
        minval[i] = d[i];
        for(auto u : g[i])
            minval[i] = min(minval[i], d[u]);
        ans[i] = 1e9+7;
        vec.pb({minval[i], i});
    }
    sort(all(vec));
    for(auto cursit : vec){
        int v = cursit.ss;
        if(ans[v] != 1e9+7) continue;
        ans[v] = minval[v];
        queue<int> q;
        q.push(v);
        while(q.size()){
            int v = q.front();
            q.pop();
            for(auto u : e[v])
                if(ans[u] > ans[v] && d[u] < d[v]){
                    ans[u] = ans[v];
                    q.push(u);
                }
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        calc();
    }

}