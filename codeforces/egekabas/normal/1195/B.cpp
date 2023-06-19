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
ll n, k;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> k;
    ll cur = 0;
    ll add = 1;
    ll ans = 0;
    for(int i = 1; i <= n;){
        if(cur > k){
            i += cur-k;
            ans += cur-k;
            cur = k;
        }
        else{
            cur += add;
            ++add;
            ++i;
        }
    }
    cout << ans << endl;
}