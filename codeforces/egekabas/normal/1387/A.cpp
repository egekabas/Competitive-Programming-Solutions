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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
int n, m;
vector<pii> g[100009];
vector<pii> val[100009];
int vis[100009];
vector<int> cur;
void dfs(int v){
    cur.pb(v);
    vis[v] = 1;
    for(auto u : g[v]){
        val[u.ff].pb({u.ss-val[v][0].ff, -val[v][0].ss});
        if(vis[u.ff] == 0)
            dfs(u.ff);
    }
}
ld ans[100009];
int same(ld a, ld b){
    return abs(a-b) < 0.0000001;
}
ld solve(pll a, pll b){
    return ld(b.ff-a.ff)/(a.ss-b.ss);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        cur.clear();
        val[i].pb({0, 1});
        dfs(i);
        int det = 0;
        ld xval;
        for(auto u : cur){
            sort(val[u].begin(), val[u].end());
            val[u].resize(unique(val[u].begin(), val[u].end())-val[u].begin());
            if(val[u].size() > 1){
                det = 1;
                if(val[u][0].ss == val[u][1].ss){
                    cout << "NO\n";
                    return 0;
                }
                xval = solve(val[u][0], val[u][1]);
            }
        }
        if(!det){
            vector<int> newcur;
            for(auto u : cur)
                if(val[u][0].ss != 0)
                    newcur.pb(-val[u][0].ff/val[u][0].ss);
            sort(newcur.begin(), newcur.end());
            xval = newcur[newcur.size()/2];
        }
        for(auto u : cur){
            ans[u] = val[u][0].ff + xval*val[u][0].ss;
            for(auto pp : val[u]){
                if(same(pp.ff + pp.ss*xval, ans[u]) == 0){
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
        cout << fixed << setprecision(10) << ans[i] << ' ';    
}