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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
int seg[800009];
multiset<int, greater<int>> s[800009];
void upd(int v, int tl, int tr, int idx, int val){
    if(tl == tr){
        seg[v] = val;
        return;
    }
    if(idx <= (tl+tr)/2)
        upd(2*v, tl, (tl+tr)/2, idx, val);
    else
        upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
    seg[v] = max(seg[2*v], seg[2*v+1]);
}
int get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return 0;
    if(l <= tl && tr <= r)
        return seg[v];
    return max(
        get(2*v, tl, (tl+tr)/2, l, r),
        get(2*v+1, (tl+tr)/2+1, tr, l, r)
    );
}
int n;
void add(int idx, int val){
    if(idx < 0) return;
    s[idx].insert(val);
    upd(1, 0, n, idx, *s[idx].begin());
}
void erase(int idx, int val){
    if(idx < 0) return;
    s[idx].erase(s[idx].lower_bound(val));
    if(s[idx].empty())
        upd(1, 0, n, idx, 0);
    else
        upd(1, 0, n, idx, *s[idx].begin());
}
vector<int> g[200009];
int k;
int chips[200009];
int dis[200009];
int ans[200009];
int block[200009];
int subsz[200009];
void findsz(int v, int prt){
    subsz[v] = 1;
    for(auto u : g[v])
        if(u != prt && !block[u]){
            findsz(u, v);
            subsz[v] += subsz[u];
        }
}
vector<pii> vecs[200009];
int findcentroid(int v, int prt, int tot){
    for(auto u : g[v])
        if(u != prt && !block[u] && 2*subsz[u] > tot)
            return findcentroid(u, v, tot);
    return v;
}
void dfs(int v, int prt, int depth, vector<pii> &vec){
    vec.pb({v, depth});
    for(auto u : g[v])
        if(u != prt && !block[u])
            dfs(u, v, depth+1, vec);
}
void func(int root){
    findsz(root, 0);
    root = findcentroid(root, 0, subsz[root]);
    for(auto u : g[root]){
        if(block[u]) continue;
        vecs[u].clear();
        dfs(u, root, 1, vecs[u]);
    }

    for(auto u : g[root]){
        if(block[u]) continue;
        for(auto v : vecs[u])
            add(dis[v.ff]-v.ss, dis[v.ff]);
    }

    add(dis[root], dis[root]);

    for(auto u : g[root]){
        if(block[u]) continue;
        for(auto v : vecs[u])
            erase(dis[v.ff]-v.ss, dis[v.ff]);
        for(auto v : vecs[u]){
            ans[v.ff] = max(ans[v.ff], get(1, 0, n, v.ss+1, n));
        
        }
        for(auto v : vecs[u])
            add(dis[v.ff]-v.ss, dis[v.ff]);
    }
    ans[root] = max(ans[root], get(1, 0, n, 1, n));
    
    for(auto u : g[root]){
        if(block[u]) continue;
        for(auto v : vecs[u])
            erase(dis[v.ff]-v.ss, dis[v.ff]);
    }
    erase(dis[root], dis[root]);
    block[root] = 1;
    for(auto u : g[root])
        if(!block[u])
            func(u);
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
    cin >> k;
    for(int i = 0; i < k; ++i){
        cin >> chips[i];
    }
    for(int i = 1; i <= n; ++i)
        dis[i] = 1e9;
    queue<int> q;
    for(int i = 0; i < k; ++i){
        q.push(chips[i]);
        dis[chips[i]] = 0;
    }
    while(q.size()){
        int v = q.front();
        q.pop();
        for(auto u : g[v])
            if(dis[u] == 1e9){
                dis[u] = dis[v]+1;
                q.push(u);
            }
    }
    func(1);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}