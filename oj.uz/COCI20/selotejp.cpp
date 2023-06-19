#include <bits/stdc++.h>
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
int n, m;
int a[1000][10];
int dp[1000][(1<<10)];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j){
            a[i][j] = (s[j] == '#');
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < (1<<m); ++j)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    int ans = 1e9;
    for(int i = 0; i < n; ++i)
        for(int bit = 0; bit < (1<<m); ++bit){
            int bad = 0;
            for(int j = 0; j < m; ++j)
                if( (bit&(1<<j)) && (a[i][j] == 0) )
                    bad = 1;
            if(bad){
                continue;
            }
            for(int j = 0; j < m; ++j)
                if((bit&(1<<j)) == 0)
                    dp[i][bit+(1<<j)] = min(dp[i][bit+(1<<j)], dp[i][bit]+1);
            
            for(int j = 0; j < m; ++j){
                if((bit&(1<<j)) || a[i][j] == 0) continue;
                if(j == 0 || (bit&(1<<(j-1))) || a[i][j-1] == 0)
                    ++dp[i][bit];
            }
            
            /*cout << i << ' ';
            for(int j = 0; j < m; ++j)
                cout << ((bit&(1<<j)) > 0);
            cout << '\n' << dp[i][bit] << '\n';*/
            
            if(i == n-1){
                ans = min(ans, dp[i][bit]);
            }
            else{
                for(int newbit = bit; ;newbit = (bit&(newbit-1))){
                    dp[i+1][newbit] = min(dp[i][bit], dp[i+1][newbit]);
                    if(!newbit) break;
                }
            }
        }
    cout << ans << '\n';
}
