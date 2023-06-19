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
int n, q;
int bit[100009];
int get(int idx){
    int ret = 0;
    for(++idx; idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}
void upd(int idx, int val){
    for(++idx; idx <= n; idx += idx&(-idx))
        bit[idx] += val;
}
void updrange(int l, int r, int val){
    upd(l, val);
    upd(r+1, -val);
}
int val[100009];
vector<int> g[100009];
int root;
int dad[100009][20];
void dfs1(int v){
    for(int i = 1; i < 20; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v]){
        dad[u][0] = v;
        dfs1(u);
        val[v] = min(val[v], val[u]);
    }
}
int sf(int x, int y){
    return val[x] < val[y];
}
int tin[100009];
int tout[100009];
int ord[100009];
int curtime = 0;
int curord = 0;
void dfs2(int v){
    sort(all(g[v]), sf);
    tin[v] = curtime++;
    for(auto u : g[v]){
        dfs2(u);
    }
    tout[v] = curtime-1;
    ord[v] = curord++;
}
int goup(int v, int x){
    for(int i = 19; i >= 0; --i)
        if(x&(1<<i))
            v = dad[v][i];
    return v;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        val[i] = i;
        int prt;
        cin >> prt;
        if(prt == 0)
            root = i;
        else
            g[prt].pb(i);
    }
    dfs1(root);
    dfs2(root);
    set<pii> s;
    for(int i = 1; i <= n; ++i)
        s.insert({ord[i], i});
    while(q--){
        int t, k;
        cin >> t >> k;
        if(t == 1){
            int last;
            while(k--){
                last = s.begin()->ss;
                s.erase(s.begin());
                updrange(tin[last], tout[last], 1);
            }
            cout << last << '\n';
        }
        else{
            int rolldown = get(tin[k])-1;
            cout << rolldown << '\n';
            int v = goup(k, rolldown);
            s.insert({ord[v], v});
            updrange(tin[v], tout[v], -1);
        }
    }
}
