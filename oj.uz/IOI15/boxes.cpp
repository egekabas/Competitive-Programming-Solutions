#include "boxes.h"
#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ll inf = 1e18;
int n, k, l;

void calcOneSide(int dist[], ll dp[]){
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[max(0, i-k)] + 2*dist[i-1];
    }
}

ll leftDp[10000009];
ll rightDp[10000009];

long long delivery(int N, int K, int L, int p[]) {
    n = N;
    k = K;
    l = L;

    sort(p, p+n);
    calcOneSide(p, leftDp);
    
    reverse(p, p+n);
    for(int i = 0; i < n; ++i){
        p[i] = l-p[i];
    }
    calcOneSide(p, rightDp);
    
    ll ans = inf;
    for(int i = 0; i <= n; ++i){
        ll simpAns = leftDp[i] + rightDp[n-i];
        ll compAns = leftDp[i] + l + rightDp[max(0, n-i-k)];
        ans = min({ans, simpAns, compAns});
    }

    return ans;
}
