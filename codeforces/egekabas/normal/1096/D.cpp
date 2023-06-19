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
ll n;
string s;
ll a[100009];
ll dp[100009][4];
char c[] = {'d', 'r', 'a', 'h'};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = n-1; i >= 0; --i)
        for(int j = 0; j < 4; ++j){
            if(s[i] == c[j]){
                if(j == 0)
                    dp[i][j] = dp[i+1][j]+a[i];
                else
                    dp[i][j] = min(dp[i+1][j]+a[i], dp[i+1][j-1]);
            }
            else
                dp[i][j] = dp[i+1][j];
        }
    cout << dp[0][3] << endl;
}