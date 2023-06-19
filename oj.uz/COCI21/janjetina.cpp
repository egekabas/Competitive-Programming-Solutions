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
int n, k;
 
int bit[100009];
 
void upd(int idx, int val){
    for(++idx; idx <= 100000; idx += idx&(-idx))
        bit[idx] += val;
}
int get(int idx){
    int ret = 0;
    for(++idx; idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}
 
vector<pii> g[100009];
int subsz[100009];
int block[100009];
void getsz(int v, int prt){
    subsz[v] = 1;
    for(auto u : g[v])
        if(u.ff != prt && !block[u.ff]){
            getsz(u.ff, v);
            subsz[v] += subsz[u.ff];
        }
}
int getcentroid(int v, int prt, int tot){
    for(auto u : g[v])
        if(u.ff != prt && !block[u.ff] && subsz[u.ff]*2 >= tot)
            return getcentroid(u.ff, v, tot);
    return v;
}
vector<pll> child[100009];
void dfs(int v, int prt,int d, int curmax, int top){
    child[top].pb({curmax, d});
    for(auto u : g[v])
        if(u.ff != prt && !block[u.ff])
            dfs(u.ff, v, d+1, max(curmax, u.ss), top);
}
vector<int> rel;
ll mx = 1e5;
ll ans;
 
void getans(int v){
    getsz(v, 0);
    v = getcentroid(v, 0, subsz[v]);
    vector<pii> vec;
    for(auto u : g[v]){
        if(block[u.ff]) continue;
        dfs(u.ff, v, 1, u.ss, u.ff);
        sort(all(child[u.ff]));
 
        for(auto u : child[u.ff]){
            if(u.ff-u.ss-k >= 0){
                ans += 2;
            }
            ans -= 2*get(u.ff-u.ss-k);
            upd(u.ss, 1);
        }
        for(auto u : child[u.ff]){
            upd(u.ss, -1);
            vec.pb(u);
        }
    }
    sort(all(vec));
    for(auto u : vec){
        ans += 2*get(u.ff-u.ss-k);
        upd(u.ss, 1);
    }
    for(auto u : vec){
        upd(u.ss, -1);
    }
    for(auto u : g[v])
        child[u.ff].clear();
    
    block[v] = 1;
    for(auto u : g[v])
        if(!block[u.ff])
            getans(u.ff);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(int i = 0; i < n-1; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    getans(1);
    cout << ans << '\n';
}
