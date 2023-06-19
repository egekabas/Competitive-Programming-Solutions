#include <bits/stdc++.h>
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
int dp[10009][10009];
int aft[10009];
string s, t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> s >> t;
    for(int i = 0; i < s.size(); ++i){
        aft[i] = -1;
        int bal = 0;
        for(int j = i; j < s.size(); ++j){
            bal += (s[j] != '.') - (s[j] == '.');
            if(bal < 0) break;
            if(bal == 0){
                aft[i] = j+1;
                break;
            }
        }
    }
    for(int i = 0; i <= s.size(); ++i)
        for(int j = 0; j <= t.size(); ++j)
            dp[i][j] = 1e9;
    dp[0][0] = 0; 
    for(int i = 0; i < s.size(); ++i)
        for(int j = 0; j <= t.size(); ++j){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            if(j != t.size() && s[i] == t[j])
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            if(aft[i] != -1)
                dp[aft[i]][j] = min(dp[aft[i]][j], dp[i][j]);
        }
    cout << dp[s.size()][t.size()] << '\n';
}