#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

ll n;
ll a[509];
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
   if(n == 1){
       cout << a[0] << '\n';
       return 0;
   }
   if(n == 2){
       cout << (a[0]|a[1]) << '\n';
       return 0;
   }
    for(ll i = 0; i < n; ++i)
        for(ll j = i+1; j < n; ++j)
            for(ll k = j+1; k < n; ++k)
                ans = max(ans, (a[i]|a[j]|a[k]));
    cout << ans << '\n';    
}