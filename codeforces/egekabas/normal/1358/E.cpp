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
ll a[1000009];
ll p[1000009];
ll n;
ll x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 1; i <= (n+1)/2; ++i)
        cin >> a[i];
    cin >> x;
    for(ll i = (n+1)/2+1; i <= n; ++i)
        a[i] = x;
    if(x < 0)
        reverse(a+1, a+1+n);
    for(ll i = 1; i <= n; ++i)
        p[i] = p[i-1]+a[i];
    ll cur = n/2;
    for(ll i = cur; i <= n; ++i){
        while(p[i] <= p[i-cur] && cur <= n && cur <= i)
            ++cur;
        if(cur > n){
            cout << "-1\n";
            return 0;
        }
    }
    cout << cur << '\n';
}