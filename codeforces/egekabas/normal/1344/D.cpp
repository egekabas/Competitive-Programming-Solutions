#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n, k;
ll a[100009];
ll b[100009];
ll findval(ll i, ll val){
    ld a1 = -3, b = 3, c = a[i]-1-val;
    ll x = (-b-sqrt(b*b-4*a1*c))/(2*a1);
    x = min(x, a[i]);
    return x;
}
ll check(ll val){
    ll ret = 0;
    for(ll i = 0; i < n; ++i)
        ret += findval(i, val);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll l = -4e18, r = 4e18;
    while(l < r){
        ll m = (l+r)/2 - (m < 0 && (l+r)%2);
        if(check(m) > k)
            l = m+1;
        else
            r = m;
    }
    
    ll curk = 0;
    vector<pll> v;
    for(ll i = 0; i < n; ++i){
        b[i] = findval(i, l);
        curk += b[i];
        v.pb({(b[i]+1)*(a[i]-(b[i]+1)*(b[i]+1))-b[i]*(a[i]-b[i]*b[i]), i});
    }
    sort(v.begin(), v.end(), greater<pll>());
    for(int i = 0; i < n; ++i)
        if(curk < k && b[v[i].ss] < a[v[i].ss]){
            ++b[v[i].ss];
            ++curk;
        }
    for(ll i = 0; i < n; ++i)
        cout << b[i] << ' ';

}