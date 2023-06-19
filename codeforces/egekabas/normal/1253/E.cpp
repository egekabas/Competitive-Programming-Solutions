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
ll n, m;
pll a[100];
ll bit[400009];
void update(ll idx, ll val){
    while(idx > 0){
        bit[idx] = min(bit[idx], val);
        idx -= idx&(-idx);
    }
}
ll get(ll idx){
    if(idx == 0) return 0;
    ll ret = 1e18;
    while(idx <= 2*m){
        ret = min(ret, bit[idx]);
        idx += idx&(-idx);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i].ff >> a[i].ss;
    for(ll i = 1; i <= 2*m; ++i)
        bit[i] = 1e18;
    for(ll i = 1; i <= m; ++i){
        for(ll j = 0; j < n; ++j){
            if(a[j].ff < i)
                continue;
            ll need = a[j].ff-a[j].ss-i;
            need = max((ll)0, need);
            update(a[j].ff+a[j].ss+need, get(i-1)+need);
            update(i, get(i-1)+need);
        }
        if(i != 1){
            update(i, get(i-1)+1);
        }
    }
    cout << get(m) << "\n";
}