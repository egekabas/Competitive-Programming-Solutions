#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
ll pw(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y%2){
            ret = ret*x;
        }
        x = x*x;
        y /= 2;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x%y){
            cout << x << '\n';
            continue;
        }
        ll ans = 1;
        for(ll i = 2; i*i <= y; ++i){
            if(y%i) continue;
            ll cnt1 = 0;
            while(y%i == 0){
                y /= i;
                ++cnt1;
            }
            ll tmp = x;
            ll cnt2 = 0;
            while(tmp%i == 0){
                tmp /= i;
                ++cnt2;
            }
            //cout << i << ' ' << cnt1 << ' ' << cnt2 << '\n';
            ans = max(ans, x/pw(i, cnt2-cnt1+1));
        }
        if(y != 1){
            ll tmp = x;
            ll cnt = 0;
            while(tmp%y == 0){
                tmp /= y;
                ++cnt;
            }
            ans = max(ans, x/pw(y, cnt));
        }
        cout << ans << '\n';
    }
}