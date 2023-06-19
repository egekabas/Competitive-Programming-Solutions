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
typedef long double ld;
ll n;
ll k1, k2, k3;
ll a[200009];
ll dp[200009][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    int tmp;
    for(int i = 0; i < k1; ++i){
        cin >> tmp;
        a[tmp] = 0;
    }
    for(int i = 0; i < k2; ++i){
        cin >> tmp;
        a[tmp] = 1;
    }
    for(int i = 0; i < k3; ++i){
        cin >> tmp;
        a[tmp] = 2;
    }
    for(int i = 1; i <= n; ++i){
        dp[i][0] = 1+dp[i-1][0];
        dp[i][1] = 1+min(dp[i-1][0], dp[i-1][1]);
        dp[i][2] = 1+min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
        --dp[i][a[i]];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
}