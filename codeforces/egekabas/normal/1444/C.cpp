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
typedef pair<int, int> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n, m, k;
int col[500009];
vector<int> gr[500009];

int prt[500009];
int add[500009];
int sz[500009];
pll findprt(int x){
    if(prt[x] == x)
        return {x, add[x]};
    pll ret = findprt(prt[x]);

    ret.ss^=add[x];
    return ret;
}
struct status{
    int x, xadd, xsz, y, yadd, ysz;
};
vector<status> rvec;
int badadded;
void merge(int x, int y){
    pll a, b;
    a = findprt(x);
    b = findprt(y);
    rvec.pb({a.ff, add[a.ff], sz[a.ff], b.ff, add[b.ff], sz[b.ff]});
    if(a.ff == b.ff){
        if(a.ss == b.ss){
            badadded = 1;
        }
    }
    else{
        if(sz[a.ff] < sz[b.ff])
            swap(a, b);
        prt[b.ff] = a.ff;
        sz[a.ff] += sz[b.ff];
        if(b.ss == a.ss){
            add[b.ff] ^= 1;
        }
    }
}
void roll(){
    status cur = rvec.back();
    rvec.pop_back();
    
    prt[cur.x] = cur.x;
    sz[cur.x] = cur.xsz;
    add[cur.x] = cur.xadd;

    prt[cur.y] = cur.y;
    sz[cur.y] = cur.ysz;
    add[cur.y] = cur.yadd;
}
int badgr[500009];
map<pll, vector<pll>> mpp;
vector<pll> intedge[500009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        cin >> col[i];
        gr[col[i]].pb(i);
        prt[i] = i;
        sz[i] = 1;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        if(col[x] == col[y]){
            intedge[col[x]].pb({x, y});
        }
        else
            mpp[{min(col[x], col[y]), max(col[x], col[y])}].pb({x, y});
    }
    ll ans = k;
    for(int i = 1; i <= k; ++i){
        badadded = 0;
        for(auto u : intedge[i])
            merge(u.ff, u.ss);
        if(badadded){
            badgr[i] = 1;
            --ans;
        }
    }
    ans = ans*(ans-1)/2;
    for(auto u : mpp){
        int g1 = u.ff.ff;
        int g2 = u.ff.ss;
        if(badgr[g1] || badgr[g2]) continue;
        vector<pll> edges = u.ss;
        badadded = 0;
        for(auto u : edges){
            merge(u.ff, u.ss);
        }
        ans -= badadded;
        for(auto u : edges)
            roll();
    }
    cout << ans << '\n';
}