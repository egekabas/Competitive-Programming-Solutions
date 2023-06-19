#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, ll>  pll;
typedef pair<ld, ld>  pld;
ll n, x;
ll a, b,c, ans;

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> x;

    ll tmp;
    while(n--){
        cin >> tmp;
        a = max((ll)0, a+tmp);
        b = max(a, b+tmp*x);
        c = max(b, c + tmp);
        ans = max(ans, c);
    }

    cout << ans << endl;
}