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
pll check(ll x){
    ll mini = -1e18;
    ll maxi = 1e18;
    for(ll i = 0; i < n; ++i){
        if(a[i] == -1)
            continue;
        if(i < n-1 && a[i+1] == -1){
            mini = max(mini, a[i]-x);
            maxi = min(maxi, a[i]+x);
        }
        if(i > 0 && a[i-1] == -1){
            mini = max(mini, a[i]-x);
            maxi = min(maxi, a[i]+x);
        }
    }
    return {mini, maxi};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        ll l = 0, r = 1e9;
        for(ll i = 0; i < n-1; ++i)
            if(a[i] != -1 && a[i+1] != -1)
                l = max(l, abs(a[i]-a[i+1]));
        while(l < r){
            ll m = (l+r)/2;
            pll pr = check(m);
            if(pr.ff > pr.ss)
                l = m+1;
            else
                r = m;
        }
        cout << l << ' ' << max(0LL, check(l).ff) << '\n';
    }
}