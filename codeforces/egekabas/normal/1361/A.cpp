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
vector<int> g[500009];
int t[500009];
int used[500009];
int sfunc(int x, int y){
    return t[x] < t[y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<int> lst;
    for(int i = 1; i <= n; ++i){
        cin >> t[i];
        lst.pb(i);
    }
    sort(lst.begin(), lst.end(), sfunc);
    for(auto v : lst){
        sort(g[v].begin(), g[v].end(), sfunc);
        int cur = 1;
        for(auto u : g[v])
            if(t[u] == cur && used[u])
                ++cur;
        if(t[v] != cur){
            cout << "-1\n";
            return 0;
        }
        used[v] = 1;
    }
    for(auto v : lst)
        cout << v << ' ';
}