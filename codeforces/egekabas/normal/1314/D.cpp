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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, k;
int dist[100][100];
vector<int> randdist;
int dp[100][100];
int f(ll x, ll k){
    if(dp[x][k] != -1)
        return dp[x][k];
    if(k == 0 && x == 0)
        return dp[x][k] = 0;
    if(k == 0 && x != 0)
        return dp[x][k] = 1e9;
    dp[x][k] = 1e9;
    for(int i = 0; i < n; ++i)
        if(randdist[i] != randdist[x])
            dp[x][k] = min(dp[x][k], dist[x][i] + f(i, k-1));
    return dp[x][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    srand(time(NULL));

    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dist[i][j] = 1e9;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> dist[i][j];    

    int iterations = 10000;
    int ans = 1e9;
    while(iterations--){
        randdist.clear();
        for(ll i = 0; i < n/2; ++i){
            randdist.pb(1);
            randdist.pb(0);
        }
        if(n%2)randdist.pb(rand()%2);
        random_shuffle(randdist.begin(), randdist.end());
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= k; ++j)
                dp[i][j] = -1;
        ans = min(ans, f(0, k));
    }
    cout << ans << '\n';
}