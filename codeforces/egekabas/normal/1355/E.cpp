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
ll n, a, r, m;
ll h[100009];
ll sum[100009];
ll cost(ll val){
    ll id = upper_bound(h, h+n, val)-h;
    ll below = id*val-sum[id-1];
    ll above = sum[n-1]-sum[id-1]-val*(n-id);
    ll ret = 0;
    if(m < a+r){
        ll mini = min(above, below);
        ret += mini*m;
        above -= mini;
        below -= mini;
    }
    ret += above*r + below*a;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> a >> r >> m;
    for(ll i = 0; i < n; ++i)
        cin >> h[i];
    sort(h, h+n);
    sum[0] = h[0];
    for(ll i = 1; i < n; ++i)
        sum[i] = sum[i-1]+h[i];
    
    ll l = 0, r = 1e9;
    while(l < r){
        ll m = (l+r)/2;
        if(cost(m+1) < cost(m)){
            l = m+1;
        }
        else{
            r = m;
        }
    }
    cout << cost(l) << '\n';
}