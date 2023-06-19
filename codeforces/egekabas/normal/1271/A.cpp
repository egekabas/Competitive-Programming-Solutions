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
ll a, b, c, d, e, f;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = 0;
    if(e > f){
        ll cnt = min(a, d);
        ans += e*cnt;
        a -= cnt;
        d -= cnt;
        cnt = min(min(b, c), d);
        ans += f*cnt;
        d -= cnt;
        b -= cnt;
        c -= cnt;
    }
    else{
        ll cnt = min(min(b, c), d);
        ans += f*cnt;
        d -= cnt;
        b -= cnt;
        c -= cnt;
        cnt = min(a, d);
        ans += e*cnt;
        a -= cnt;
        d -= cnt;
    }
    cout << ans << "\n";
}