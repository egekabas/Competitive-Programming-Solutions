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
ll a[2009][2009];
ll rd[2009][2009];
ll rr[2009][2009];
ll cl[2009][2009];
ll cu[2009][2009];
ll mod = 1e9+7;
inline ll check(ll a){
    a %= mod;
    if(a < 0)
        a += mod;
    return a;
}
void updcl(ll x, ll y, ll val){
    while(y <= m){
        cl[x][y] += val;
        cl[x][y] = check(cl[x][y]);
        y += y&(-y);
    }
}
void updateleft(ll x, ll y1, ll y2, ll val){
    if(y1 > y2)
        return;
    updcl(x, y1, val);
    updcl(x, y2+1, -val);
}
void updcu(ll x, ll y, ll val){
    while(x <= n){
        cu[x][y] += val;
        cu[x][y] = check(cu[x][y]);
        x += x&(-x);
    }
}
void updateup(ll x1, ll x2, ll y, ll val){
    if(x1 > x2)
        return;
    updcu(x1, y, val);
    updcu(x2+1, y, -val);
}
ll getcl(ll x, ll y){
    ll ret = 0;
    while(y > 0){
        ret += cl[x][y];
        ret = check(ret);
        y -= y&(-y);
    }
    return ret;
}
ll getcu(ll x, ll y){
    ll ret = 0;
    while(x > 0){
        ret += cu[x][y];
        ret = check(ret);
        x -= x&(-x);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    char c;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j){
            cin >> c;
            if(c == 'R')
                a[i][j] = 1;
        }
    for(ll i = n; i > 0; --i)
        for(ll j = m; j > 0; --j){
            rr[i][j] = rr[i][j+1]+a[i][j+1];
            rr[i][j] = check(rr[i][j]);
            rd[i][j] = rd[i+1][j] + a[i+1][j];
            rd[i][j] = check(rd[i][j]);
        }
    updateleft(1, 1, 1, 1);
    updateup(1, 1, 1, 1);
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j){
            updateleft(i, j+1, m-rr[i][j], getcu(i, j));
            updateup(i+1, n-rd[i][j], j, getcl(i, j));
        }
/*    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            cout << getcl(i, j) << " ";
        }
        cout << "\n";
    }*/
    if(n == 1 && m == 1)
        cout << "1\n";
    else
        cout << (getcl(n, m) + getcu(n, m))%mod << "\n";
}