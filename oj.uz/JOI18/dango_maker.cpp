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
int n, m;
int a[3009][3009];
int cl(int x, int y){
    return(x >= 0 && y >= 0 && a[x][y] == 1 && a[x][y+1] == 2 && a[x][y+2] == 3);
}
int cd(int x, int y){
    return(x >= 0 && y >= 0 && a[x][y] == 1 && a[x+1][y] == 2 && a[x+2][y] == 3);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < m; ++j){
            if(s[j] == 'R')
                a[i][j] = 1;
            else if(s[j] == 'G')
                a[i][j] = 2;
            else
                a[i][j] = 3;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(a[i][j] != 2) continue;
            vector<pii> v;
            for(int red = 0; i+red < n && red <= j; ++red){
                if(a[i+red][j-red] != 2) break;
                v.pb({(i+red), (j-red)});
            }
            vector<pii> dp(v.size()+5);
            for(int i = v.size()-1; i >= 0; --i){
                dp[i].ff = max(dp[i+1].ff, dp[i+2].ss)+cl(v[i].ff, v[i].ss-1);
                dp[i].ss = max(dp[i+1].ss, dp[i+2].ff)+cd(v[i].ff-1, v[i].ss);
            }
            ans += max(dp[0].ff, dp[0].ss);
            for(auto u : v)
                a[u.ff][u.ss] = 0;
        }
    cout << ans << '\n';
}
