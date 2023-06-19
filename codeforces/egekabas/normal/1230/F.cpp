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
ll n, m, q;
ll az[100009];
vector<ll> cok[100009];
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m ;
    
    for(ll i = 0; i < m; ++i){
        ll x, y;
        cin >> x >> y;
        if(x < y)
            swap(x, y);
        az[x]++;
        cok[y].pb(x);
    }
    ll ans = 0;
    for(ll i = n; i >= 1; --i){
        ans += az[i]*cok[i].size();
    }
    cout << ans << "\n";
    cin >> q;
    while(q--){
        ll c;
        cin >> c;
        ans -= az[c]*cok[c].size();
        for(auto u : cok[c]){
            az[u]--;
            ans -= cok[u].size();
            cok[u].pb(c);
            ans += az[u];
            az[c]++;
        }
        cok[c].clear();    
        cout << ans << "\n";
    }
}