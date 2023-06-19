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
ll n, p;
ll a[1000009];
ll bit[2000009];
vector<ll> v;
void upd(ll idx){
    while(idx > 0){
        bit[idx]++;
        idx -= idx&(-idx);
    }
}
ll get(ll idx){
    ll ret = 0;
    while(idx <= v.size()+2){
        ret += bit[idx];
        idx += idx&(-idx);
    }
    return ret;
}
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i){
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &p);
    for(ll i = 0; i < n; ++i){
        a[i] -= p;
    }
    
    ll add = 0;
    for(ll i = 0; i < n; ++i){
        v.pb(-a[i]+add);    
        add -= a[i];
        v.pb(a[i]+add);    
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    ll ans = 0;
    add = 0;
    for(ll i = 0; i < n; ++i){
        if(a[i] >= 0){
            ++ans;
        }
        ans += get(1+lower_bound(v.begin(), v.end(), -a[i]+add)-v.begin());
        add -= a[i];
        upd(1+lower_bound(v.begin(), v.end(), a[i]+add)-v.begin());
    }
    printf("%lld", ans);
}
