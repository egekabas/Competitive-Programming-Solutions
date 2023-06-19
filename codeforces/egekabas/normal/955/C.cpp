#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
ll q, l, r;
vector<ll> v1;
vector<ll> v2;
ll bip(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y % 2)
            ret *= x;
        y /= 2;
        x *= x;
    }
    return ret;
}
ll sq(ll x){
    ll l = 0;
    ll r = 1e9+1;
    while(l < r-1){
        ll m = (l+r)/2;
        if(m*m > x)
            r = m;
        else
            l = m;
    }
    return l;
}
int main(){
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    for(ll i = 3; i < 64; i += 2){
        ll cur;
        for(ll j = 2; (cur = bip(j, i)) <= 1e18 && cur > 0; ++j)
            v1.push_back(cur);
    }
    sort(v1.begin(), v1.end());
    v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
    for(auto u : v1)
        if(sq(u)*sq(u) != u)
            v2.push_back(u);
    cin >> q;
    while(q--){
        cin >> l >> r;
        ll ans = sq(r)-sq(l-1);
        ans += upper_bound(v2.begin(), v2.end(), r)-
        lower_bound(v2.begin(), v2.end(), l);
        cout << ans << endl;
    }
        
}