#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n, k;
vector<int> g[100009];
vector<int> counts;
bool vis[100009];
ll mod = (ll)1e9 + 7;

ll exp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2) res = (res * a)%mod;
        a = (a * a)%mod;
        b = b /2;
    }
    return res;
}


ll dfs(ll v){
    vis[v] = 1;
    ll add = 1;
    for(auto u : g[v]){
        if(!vis[u])
            add += dfs(u);
    }
    return add;
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> k;
   ll tmp1, tmp2, tmp3;
    for(ll i = 0; i < n-1; ++i){
        cin >> tmp1 >> tmp2 >> tmp3;
        if(tmp3 == 1)
            continue;
        else{
            g[tmp1].pb(tmp2);
            g[tmp2].pb(tmp1);
        }
    }
    ll groups = 0;
    for(ll i = 1; i <= n; ++i){
        if(!vis[i]){
            counts.pb(dfs(i));
            groups++;
        }
    }
    ll ans = exp(n, k);
    for(ll i = 0; i < groups; ++i){
        ans = (ans-exp(counts[i], k))%mod;
        if(ans < 0) ans = mod+ans;
    }
    cout << ans << endl;
}