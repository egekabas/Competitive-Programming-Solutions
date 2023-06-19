#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll a[200009];
ll n ,t;

int main(){
    cin >> n >> t;
    ll mn = (ll)1e9;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    ll ans = 0;
    while (t >= mn){
        ll sum = 0;
        ll cnt = 0;
        for(ll i = 0; i < n; ++i){
            if(t >= a[i]){
                t -= a[i];
                ++cnt;
                sum += a[i];
                ++ans;
            }
        }
        ans += (t/sum)*cnt;
        t %= sum;
    }
    cout << ans << endl;
}