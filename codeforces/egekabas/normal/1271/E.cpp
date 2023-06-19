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
ll n, k;
ll check(ll x){
    if(x > n)
        return 0;
    ll ret = 1;
    if(x%2 == 0)
        ret += check(x+1);
    ll cur = 0;
    ll tmp = x;
    while(1){
        tmp *= 2;
        if(tmp > n)
            break;
        ++cur;
        if(x)
        ret += min(n-tmp+1, (((ll)1)<<cur));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    ll l = 0, r = n;
    while(l < r){
        ll m = l + (r-l+1)/2;
        if(check(2*m) >= k)
            l = m;
        else
            r = m-1;
    }
    if(check(2*l+1) >= k)
        cout << 2*l+1 << "\n";
    else
        cout << 2*l <<  "\n";
}