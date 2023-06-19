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
int n, a[1000009][2];
int dp[1000009][2][2];
void calc(int i, int j){
    if(a[i][j] >= a[i-1][0]){
        dp[i][j][0] = min(dp[i][j][0], dp[i-1][0][0]+j);
        dp[i][j][1] = max(dp[i][j][1], dp[i-1][0][1]+j);
    }
    if(a[i][j] >= a[i-1][1]){
        dp[i][j][0] = min(dp[i][j][0], dp[i-1][1][0]+j);
        dp[i][j][1] = max(dp[i][j][1], dp[i-1][1][1]+j);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; ++i)
        cin >> a[i][0];
    for(int i = 0; i < n; ++i)
        cin >> a[i][1];
    for(int i = 0; i < n; ++i){
        dp[i][0][0] = 1e9;
        dp[i][0][1] = -1e9;
        dp[i][1][0] = 1e9;
        dp[i][1][1] = -1e9;
    }   
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][1][0] = 1;
    dp[0][1][1] = 1;
    for(int i = 1; i < n; ++i){
        calc(i, 0);
        calc(i, 1);
    }
    vector<int> ans;
    int pos, cur;
    if(dp[n-1][0][0] <= n/2 && n/2 <= dp[n-1][0][1])
        pos = cur = 0;
    else if(dp[n-1][1][0] <= n/2 && n/2 <= dp[n-1][1][1])
        pos = cur = 1;
    else{
        cout << -1;
        return 0;
    }
    ans.pb(pos);
    for(int i = n-2; i >= 0; --i){
        if(a[i][0] <= a[i+1][pos] && dp[i][0][0] <= n/2-cur && n/2-cur <= dp[i][0][1])
            pos = 0;
        else
            pos = 1;
        ans.pb(pos);
        cur += pos;
    }
    reverse(ans.begin(), ans.end());
    for(auto u : ans){
        if(u)
            cout << 'B';
        else
            cout << 'A';
    }
}
