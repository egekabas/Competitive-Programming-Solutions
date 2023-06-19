#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
int h;
int modulo = (int)1e9 + 7;
int dp[200009];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, g;
    cin >> r >> g;
    int h = (int)sqrt(2.00*(r+g));
    while(h*(h+1) > 2*(r+g))
        --h;
    dp[0] = 1;
    for(int i = 1; i <= h; ++i){
        int sum = i*(i+1)/2;
        for(int j = r; j >= 0; --j){
            if( j > sum || sum - j > g )
                dp[j] = 0;
            else if(j - i >= 0)
                dp[j] = (dp[j] + dp[j-i]) % modulo;
        }
    }
    int ans = 0;
    for(int j = 0; j <= r; ++j){
        ans += dp[j];
        ans = ans % modulo;
    }
    cout << ans << endl;
}