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
ll n, k;
ll a[100009];
ll b[100009];
ll val[100009];;
ll pre[100009];
ll ans = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    for(ll i = 1; i <= n; ++i)
        cin >> b[i];
    for(ll i = 1; i <= n; ++i)
        val[i] = (a[i]-b[i]);
    sort(val+1, val+1+n);
    for(ll i = 1; i <= n; ++i)
        pre[i] = val[i] + pre[i-1];    
    for(ll beg = 0; beg <= k; ++beg){
        ll fin = k-beg;
        ll idx = (beg+1+n-fin)/2;
        ll cur = ((pre[n-fin]-pre[idx-1]) - val[idx]*((n-fin)-(idx-1)));
        cur += val[idx]*(idx-1-beg)-(pre[idx-1]-pre[beg]);
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
