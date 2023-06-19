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
struct edge{
    int a, b, w;
};
int func(edge x, edge y){
    return x.w < y.w;
}
vector<edge> v;
vector<edge> mst;
vector<edge> oth;
int n, m;
edge first;
int par[1000009];
int siz[1000009];
void create(int x){
    par[x] = x;
    siz[x] = 1;
}
int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}
void merge(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(siz[y] > siz[x]) swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    cin >> first.a >> first.b >> first.w;
    for(int i = 0; i < m-1; ++i){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v.pb({t1, t2, t3});
    }
    for(int i = 1; i <= n; ++i) create(i);
    sort(v.begin(), v.end(), func);
    merge(first.a, first.b);
    for(auto u : v){
        if(find(u.a) == find(u.b)){
            oth.pb(u);
        }
        else{
            merge(u.a, u.b);
            mst.pb(u);
        }
    }
    for(int i = 1; i <= n; ++i) create(i);
    for(auto u : mst){
        merge(u.a, u.b);
    }
    int ans = 1e9;
    for(auto u : oth){
        if(find(u.a) != find(u.b)){
            ans = min(ans, u.w);
        }
    }
    cout << ans << endl;
}