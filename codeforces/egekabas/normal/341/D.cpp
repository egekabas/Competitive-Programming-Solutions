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
ll n, m;
ll bit[4][1009][1009];
ll find(ll x, ll y){
    if(x % 2 == 0 && y % 2 == 0)
        return 0;
    if(x % 2 == 1 && y % 2 == 0)
        return 1;
    if(x % 2 == 0 && y % 2 == 1)
        return 2;
    if(x % 2 == 1 && y % 2 == 1)
        return 3;
}
void upd(ll x, ll y, ll val){
    ll par = find(x, y);
    for(ll i = x; i <= n; i += i&(-i))
        for(ll j = y; j <= n; j += j&(-j))
            bit[par][i][j] ^= val;    
}   
ll get(ll x, ll y){
    ll ret = 0;
    ll par = find(x, y);
    for(ll i = x; i > 0; i -= i&(-i))
        for(ll j = y; j > 0; j -= j&(-j))
            ret ^= bit[par][i][j];
    return ret;    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    while(m--){
        ll t, x0, y0, x1, y1, v;
        cin >> t;
        if(t == 1){
            cin >> x0 >> y0 >> x1 >> y1;
            ll res = get(x1, y1);
            res ^= get(x0 - 1, y1);
            res ^= get(x1, y0 - 1);
            res ^= get(x0 - 1, y0 - 1);
            cout << res << "\n";
        } 
        else{
            cin >> x0 >> y0 >> x1 >> y1 >> v;
            upd(x0, y0, v);
            upd(x0, y1 + 1, v);
            upd(x1 + 1, y0, v);
            upd(x1 + 1, y1 + 1, v);
        }
    }
}