#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        ll x, y, k;
        cin >> x >> y >> k;
        ll stcnt = k+y*k;
        ll ans = (stcnt-1+(x-1-1))/(x-1)+k;
        cout << ans << '\n';
    }
}