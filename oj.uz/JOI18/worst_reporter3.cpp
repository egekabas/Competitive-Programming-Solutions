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
ll n, q;
ll slow[500009];
pll rate[500009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i)
        cin >> slow[i];
    rate[0] = {1, 1};
    for(ll i = 1; i <= n; ++i){
        ll times = (slow[i]+rate[i-1].ff-1)/rate[i-1].ff;
        rate[i].ff = times*rate[i-1].ff;
        rate[i].ss = times*rate[i-1].ss;
    }
    while(q--){
        ll t, l, r;
        cin >> t >> l >> r;
        
        ll l1 = -1, r1 = n;
        while(l1 < r1){
            ll m = (l1+r1+1)/2;
            ll dist = t/rate[m].ss*rate[m].ff-m;
            if(dist >= l)
                l1 = m;
            else
                r1 = m-1;
        }
        ll l2 = 0, r2 = n+1;
        while(l2 < r2){
            ll m = (l2+r2)/2;
            ll dist = t/rate[m].ss*rate[m].ff-m;
            if(dist <= r)
                r2 = m;
            else
                l2 = m+1;
        }
        if(l1 == -1 || l2 == n+1)
            cout << "0\n";
        else
            cout << l1-l2+1 << '\n';
    }
}
