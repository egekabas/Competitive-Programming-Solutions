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
typedef long double ld;
ll n, q, b;
ll a[2000009];
ll nxt[2000009];
ll pre[2000009];
ll calc(ll cur, ll beg){
    if(cur >= n+beg)
        return 0;
    else
        return 1+calc(nxt[cur], beg);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        a[n+i] = a[i];
    }
    for(ll i = 1; i <= 2*n; ++i)
        pre[i] = pre[i-1]+a[i];
    while(q--){
        cin >> b;
        ll j = 1;
        ll mini = 1e18;
        ll place = -1;
        for(ll i = 1; i <= 2*n; ++i){
            while(j <= 2*n && pre[j]-pre[i-1] <= b)
                ++j;
            if(i <= n && j-i <= mini){
                mini = j-i;
                place = i;
            }
            nxt[i] = j;
        }
        ll ans = 1e18;
        ll endi = nxt[place];
        for(ll i = place; i <= endi; ++i){
            if(i > n){
                i -= n;
                endi -= n;
            }
            //cout << i << " " << calc(i, i) << "\t";
            ans = min(ans, calc(i, i));
        }
        cout << ans << "\n";
    }
}