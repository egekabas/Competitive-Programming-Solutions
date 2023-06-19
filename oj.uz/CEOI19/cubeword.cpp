#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
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
const ll mod = 998244353;
ll ans = 0;
vector<string> a[11];
const ll n = 62;
ll cnt[70][70];
map<char, ll> mpp;
ll dp[70][70][70];
    
ll ft[5] = {1, 1, 2, 6, 24};
ll calc(vector<int> v){
    int ans = ft[4];
    int cur = 0;
    for(int i = 0; i < v.size(); ++i){
        if(i != 0 && v[i] == v[i-1])
            ++cur;
        else{
            ans /= ft[cur];
            cur = 1;
        }
    }
    ans /= ft[cur];
    return ans;
}
int gt[2][2][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        a[s.size()-3].pb(s);
        reverse(all(s));
        a[s.size()-3].pb(s);
 
    }
    int curcnt = 0;
    for(char i = 'a'; i <= 'z'; ++i)
        mpp[i] = curcnt++;
    for(char i = 'A'; i <= 'Z'; ++i)
        mpp[i] = curcnt++;
    for(char i = '0'; i <= '9'; ++i)
        mpp[i] = curcnt++;
    
    for(int i = 0; i < 4; ++i)
        for(int j = i; j < 4; ++j)
            for(int k = j; k < 4; ++k)
                for(int y = k; y < 4; ++y)
                    gt[j==i][k==j][y==k] = calc({i, j, k, y});
 
    for(int cur = 0; cur < 8; ++cur){
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cnt[i][j] = 0;
        sort(all(a[cur]));
        for(int i = 0; i < a[cur].size(); ++i){
            if(i == 0 || a[cur][i] != a[cur][i-1])
                cnt[mpp[a[cur][i][0]]][mpp[a[cur][i].back()]]++;
        }
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                for(int k = j; k < n; ++k){
                    dp[i][j][k] = 0;
                    for(int mid = 0; mid < n; ++mid){
                        dp[i][j][k] += cnt[i][mid]*cnt[j][mid]%mod*cnt[k][mid]%mod;
                        if(dp[i][j][k] >= mod)
                            dp[i][j][k] -= mod;
                    }
                }
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                for(int k = j; k < n; ++k)
                    for(int y = k; y < n; ++y){
                        ans += gt[j==i][k==j][y==k]*dp[i][j][k]%mod*dp[i][j][y]%mod*dp[j][k][y]%mod*dp[i][k][y]%mod;
                        if(ans >= mod)
                            ans -= mod;
                    }
    }
    cout << ans << '\n';
    //cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
}
