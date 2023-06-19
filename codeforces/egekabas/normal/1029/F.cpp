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
ll a, b;
vector<int> v;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> a >> b;
    ll ans = 1e18;
    
    v.clear();
    for(ll i = 1; i*i <= a; ++i)
        if(a%i == 0)
            v.pb(i);
    for(ll i = 1; i*i <= (a+b);++i){
        if((a+b)%i != 0) continue;
        ll j = *(upper_bound(v.begin(), v.end(), i)-1);
        if(a/j <= (a+b)/i)
            ans = min(ans, ((a+b)/i+i)*2);
    }
    swap(a, b);
    v.clear();
    for(ll i = 1; i*i <= a; ++i)
        if(a%i == 0)
            v.pb(i);
    for(ll i = 1; i*i <= (a+b);++i){
        if((a+b)%i != 0) continue;
        ll j = *(upper_bound(v.begin(), v.end(), i)-1);
        if(a/j <= (a+b)/i)
            ans = min(ans, ((a+b)/i+i)*2);
    }
    cout << ans << endl;
}