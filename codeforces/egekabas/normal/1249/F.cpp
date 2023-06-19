#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int n, k;
int w[209];
vector<int> g[209];
int dp[209][209];
int hold[209][209];
int f(int r, int d, int p){
    if(dp[r][d] != -1)
        return dp[r][d];
    int tmp = 0;
    if(d == 0){
        tmp = w[r];
        for(auto u : g[r]){
            if(u == p)
                continue;
            tmp += f(u, k, r);
        }
    }
    dp[r][d] = max(tmp, dp[r][d]);
    tmp = 0;
    if(hold[r][0] == -1){
        for(int i = 0; i <= k; ++i){
            hold[r][i] = 0;
            for(auto u : g[r]){
                if(u == p)
                    continue;
                hold[r][i] += f(u, i, r);
            }
        }
    }
    for(auto u : g[r]){
        if(u == p)
            continue;
        for(int i = max(d-1, 0); i <= k; ++i){
            int oth = max(k-(i+1), max(d-1, 0));
            if(oth < i)
                break;
            tmp = f(u, i, r) + hold[r][oth] - f(u, oth, r);
            
            dp[r][d] = max(dp[r][d], tmp);
        }    
    }
//    cout << r << " " << d << " " << dp[r][d] << "\n";
    return dp[r][d];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> w[i];
    for(int i = 1; i < n; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
    }
    for(int i = 0; i <= 200; ++i)
        for(int j = 0; j <= 200; ++j)
            dp[i][j] = hold[i][j] = -1;
    cout << f(1, 0, -1) << "\n";
}