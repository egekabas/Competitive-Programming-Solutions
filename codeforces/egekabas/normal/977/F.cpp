#include <bits/stdc++.h>
using namespace std;
map <int, int> dp;
int ar[200005];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i )
        cin >> ar[i];
    int big = 0;
    int ind = 0;
    for(int i = 0; i < n; ++i){
        dp[ar[i]] = max(dp[ar[i] - 1] + 1, dp[ar[i]]);
        if(dp[ar[i]] >= big ){
            ind = ar[i];
            big = dp[ar[i]];
        }
    }
    int count = ind - big + 1;
    cout << big << endl;
    for(int i = 0; i < n; ++i){
        if(ar[i] == count){
            ++count;
            cout << i + 1 << " ";
        }
        if(count > ind)
            return 0;

    }


}