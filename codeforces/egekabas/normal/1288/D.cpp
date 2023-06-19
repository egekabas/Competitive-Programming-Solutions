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
int n, m;
pii dp[1<<10];
int a[300009][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    for(int bit = 0; bit < (1<<m); ++bit){
        int curmini;
        for(int i = 0; i < n; ++i){
            curmini = 1e9;
            for(int j = 0; j < m; ++j)
                if((bit&(1<<j)) > 0)
                    curmini = min(curmini, a[i][j]);
            if(curmini >= dp[bit].ff)
                dp[bit] = {curmini, i};
        }
    }
    pii ans;
    int val = 0;
    for(int bit = 0; bit < (1<<m); ++bit){
        int othbit = (1<<m)-1-bit;
        if(min(dp[bit].ff, dp[othbit].ff) >= val){
            val = min(dp[bit].ff, dp[othbit].ff);
            ans = {dp[bit].ss, dp[othbit].ss};
        }
    }
    cout << ans.ff+1 << " " << ans.ss+1 << "\n";
}