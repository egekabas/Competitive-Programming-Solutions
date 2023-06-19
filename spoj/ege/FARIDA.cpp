#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long a[10000];
long long dp[10000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
        freopen("../IO/in.txt", "r", stdin);
        freopen("../IO/out.txt", "w", stdout);
    #endif
    cin >> t;
    for(long long j = 1; j <= t; ++j ){
        cin >> n;
        if(n == 0){
            cout << "Case  " << j << ": " << 0 << endl;
            continue;
        }
        for(long long i = 0; i < n; ++i)
            cin >> a[i];
        dp[0] = a[0];
        dp[1] = a[1];
        for(long long i = 2; i < n; ++i){
            dp[i] = max(dp[i-2], dp[i-3]);
            dp[i] += a[i];
        }
        cout << "Case  " << j << ": " << max(dp[n-1], dp[n-2]) << endl;
    }
}
