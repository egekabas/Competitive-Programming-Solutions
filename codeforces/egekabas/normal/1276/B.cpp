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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
vector<ll> g[400009];
bool vis[400009];
ll n, m, a, b;

void dfs1(ll v){
    vis[v] = 1;
    for(auto u : g[v]){
        if(u != a && u != b && vis[u] == 0)
            dfs1(u);
    }
}
ll cnt(ll v){
    vis[v] = 1;
    ll ret = 0;
    for(auto u : g[v]){
        if(vis[u] == 0)
            ret += 1+cnt(u);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b;
        for(ll i = 1; i <= n; ++i){
            g[i].clear();
            vis[i] = 0;
        }
        while(m--){
            ll t1, t2;
            cin >>t1 >> t2;
            g[t1].pb(t2);
            g[t2].pb(t1);      
        }
        ll cnt1 = 0;
        ll cnt2 = 0;
        dfs1(a);
        cnt1 = cnt(b);
        for(ll i = 1; i <= n; ++i)
            vis[i] = 0;
        dfs1(b);
        cnt2 = cnt(a);
        cout << cnt1*cnt2 << "\n";
    }
}