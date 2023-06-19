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
vector<int> g[70009];
int dad[70009][20];
int depth[70009];
void dfs(int v, int prt){
    depth[v] = depth[prt]+1;
    dad[v][0] = prt;
    for(int i = 1; i < 20; ++i)
        dad[v][i] = dad[dad[v][i-1]][i-1];
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v);
}
int lca(int x, int y){
    if(depth[x] < depth[y])
        swap(x, y);
    for(int i = 19; i >= 0; --i)
        if(depth[dad[x][i]] >= depth[y])
            x = dad[x][i];
    if(x == y) return x;
    for(int i = 19; i >= 0; --i)
        if(dad[x][i] != dad[y][i]){
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}
struct node{
    set<pii> mini;
    set<pii, greater<pii>> fin;
    void add(int v1, int v2){
        mini.insert({v1, v2});
        fin.insert({v2, v1});
    }
    void clear(int d){
        while(fin.size() && fin.begin()->ff >= d){
            mini.erase({fin.begin()->ss, fin.begin()->ff});
            fin.erase(fin.begin());
        }
    }
};
void merge(node &a, node &b){
    if(a.mini.size() < b.mini.size())
        swap(a, b);
    for(auto u : b.mini)
        a.add(u.ff, u.ss);
    b.mini.clear();
    b.fin.clear();
}
node mini[70009];
node maxi[70009];
int p[70009];
pii critval[70009];
void calc(int v, int prt){
    p[v] = prt;
    for(auto u : g[v])
        if(u != prt){
            calc(u, v);
            merge(mini[v], mini[u]);
            merge(maxi[v], maxi[u]);
        }
    mini[v].clear(depth[v]);
    maxi[v].clear(depth[v]);
    critval[v] = {-1,-1};
    if(mini[v].mini.size())
        critval[v].ff = -mini[v].mini.begin()->ff;
    if(maxi[v].mini.size())
        critval[v].ss = maxi[v].mini.begin()->ff;
}
vector<int> posval[70009];
int sz[70009];
int ans[70009];
int done[70009];
int main(){
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
    dfs(1, 0);
    cin >> q;
    vector<int> mpp;
    for(int i = 0; i < q; ++i){
        char type;
        int x, y, z;
        cin >> type >> x >> y >> z;
        int d = depth[lca(x, y)];
 
        if(type == 'M'){
            maxi[x].add(z, d);
            maxi[y].add(z, d);
        }
        else{
            mini[x].add(-z, d);
            mini[y].add(-z, d);
        }
        mpp.pb(z);
    }
    sort(all(mpp));
    mpp.resize(unique(all(mpp))-mpp.begin());
 
    calc(1, 0);
    for(int i = 2; i <= n; ++i){
        if(critval[i].ff != -1){
            critval[i].ff = lower_bound(all(mpp), critval[i].ff)-mpp.begin();
            posval[critval[i].ff].pb(i);
        }
        if(critval[i].ss != -1){
            critval[i].ss = lower_bound(all(mpp), critval[i].ss)-mpp.begin();
            posval[critval[i].ss].pb(i);
        }
    }   
    set<pii> s;
    for(int i = 0; i < mpp.size(); ++i){
        sz[i] = posval[i].size();
        s.insert({posval[i].size(), i});
    }
    while(s.size()){
        int cur = s.begin()->ss;
        s.erase(s.begin());
        done[cur] = 1;
        int v;
        for(auto u : posval[cur])
            if(ans[u] == 0){
                v = u;
                break;
            }
        if(critval[v].ff != -1 && done[critval[v].ff] == 0){
            s.erase({sz[critval[v].ff], critval[v].ff});
            sz[critval[v].ff]--;
            s.insert({sz[critval[v].ff], critval[v].ff});
        }
        if(critval[v].ss != -1 && done[critval[v].ss] == 0){
            s.erase({sz[critval[v].ss], critval[v].ss});
            sz[critval[v].ss]--;
            s.insert({sz[critval[v].ss], critval[v].ss});
        }
        ans[v] = mpp[cur];
    }
    for(int i = 2; i <= n; ++i){
        cout << i << ' ' << p[i] << ' ';
        if(ans[i])
            cout << ans[i];
        else{
            if(critval[i].ff != -1)
                cout << mpp[critval[i].ff];
            else
                cout << 0;
        }
        cout << '\n';
    }
}
