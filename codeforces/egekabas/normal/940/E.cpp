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
ll n, c;
ll a[100009];
ll sum[100009];
ll dp[100009];
set<pll> s;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> c;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        if(i == 0) sum[i] = a[i];
        else sum[i] = sum[i-1] + a[i];
    }
    for(ll i = 0; i < n; ++i){
        if(i >= c){
            s.erase({a[i-c], i-c});
            s.insert({a[i], i});
            dp[i] = a[i] + dp[i-1];
            dp[i] = min(dp[i], dp[i-c]+sum[i]-sum[i-c] - (*(s.begin())).ff);
        }
        else{
            s.insert({a[i], i});
            dp[i] = sum[i];
            if(i == c-1) dp[i] -= (*(s.begin())).ff;
        }
    }
    cout << dp[n-1] << endl;
}