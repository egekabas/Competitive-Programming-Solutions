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
ll x, n;
ll a[1009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> x >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n; ++i)
        ans += x-a[i];
    ans += x;
    cout << ans << "\n";
}
