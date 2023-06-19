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
ll n;
ll a[100009];
ll mod = 998244353;
ll ans = 0;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        ll mult = 1;
        ll tmp = a[i];
        while(tmp > 0){
            ll cur = tmp%10;
            ans = (ans + n*cur%mod*mult%mod)%mod;
            mult = mult*100%mod;
            tmp /= 10;
        }
        mult = 10;
        tmp = a[i];
        while(tmp > 0){
            ll cur = tmp%10;
            ans = (ans + n*cur%mod*mult%mod)%mod;
            mult = mult*100%mod;
            tmp /= 10;
        }
    }
    cout << ans << endl;
}