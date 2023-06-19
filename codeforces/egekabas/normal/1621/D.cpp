#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
int a[509][509];
void solve(){
    cin >> n;
    for(int i = 0; i < 2*n; ++i)
        for(int j = 0; j < 2*n; ++j)
            cin >> a[i][j];
    ll ans = 0;
    for(int i = n; i < 2*n; ++i)
        for(int j = n; j < 2*n; ++j)
            ans += a[i][j];
    ans += min({a[n][n-1], a[n-1][n], a[2*n-1][0], a[0][2*n-1], a[2*n-1][n-1], a[n-1][2*n-1], a[0][n], a[n][0]});
    cout << ans << '\n';
}
int main(){
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}