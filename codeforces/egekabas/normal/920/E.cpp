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
map<int, int> no[200009];
set<int> s;
int dfs(int v){
    int cur = 1;
    auto it = s.begin();
    while(it != s.end()){
        int u = *it;
        if(!no[v][u]){
            s.erase(u);
            cur += dfs(u);
        }
        it = s.upper_bound(u);
    }

    return cur;
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
        no[x][y] = no[y][x] = 1;
    }

    for(int i = 1; i <= n; ++i)
        s.insert(i);
    vector<int> ans;

    for(int i = 1; i <= n; ++i)
        if(s.lower_bound(i) != s.end() && *s.lower_bound(i) == i){
            s.erase(i);
            ans.pb(dfs(i));
        }
    sort(all(ans));
    cout << ans.size() << '\n';
    for(auto u : ans)
        cout << u << ' ';
}