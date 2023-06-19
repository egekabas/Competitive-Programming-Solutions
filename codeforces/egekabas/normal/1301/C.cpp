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
        ll n, one;
        cin >> n >> one;
        ll zero = n-one;
        ll gap = one+1;
        ll ans = n*(n+1)/2;
        ll extra = zero%gap;
        ans -= (gap-extra)*(zero/gap)*(zero/gap+1)/2;
        ans -= extra*(zero/gap+2)*(zero/gap+1)/2;
        cout << ans << '\n';
    }
}