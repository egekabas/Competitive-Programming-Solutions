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
ll n;
ll a[200009];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/out.txt", "w", stdout);
    freopen("../IO/in.txt", "r", stdin);
#endif

    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n-1; ++i){
        ll x = a[i];
        ll y = a[i+1];
        if(x > y){
            ans += (n-x+1)*(x-y);
        }
        else if(x < y){
            ans += x*(y-x);
        }
        
    }
    ans += (n-a[n-1]+1)*a[n-1];
    cout << ans << endl;
}