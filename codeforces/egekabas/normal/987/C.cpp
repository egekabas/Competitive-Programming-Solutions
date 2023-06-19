#include <bits/stdc++.h>
using namespace std;
const long long Inf = (long long) 1e9;
const long long  InfL = (long long)  1e18;
long long n;
long long font[3009];
long long cost[3009];
long long dp[3009][3];
int main(){
    cin >> n;
    for(long long i = 0; i < n; ++i)
        cin >> font[i];
    for(long long i = 0; i < n; ++i)
        cin >> cost[i];

    for(long long i = 0; i < n; ++i){
        dp[i][0] = cost[i];
        long long mini = InfL;
        for(long long k = 0; k < i; ++k){
            if(font[i] > font[k])
                mini = min(mini, dp[k][0] + cost[i]);
        }
        dp[i][1] = mini;
        mini = InfL;
        for(long long k = 0; k < i; ++k){
            if(font[i] > font[k])
                mini = min(mini, dp[k][1] + cost[i]);
        }
        dp[i][2] = mini;
        mini = InfL;
    }

    long long mini = InfL;
    for(long long i = 0; i < n; ++i){
        if(dp[i][2] != 0)
            mini = min(mini, dp[i][2]);
    }
    if(mini == InfL)
        cout << -1;
    else
        cout << mini;
}