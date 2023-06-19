#include <bits/stdc++.h>
#include "homecoming.h"
#define all(x) (x).begin(), (x).end()
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
long long solve(int N, int K, int *A, int *B){
    
 
    ll ans = 0;
 
    ll cost = 0;
    for(ll i = 0; i < K; ++i)
        cost += B[i];
    vector<ll> dp = {(ll)-1e18, A[0]-cost};
    for(int i = 1; i < N; ++i){
        vector<ll> nw(2, -1e18);
        cost -= B[i-1];
        if(i+K-1 < N)
            cost += B[i+K-1];
 
        nw[0] = max(dp[0], dp[1]);
        nw[1] = dp[0]+A[i]-cost;
        if(i+K-1 < N)
            nw[1] = max(nw[1], dp[1]+A[i]-B[i+K-1]);
        else
            nw[1] = max(nw[1], dp[1]+A[i]);
        nw[1] = max((ll)-1e18, nw[1]);
 
        dp = nw;
    }
    ans = max({ans, dp[0], dp[1]});
 
    cost = 0;
    for(ll i = 0; i < K; ++i)
        cost += B[i];
    dp = {0, (ll)-1e18};
    for(int i = 1; i < N; ++i){
        vector<ll> nw(2, -1e18);
        cost -= B[i-1];
        cost += B[(i+K-1)%N];
        
        nw[0] = max(dp[0], dp[1]);
        
        nw[1] = dp[0]+A[i]-cost;
        nw[1] = max(nw[1], dp[1]+A[i]-B[(i+K-1)%N]);
        
        nw[1] = max((ll)-1e18, nw[1]);
    
        dp = nw;
    }
    ans = max({ans, dp[0], dp[1]});
    return ans;
 
}
