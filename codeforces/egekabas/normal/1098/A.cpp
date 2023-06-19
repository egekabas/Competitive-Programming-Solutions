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
ll n;
ll s[100009];
ll a[100009];
vector<ll> g[100009];

void dfs(ll v, ll come){
    ll mini = (ll)1e9;
    if(s[v] == -1){
        for(auto u : g[v]){
            mini = min(mini, s[u]);
        }
        if(mini == (ll)1e9){
            a[v] = 0 ;
        }
        else
             a[v] = max((ll)0, mini-come);
        s[v] = come + a[v];
    }
    else{
        if(come > s[v]){
            cout << -1 << endl;
            exit(0); 
        }
        a[v] = s[v]-come;
    }
    for(auto u : g[v]){
        dfs(u, s[v]);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    ll tmp;
    for(ll i = 2; i <= n; ++i ){
        cin >> tmp;
        g[tmp].pb(i);
    }
    for(ll i = 1; i <= n; ++i )
        cin >> s[i];
    dfs(1, 0);
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        ans += a[i];
        //cout << a[i] << endl;
    }
    cout << ans << endl;
}