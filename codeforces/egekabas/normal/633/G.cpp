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
const int sq = 300;
int n, m;
int a[100009], st[100009], fn[100009];
bitset<1009> notp;
vector<int> g[100009];
vector<int> val;
void dfs(int v, int prt){
    st[v] = val.size();
    val.pb(a[v]);
    for(auto u : g[v])
        if(u != prt)
            dfs(u, v);
    fn[v] = val.size()-1;
}
int lazy[1009];
bitset<1009> seg[1009];
int calc[1009];
void recalc(int x){
    seg[x].reset();
    for(int i = x*sq; i < n && i < (x+1)*sq; ++i){
        val[i] = (val[i]+lazy[x])%m;
        seg[x][val[i]] = 1;
    }
    calc[x] = 1;
    lazy[x] = 0;
}
void addseg(int x, int y){
    y %= m;
    seg[x] = (seg[x]<<y)|(seg[x]>>(m-y));
    lazy[x] = (lazy[x]+y)%m;
}
void add(int l, int r, int x){
    x %= m;
    for(int i = l; i <= r;){
        if(i%sq == 0 && i+sq-1 <= r){
            if(calc[i/sq] == 0)
                lazy[i/sq] = (lazy[i/sq]+x)%m;
            else
                addseg(i/sq, x);
            i += sq;
        }
        else{
            val[i] = (val[i]+x)%m;
            calc[i/sq] = 0;
            ++i;
        }
    }
}
int get(int l, int r){
    bitset<1009> bit;
    for(int i = l; i <= r;){
        if(i%sq == 0 && i+sq-1 <= r){
            if(calc[i/sq] == 0)
                recalc(i/sq);
            bit |= seg[i/sq];
            i += sq;
        }
        else{
            bit[(val[i]+lazy[i/sq])%m] = 1;
            ++i;
        }
    }
    int ret = 0;
    for(int i = 0; i < m; ++i){
        ret += (bit[i]&(!notp[i]));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    notp[0] = notp[1] = 1;
    for(int i = 2; i <= 1000; ++i){
        if(notp[i]) continue;
        for(int j = i*i; j <= 1000; j += i)
            notp[j] = 1;
    }
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    for(int i = 0; i < n; ++i)
        seg[i/sq][val[i]];
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        int v, x;
        if(t == 1){
            cin >> v >> x;
            add(st[v], fn[v], x);
        }
        else{
            cin >> v;
            cout << get(st[v], fn[v]) << '\n';
        }
    }
}