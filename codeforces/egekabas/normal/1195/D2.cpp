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
ll mod = 998244353;
ll a[100009];
ll sum[100009];
ll ten[100];
ll ans;
ll dig(ll x){
    ll ret = 0;
    while(x > 0){
        ++ret;
        x /= 10;
    }
    return ret;
}
ll high(ll x){
    return sum[10]-sum[x-1];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum[dig(a[i])]++;
    }
    for(int i = 1; i <= 10; ++i){
        sum[i] += sum[i-1];
    }
    ten[0] = 1;
    for(int i = 1; i <= 30; ++i){
        ten[i] = ten[i-1]*10%mod;
    }
    for(int i = 0; i < n; ++i){
        ll cur = 0;
        ll tmp = a[i];
        ll old = 0;
        while(tmp > 0){
            ans += high(cur+1)*ten[2*cur]%mod*(tmp%10)%mod;
            ans %= mod;
            ans += high(cur+1)*ten[2*cur+1]%mod*(tmp%10)%mod;
            ans %= mod;
            ll neww;
            if(cur == 0) neww = 0;
            else neww = 2*(sum[cur]-sum[cur-1]);
            ans += old*(tmp%10)%mod*10%mod;
            ans %= mod;
            ans += neww*ten[2*cur]%mod*(tmp%10)%mod;
            ans %= mod;
            old = old*10%mod+neww*ten[2*cur]%mod;
            old %= mod;
            tmp /= 10;
            ++cur;
        }
    }
    cout << ans << endl;
}