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
ll t;
ll mod = 998244353; 
vector<ll> g[300009];
ll vis[300009];
ll odd, even, check;

void dfs(ll v){
    for(auto u : g[v]){
        if(vis[v] == 1){
            if(vis[u] == 1){
                check = 1;
                //cout << v <<  " " << u << endl;
            }
            else if(vis[u] == 0){
                ++even;
                vis[u] = 2;
                dfs(u);
            }
        }
        else if(vis[v] == 2){
            if(vis[u] == 2){
                check = 1;
                //cout << v <<  " " << u << endl;
            }
            else if(vis[u] == 0){
                ++odd;
                vis[u] = 1;
                dfs(u);
            }
        }
    }
}
ll mod_pow2(ll k){
    ll ans = 1;
    ll tmp = 2;
    while(k > 0){
        if(k % 2){
            ans = (ans*tmp)%mod;
            --k;
        }
        else{
            tmp = (tmp*tmp)%mod;
            k /= 2;
        }
    }
    return ans;
}
ll calc(ll a, ll b){
    return (mod_pow2(b)+mod_pow2(a))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif    
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0; i <= n; ++i){
            g[i].clear();
            vis[i] = 0;
        }
        ll x, y;
        for(ll i = 0; i < m; ++i){
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        check = 0; even = 0; odd = 0;
        ll ans = 1;
        for(ll i = 1; i <= n; ++i){
            if(!vis[i]){
                vis[i] = 1; 
                ++odd;
                dfs(i);
                if(calc(odd, even)){
                    ans = (ans*calc(odd, even))%mod;
                    //cout << calc(odd, even) << endl;
                }even = 0; odd = 0;
            }
        }
        //cout << even << " " << odd << " " ;
        if(check == 1)
            cout << "0\n";
        else{
            cout << ans << endl;
        }
    }
}