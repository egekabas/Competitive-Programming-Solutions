#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef unsigned long long   ull;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll mod = 1e9+7;
ll n, k;
ll dp[300][300];
ll comb[300][300];
ll pw[90009];
ll pwl[90009];

ll func(ll x, ll fin){
    if(dp[x][fin] != 0)
        return dp[x][fin];
    if(x == 1){
        if(fin != 0)
            dp[x][fin] = pw[n-fin];
        else
            dp[x][fin] = (pw[n]-pwl[n]+mod)%mod;
        return dp[x][fin];
    }
    if(x == 0)
        return dp[x][fin] = 1;
    ll unfin = n-fin;
    for(ll i = 0; i <= fin; ++i){
        ll tmp = 1;
        tmp = tmp*comb[fin][i]%mod;
        tmp = tmp*pwl[fin-i]%mod*pw[unfin]%mod;
        tmp = tmp*(func(x-1, fin-i))%mod;
        dp[x][fin] = (dp[x][fin]+tmp)%mod;
    }
    dp[x][fin] -= pwl[n]*func(x-1, fin)%mod;
    if(dp[x][fin] < 0)
        dp[x][fin] += mod;
    return dp[x][fin];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> k;
    pw[0] = pwl[0] = 1;
    for(ll i = 1; i <= n*n; ++i){
        pw[i] = pw[i-1]*k%mod;
        pwl[i] = pwl[i-1]*(k-1)%mod;
    }
    for(ll i = 0; i <= n+3; ++i)
        comb[i][0] = comb[i][i] = 1;
    for(ll i = 0; i <= n+3; ++i)
        for(ll j = 1; j <= i-1; ++j){
            comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    /*for(int i = 0; i <= 2; ++i)
        for(int j = 0; j <= 2; ++j)
            cout << i << " " << j << " " << func(i, j) << "\n";
    */    
    cout << func(n, n) << "\n";
    
        
}