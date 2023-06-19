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
ll pw[100];
ll i = 1;
map<ll, ll> mpp;
ll f(ll x){
    if(x == 1)
        return 1;
    if(x == 0)
        return 0;
    if(mpp[x] != 0)
        return mpp[x];
    
    ll cur = *(upper_bound(pw, pw+i, x)-1);

    return mpp[x] = f(cur-1)+f(x-cur)+cur;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    pw[0] = 1;
    while(pw[i-1] <= 1e12+2){
        pw[i] = 2*pw[i-1];
        ++i;
    }
    cin >> n;
    cout << f(n-1) << "\n";
}