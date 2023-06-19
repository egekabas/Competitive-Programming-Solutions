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
ll mod = 1e9+7;
int n, t;
ll dp[209][209][209][3][2];
ll fact[209];
ll f(int a, int b, int ab, int cur, int done){
    if(a < 0 || b < 0 || ab < 0)return 0;
    if(cur == 0 && done == 1)
        return dp[a][b][ab][cur][done] = f(a, b, ab, cur, 0);
    if(dp[a][b][ab][cur][done] != -1)
        return dp[a][b][ab][cur][done];
    if(a == 0){
        if(cur == 2 && done == 0)
            return dp[a][b][ab][cur][done] = 0;
        return dp[a][b][ab][cur][done] = fact[b];
    }
    dp[a][b][ab][cur][done] = 0;
    int c = a-ab+b-ab;
    dp[a][b][ab][cur][done] += ab*f(b-1, c, b-ab, (cur+1)%3, 1)%mod;
    if(!(done == 0 && cur == 2))
        dp[a][b][ab][cur][done] += (a-ab)*f(b+1, c, b-ab+1, (cur+1)%3, done)%mod;
    dp[a][b][ab][cur][done] %= mod;
    return dp[a][b][ab][cur][done];    
}
vector<int> clean(vector<int> v){
    sort(all(v));
    vector<int> ret;
    for(int i = 0; i < v.size(); ++i){
        if(i == v.size()-1 || v[i] != v[i+1])
            ret.pb(v[i]);
        else
            ++i;
    }
    return ret;
}
void solve(){
    vector<int> a(2*n), b(2*n), c(2*n);
    for(int i = 0; i < 2*n; ++i)
        cin >> a[i];
    for(int i = 0; i < 2*n; ++i)
        cin >> b[i];
    for(int i = 0; i < 2*n; ++i)
        cin >> c[i];
    a = clean(a);
    b = clean(b);
    int abcon = 0;
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b.size(); ++j)
            if(a[i] == b[j])
                abcon++;
    cout << f(a.size(), b.size(), abcon, 0, 0) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> t;
    for(int i = 0; i <= 200; ++i)
        for(int j = 0; j <= 200; ++j)
            for(int k = 0; k <= 200; ++k){
                dp[i][j][k][0][0] = dp[i][j][k][1][0] = dp[i][j][k][2][0] = -1;
                dp[i][j][k][0][1] = dp[i][j][k][1][1] = dp[i][j][k][2][1] = -1;
            }
    fact[0] = 1;
    for(ll i = 1; i <= 200; ++i)
        fact[i] = i*fact[i-1]%mod;
    while(t--){
        solve();
    }    
}
