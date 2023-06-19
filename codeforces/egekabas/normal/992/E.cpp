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
ll bit[200009];

ll n, q;
void upd(ll idx, ll val){
    for(;idx <= n; idx += idx&(-idx))
        bit[idx] += val;
}
ll get(ll idx){
    ll ret = 0;
    for(;idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}

ll a[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        upd(i, a[i]);
    }
    while(q--){
        ll x, y;
        cin >> x >> y;
        upd(x, y-a[x]);
        a[x] = y;
        ll max = 1e18;
        ll ans = -1;
        while(max >= a[1] && max){
            ll l = 1, r = n;
            while(l < r){
                ll m = (l+r+1)/2;
                if(get(m-1) > max)
                    r = m-1;
                else
                    l = m;
            }
            if(a[l] == get(l-1)){
                ans = l;
                break;
            }
            max = get(l-1)/2;
        }
        if(a[1] == 0)
            ans = 1;
        cout << ans << '\n';
    }

}