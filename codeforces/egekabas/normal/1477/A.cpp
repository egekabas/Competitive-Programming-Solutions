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
ll n, k;
ll a[200009];
void solve(){
    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ll go = 0;
    for(ll i = 1; i < n; ++i)
        go = __gcd(go, a[i]-a[i-1]);
    if(abs(a[0]-k) % go == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--)
        solve();

}