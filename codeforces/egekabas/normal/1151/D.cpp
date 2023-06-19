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
pll a[100009];
ll cmp(pll x, pll y){
    return (x.ff - x.ss) > (y.ff - y.ss);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i].ff >> a[i].ss;
    sort(a, a+n, cmp);
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        //cout << a[i].ff << " " << a[i].ss << endl;
        ans += i*a[i].ff + (n-i-1)*a[i].ss;
    }
    cout << ans << endl;;
}