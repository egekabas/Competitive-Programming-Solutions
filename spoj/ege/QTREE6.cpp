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
struct fen{
    int bit[100009];
    void init(){
        for(int i = 1; i <= n; ++i)
            bit[i] = 0;
    }
    void updsingle(int idx, int val){
        for(;idx <= n; idx += idx&(-idx))
            bit[idx] += val;
    }
    int get(int idx){
        int ret = 0;
        for(;idx > 0; idx -= idx&(-idx))
            ret += bit[idx];
        return ret;
    }
    void upd(int l, int r, int val){
        if(r < l || l == 0) return;
        updsingle(l, val);
        updsingle(r+1, -val);
    }
};
vector<int> g[100009];
int depth[100009];
int sz[100009];
int p[100009];
void dfs1(int v){
    depth[v] = depth[p[v]]+1;
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p[v]){
            p[u] = v;
            dfs1(u);
            sz[v] += sz[u];
        }
}
int head[100009];
int curtime = 0;
int ti[100009];
int child[100009];
void dfs2(int v){
    ti[v] = ++curtime;
    if(p[v] == 0 || ti[p[v]] != ti[v]-1)
        head[v] = v;
    else
        head[v] = head[p[v]];
    pii maxi = {0, 0};
    for(auto u : g[v])
        if(u != p[v])
            maxi = max(maxi, {sz[u], u});
    child[v] = maxi.ss;
    if(maxi.ss != 0)
        dfs2(maxi.ss);
    
    for(auto u : g[v])
        if(u != p[v] && u != maxi.ss)
            dfs2(u);
}
set<pii> s[100009][2];
int col[100009];
fen bit[2];
int findtop(int v, int val, int c){
    while(1){
        //cout << v << ' ';
        auto it = s[head[v]][c].lower_bound({depth[v], 0});
        if(it == s[head[v]][c].begin()){
            bit[c].upd(ti[head[v]], ti[v], val);
            if(col[p[head[v]]] != c || p[head[v]] == 0){
                bit[c].upd(ti[p[head[v]]], ti[p[head[v]]], val);
                return head[v];
            }
            v = p[head[v]];
        }
        else{
            --it;
            //cout << it->ss << ' ' << "HEY2!\n";
            bit[c].upd(ti[it->ss], ti[v], val);
            return child[it->ss];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n; ++i)
        col[i] = 1;
    child[0] = 1;
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= n; ++i){
        findtop(i, 1, 1);;
        s[head[i]][0].insert({depth[i], i});
    }
    cin >> m;
    while(m--){
        int t, v;
        cin >> t >> v;
        if(t == 0){
            v = findtop(v, 0, col[v]);
            cout << bit[col[v]].get(ti[v]) << '\n';
        }
        else{
            int cur = col[v];
            int nxt = (col[v]^1);
            col[v] = nxt;
            
            s[head[v]][cur].insert({depth[v], v});
            int curval = bit[cur].get(ti[v]);
            findtop(v, -curval, cur);
            bit[cur].upd(ti[v], ti[v], curval-1);

            s[head[v]][nxt].erase({depth[v], v});
            bit[nxt].upd(ti[v], ti[v], 1);
            curval = bit[nxt].get(ti[v]);
            findtop(v, curval, nxt);    
            bit[nxt].upd(ti[v], ti[v], -curval);
        }
    }
