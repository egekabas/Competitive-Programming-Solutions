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
int prt[200009];
int sz[200009];
int con[200009];
void create(int v){
    prt[v] = v;
    sz[v] = 1;
}
int find(int v){
    if(prt[v] == v) return v;
    return prt[v] = find(prt[v]);
}
void merge(int v, int u){
    v = find(v); u = find(u);
    if(v == u) return;
    if(sz[v] < sz[u]) swap(v, u);
    prt[u] = v;
    sz[v] += sz[u];
}
int n, m;
int ans;
struct edge{
    int w, a, b;
} edges[200009];
int func(edge x, edge y){
    return x.w < y.w;
}
vector<pii> v;
void pros(){
    for(auto u : v){
        //cout << u.ff << " " << u.ss << "    ";
        if(find(u.ff) == find(u.ss))
            ++ans;
        else
            merge(u.ff, u.ss);
    }
    //cout << "\n";
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) create(i);
    int t1, t2, t3;
    for(int i = 0; i < m; ++i){
        cin >> t1 >> t2 >> t3;
        edges[i] = {t3, t1, t2};
    }
    sort(edges, edges+m, func);
    int cur = edges[0].w;
    for(int i = 0; i < m; ++i){
        if(cur != edges[i].w){
            pros();
            v.clear();
            cur = edges[i].w;
        }
        if(find(edges[i].a) != find(edges[i].b))
            v.pb({edges[i].a, edges[i].b});
    }
    pros();
    cout << ans << endl;
}