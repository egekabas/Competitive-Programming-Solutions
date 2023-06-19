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
ll x, y, z;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> x >> y >> z;
    ll ans1 = 0;
    ll ans2 = 0;
    ans1 += x/z + y/z;
    x = x%z;
    y = y%z;
    if(x + y < z){
        cout << ans1 << " " << ans2 << endl;
        return 0;
    }
    ans2 += min(z-y, z-x);
    ++ans1;
    cout << ans1 << " " << ans2 << endl;
    return 0;
    
}