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
ll m, a, b;
ll ans = 0;
int pre[(int)1e6+5];
ll exgcd(ll a, ll b, ll *x, ll *y){
    if(b < a) swap(a, b);
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll d = exgcd(b%a, a, &x1, &y1);
    *x = y1 - (b/a)*x1;
    *y = x1;
    return d;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> m >> a >> b;
    ll cur = 0, maxi = 0;
    while(1){
        if(cur > b)
            cur -= b;
        else
            cur += a;
        maxi = max(maxi, cur);
        if(pre[cur] != 0) break;
        pre[cur] = maxi; 
    }
    ans += (m/a+1)*(m+1 + m%a+1)/2;
    for(ll i = 1; i < a; ++i){
        if(i % gcd(a, b) != 0) continue;
        if(pre[i] > m) continue;
        ans += ((m-i)/a+1)*((m-i)+1+(m-i)%a+1)/2;
        ans -= ((pre[i]-1-i)/a+1)*((pre[i]-1-i)+1+(pre[i]-1-i)%a+1)/2;
    }
    cout << ans << endl;
}