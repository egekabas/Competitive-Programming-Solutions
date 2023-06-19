#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll s, x;
ll sc, xc;
ll dp[10000][10];
// tuttuu int deeri gelme yolu
// ilk boyut array renki
// ikinci boyut kalan
void calc(ll dep, ll art){
    ll sum = 2*art+sc;
    if(xc == 0){
        dp[dep][art] += dp[dep-1][sum];
        if(sum-2 >= 0)
            dp[dep][art] += dp[dep-1][sum-2];
    }
    if(xc == 1){
        if(sum-1 >= 0)
            dp[dep][art] += 2*dp[dep-1][sum-1];
    }
}

int main(){
    cin >> s >> x;
    ll crit = 0;
    if(s == x)
        crit = -2;
    sc = s % 2; xc = x % 2;
    s /= 2; x /= 2;
    if(sc == 1 && xc == 1){
        dp[0][0] += 2;
    }    
    if(sc == 0 && xc == 0){
        dp[0][0] += 1;
        dp[0][1] += 1;
    }
    ll i = 0;
    while(s > 0 || x > 0){
        ++i;
        sc = s % 2; xc = x % 2;
        s /= 2; x /= 2;
        calc(i, 0);
        calc(i, 1);
    }
    //for(int j = 0; j <= i; ++j)
    //    cout << dp[j][0] << " " << dp[j][1] << endl;
    cout << dp[i][0]+crit << endl;
}