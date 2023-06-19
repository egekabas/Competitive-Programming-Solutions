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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n, q;
ll a[200009];
ll b[200009];
ll fen[200009];
ll c[200009];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> q;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ll l, r;
    for(ll i = 0; i < q; ++i){
        cin >> l >> r;
        c[l] += 1;
        c[r+1] -= 1;
    }
    int cur = c[1];
    b[0] = cur;
    for(ll i = 2; i <= n; ++i){
        cur += c[i];
        b[i-1] = cur;
    }
    sort(b, b+n);
    ll ans = 0;
    for(ll i = 0; i < n; ++i)
        ans += a[i]*b[i];
    cout << ans;
}