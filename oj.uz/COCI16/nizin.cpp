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
ll a[1000009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll l = 0, r = n-1;
    ll suml = 0, sumr = 0;
    ll ans = 0;
    while(l < r){
        suml += a[l];
        sumr += a[r];
        a[l] = a[r] = 0;
        if(suml == sumr){
            ++l, --r;
        }
        else if(suml > sumr){
            ++ans;
            --r;
        }
        else{
            ++ans;
            ++l;
        }
    }
    cout << ans << "\n";
}
