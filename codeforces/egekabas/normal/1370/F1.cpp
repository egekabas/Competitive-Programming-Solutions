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
int n;
vector<int> g[1009];
pii qu(vector<int> v){
    if(v.empty()){
        return {0, 1e9};
    }
    cout << "? " << v.size();
    for(auto u : v)
        cout << ' ' << u;
    cout << endl;
    pii ret;
    cin >> ret.ff >> ret.ss;
    return ret;
}
vector<int> vd;
void dfs(int v, int prt, int l, int r, int d){
    if(prt <= 0) vd.clear();
    if(l <= d && d <= r)
        vd.pb(v);
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v, l, r, d+1);
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
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 1; i < n; ++i){
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        vector<int> tmp;
        for(int i = 1; i <= n; ++i) tmp.pb(i);
        pii pi = qu(tmp);
        int root = pi.ff;
        int dis = pi.ss;
        int v1 = -1;
        int cur = 0;
        for(int i = 9; i >= 0; --i){
            dfs(root, 0, cur+(1<<i), 1e9, 0);
            pi = qu(vd);
            if(pi.ss == dis){
                cur += (1<<i);
                v1 = pi.ff;
            }
        }
        dfs(v1, 0, dis, dis, 0);
        int v2 = qu(vd).ff;
        cout << "! " << v1 << ' ' << v2 << endl;
        string eat;
        cin >> eat;
        if(eat == "Incorrect") return 0;
    }
}