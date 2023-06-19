#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long y[505][505];
long long b[505][505];
long long l[505][505][2];
long long dp [505][505];
// 0 ==> b
// 1 ==> y
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    while(1){
        cin >> n >> m;
        if(n == m && m == 0)
            break;
        long long ye = 0;
        long long blo = 0;
        for(long long i = 1; i <= n; ++i)
            for(long long j = 1; j <= m; ++j){
                cin >> y[i][j];
                ye += y[i][j];
            }
        for(long long i = 1; i <= n; ++i)
            for(long long j = 1; j <= m; ++j){
                cin >> b[i][j];
                blo += b[i][j];
            }
        for(long long i = 1; i <= n; ++i)
            for(long long j = 1; j <= m; ++j){
                l[i][j][0] = l[i][j-1][0] + b[i][j];
                l[i][j][1] = l[i][j-1][1] + y[i][j];
            }
        long long tmp;
        for(long long i = n; i > 0; --i)
            dp[i][0] = l[i][m][0];
        for(long long i = n; i > 0; --i)
            for(long long j = 0; j <= m; ++j){
                long long tmp = l[i][j][1] + l[i][m][0] - l[i][j][0];
                long long maxi = 0;
                for(long long k = j; k <= m && i != n; ++k)
                    maxi = max(maxi, dp[i+1][k]);
                dp[i][j] = maxi + tmp;
            }
        long long ans = 0;
        for(long long j = 0; j <= m; ++j)
            ans = max(ans, dp[1][j]);
        cout << ans << endl ;
    }
}
