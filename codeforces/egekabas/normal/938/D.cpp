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
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pll> g[200009];
ll cost[200009];
ll n, m;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    ll t1, t2, t3;
    for(ll i = 0; i < m; ++i){
        cin >> t1 >> t2 >> t3;
        g[t1].pb({t2, t3});
        g[t2].pb({t1, t3});
    }
    for(ll i = 1; i <= n; ++i){
        cin >> t1;
        pq.push({t1, i});
        cost[i] = t1;
    }
    while(!pq.empty()){
        pair tmp = pq.top();
        pq.pop();
        ll dis = tmp.ff;
        ll v = tmp.ss;
        if(dis > cost[v])
            continue;
        for(auto u : g[v]){
            if(dis + 2*u.ss < cost[u.ff]){
                cost[u.ff] = dis + 2*u.ss;
                pq.push({cost[u.ff], u.ff});
            }
        }
    }
    for(ll i = 1; i <= n; ++i)
        cout << cost[i] << " ";
}