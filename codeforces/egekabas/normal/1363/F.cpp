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
int a[2009][30];
int b[2009][30];
int dp[2009][2009];
int n;
string s, t;
void create(string str, int a[2009][30]){
    for(int j = 0; j < 30; ++j)
        a[n][j] = 0;
    for(int i = n-1; i >= 0; --i)
        for(int j = 0; j < 30; ++j)
            a[i][j] = a[i+1][j] + (str[i]-'a' == j);
}
int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int test;
    cin >> test;
    while(test--){
        cin >> n >> s >> t;

        vector<int> alp(30);
        for(auto u : s)
            alp[int(u)-int('a')]++;
        for(auto u : t)
            alp[int(u)-int('a')]--;
        int okay = 1;
        for(int i = 0; i < 30; ++i)
            if(alp[i] != 0){
                cout << "-1\n";
                okay = 0;
                break;
            }
        if(okay == 0) continue;

        create(s, a);
        create(t, b);
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                dp[i][j] = 1e9;
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j){
                dp[i][j] = dp[i-1][j]+1;
                if(s[i-1] == t[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if(a[i][t[j-1]-'a'] > b[j][t[j-1]-'a'])
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        cout << dp[n][n] << '\n';
    }
}