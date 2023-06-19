#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        ll a, b, n;
        cin >> a >> b >> n;
        if(b > a) swap(a, b);
        ll ans = 0;
        while(1){
            if(a > n){
                cout << ans << '\n';
                break;
            }
            if(a + b > n){
                cout << ans+1 << '\n';
                break;    
            }
            b += a;
            a += b;
            ans += 2;   
        }
    }
}