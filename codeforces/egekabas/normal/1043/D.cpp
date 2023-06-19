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
ll a[15][100009];
pll lr[100009];
ll vis[100009];
ll n, m;
ll ret(ll v){
    vis[v] = 1;
    ll tot = 1;
    if( lr[v].ff > 0 && vis[lr[v].ff] == 0 ){
        tot += ret(lr[v].ff);
    }
    if( lr[v].ss > 0 && vis[lr[v].ss] == 0 ){
        tot += ret(lr[v].ss);
    }
    return tot;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(j == 0){
                lr[a[i][j]].ff = -1;
                continue;
            }
            if( lr[a[i][j]].ff == 0 ){
                lr[a[i][j]].ff = a[i][j-1];
            }
            else if(lr[a[i][j]].ff != a[i][j-1]){
                lr[a[i][j]].ff = -1;
            } 
        }
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j){
            if(j == n-1){
                lr[a[i][j]].ss = -1;
                continue;
            }
            if( lr[a[i][j]].ss == 0){
                lr[a[i][j]].ss = a[i][j+1];
            }
            else if(lr[a[i][j]].ss != a[i][j+1]){
                lr[a[i][j]].ss = -1;
            }
        }
    for(int i = 0; i < m; ++i)
        lr[a[i][0]].ff = lr[a[i][n-1]].ss = -1;   
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        //cout << i << " " << lr[i].ff << " " << lr[i].ss << endl;
        if(vis[i] == 0){
            ll z = ret(i);
            ans += z*(z+1)/2;
        }
    }
    cout << ans << endl;
}