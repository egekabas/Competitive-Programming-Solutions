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
ll a, b, c, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for(ll x = a; x <= b; ++x){
        ll minval = max(1LL, min(x+b-c, d+1-c));
        ll maxval = min(x, d-c+1);
        ans += (maxval-minval+1)*(maxval+minval)/2;
        ans += maxval*max(0LL, (c-max((d+1-x), b)));
    }
    cout << ans << '\n';
}