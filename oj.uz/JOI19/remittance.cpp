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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n;
ll a[1000009], b[1000009], dif[1000009];
ll check(ll x){
    ll val = x;
    for(ll i = n-1; i >= 0; --i){
        x = x*2-dif[i];
        if(x < 0)
            return -1e18;
        if(x > 1e18)
            return 1e18;
    }
    return x-val;
}
ll push[1000009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
        dif[i] = a[i]-b[i];
    }
    ll l = 0, r = 1e18;
    while(l < r){
        ll m = (l+r+1)/2;
        //cout << m << ' ' << check(m) << '\n';
        if(check(m) > 0)
            r = m-1;
        else
            l = m;
    }
    if(check(l)){
        cout << "No\n";
        return 0;
    }
    ll x = l;
    for(ll i = n-1; i >= 0; --i){
        push[i] = x;
        x = x*2-dif[i];
        if(x > 1e18)
            x = 1e18;
    }
    ll times = 3;
    while(times--)
    for(ll i = 0; i < n; ++i){
        ll add = min(a[i]/2, push[i]);
        push[i] -= add;
        a[i] -= add*2;
        a[(i+1)%n] += add;
    }
    for(ll i = 0; i < n; ++i)
        if(push[i]){
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
}
