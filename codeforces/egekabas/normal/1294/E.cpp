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
ll n, m;
ll ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    ll a[n+5][m+5];
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j)
            cin >> a[i][j];
    for(ll j = 0; j < m; ++j){
        vector<ll> v;
        for(ll i = 0; i < n; ++i)
            v.pb(n+i);
        for(ll i = 0; i < n; ++i){
            a[i][j] -= j+1;
            if(a[i][j] % m == 0 && a[i][j]/m < n)
                v[(i-a[i][j]/m+n)%n]--;
        }
        ll mini = n;
        for(auto u : v)
            mini = min(mini, u);
        ans += mini;    
    }
    cout << ans << "\n";
}