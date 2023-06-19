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
ll n;
ll sx, sy;
pll a[200009];
ll cnt(ll x, ll y){
    if(x < 0 || y < 0)
        return -1;
    ll ret = 0;
    for(ll i = 0; i < n; ++i){
        if(abs(a[i].ff-sx)+abs(a[i].ss-sy) == 
        abs(x-sx)+abs(y-sy)+abs(a[i].ff-x)+abs(a[i].ss-y))
            ++ret;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> sx >> sy;
    for(ll i = 0; i < n; ++i)
        cin >> a[i].ff >> a[i].ss;
    
    ll x = -1, y = -1;
    ll maxi = -1;

    if(cnt(sx+1, sy) >= maxi){
        x = sx+1;
        y = sy;
        maxi = cnt(sx+1, sy);
    }
    if(cnt(sx, sy+1) >= maxi){
        x = sx;
        y = sy+1;
        maxi = cnt(sx, sy+1);
    }
    if(cnt(sx-1, sy) >= maxi){
        x = sx-1;
        y = sy;
        maxi = cnt(sx-1, sy);
    }
    if(cnt(sx, sy-1) >= maxi){
        x = sx;
        y = sy-1;
        maxi = cnt(sx, sy-1);
    }
    cout << maxi << "\n";
    cout << x << " " << y << "\n";


}