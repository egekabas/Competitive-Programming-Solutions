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
int g[18];
unordered_map<int, ll> dp[1<<18];
ll mod = 998244353;
ll pw(ll x, ll y = mod-2){
    ll ret = 1;
    while(y){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x] += (1<<y);
        g[y] += (1<<x);
    }
    dp[0][(1<<n)-1] = 1;
    for(int a = 0; a < (1<<n)-1; ++a)
        for(auto u : dp[a]){
            int b = u.ff;
            ll cnt = u.ss;
            for(int i = 0; i < n; ++i)
                if(b&(1<<i)){
                    int newb = b&(((1<<(n-i))-1)<<i);
                    newb |= g[i];
                    int newa = a+(1<<i);
                    newb &= ((1<<n)-1-newa);
                    dp[newa][newb] += cnt;
                    dp[newa][newb] %= mod;
                }
        }
    cout << dp[(1<<n)-1][0]*m%mod*pw(2)%mod << '\n';
}