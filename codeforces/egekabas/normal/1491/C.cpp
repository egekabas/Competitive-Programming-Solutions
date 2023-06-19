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
ll n;
ll bef[5009];
ll a[5009];
void solve(){
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        bef[i] = 0;
    }
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        ll outside = max(0LL, a[i]-(n-1-i));
        if(i == n-1)
            outside = a[i]-1;
        ll subtract = min(bef[i], outside);
        bef[i] -= subtract;
        outside -= subtract;
        ans += outside;
        
        a[i] = min(a[i], n-1-i);
        for(ll j = i+a[i]; j > i+1; --j){
            bef[j]++;
            if(bef[i])
                --bef[i];
            else
                ++ans;
        }
        bef[i+1] += bef[i];
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--)
        solve();
}