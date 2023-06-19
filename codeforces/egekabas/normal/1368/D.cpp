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
ll a[200009];
ll cnt[20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        for(ll j = 0; j < 20; ++j)
            if(a[i]&(1<<j))
                cnt[j]++;
    }
    ll ans = 0;
    while(n--){
        ll cur = 0;
        for(ll i = 0; i < 20; ++i)
            if(cnt[i]){
                --cnt[i];
                cur += (1<<i);
            }
        ans += cur*cur;
    }
    cout << ans << '\n';
}