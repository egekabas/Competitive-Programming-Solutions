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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for(ll i = 10; ; i *= 10){
            ll cur = i-1;
            if(cur > b)
                break;
            ans += a;
        }
        cout << ans << "\n";
    }
}