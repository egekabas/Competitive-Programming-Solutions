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
int n, m;
int agre[2009];
int cost[2009];
int prof[4009];
int dp[4009][2009];
int bit[4009];
void upd(int idx, int val){
    for(;idx <= 4000; idx += idx&(-idx))
        bit[idx] = max(bit[idx], val);
}
int get(int idx){
    int ret = 0;
    for(;idx > 0; idx -= idx&(-idx))
        ret = max(bit[idx], ret);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> agre[i];
    for(int i = 0; i < n; ++i)
        cin >> cost[i];
    for(int i = 1; i <= n+m; ++i)
        cin >> prof[i];
    for(int i = 0; i <= 4000; ++i)
        for(int j = 0; j <= 2000; ++j)
            dp[i][j] = -1e9;
    reverse(agre, agre+n);
    reverse(cost, cost+n);
    for(int i = 0; i < n; ++i){
        for(int j = n; j >= 0; --j){
            if(j == 0)
                dp[agre[i]][j] = get(agre[i]);
            if(dp[agre[i]][j] == -1e9) continue;
            int curval = dp[agre[i]][j]-cost[i]+prof[agre[i]];
            dp[agre[i]][j+1] = max(dp[agre[i]][j+1], curval);
            int val = (j+1)/2;
            int ti;
            for(ti = agre[i]+1; val > 0; val /= 2, ++ti){
                curval += val*prof[ti];
                dp[ti][val] = max(dp[ti][val], curval);
            }
            upd(ti, curval);
        }
    }
    cout << get(4000) << '\n';
}