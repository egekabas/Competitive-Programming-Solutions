#include <bits/stdc++.h>
using namespace std;
int t;
int dp[2009][2009];
int solve(string a,string b,int n,int m){
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++){
            if(j == 0)
                dp[i][j] = i;
            else if(i == 0)
                dp[i][j] = j;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    return dp[n][m];
}

int main(){
    int ans;
    cin >> t;
    string a, b;
    while(t--){
        cin >> a >> b;
        ans = solve(a, b, a.length(), b.length());
        cout << ans << endl;
    }
}
