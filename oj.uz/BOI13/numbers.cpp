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
ll dp[19];
ll calc(ll x){
    if(x == 0)
        return 1;
    if(x < 0)
        return 0;
    vector<ll> val;
 
    while(x > 0){
        val.pb(x%10);
        x /= 10;
    }
    reverse(all(val));
    ll addnew = 1;
    vector<vector<ll>> cur(11, vector<ll>(11)), nw(11, vector<ll>(11));
    for(ll i = 0; i < val.size(); ++i){
        if(i == 0){
            for(ll j = 1; j < val[i]; ++j)
                nw[10][j] = 1;
        }
        else{
            for(ll j = 0; j < 10; ++j)
                for(ll a = 0; a <= 10; ++a)
                    for(ll b = 0; b <= 10; ++b)
                        if(j != a && j != b)
                            nw[b][j] += cur[a][b];
            for(ll j = 0; j < val[i]; ++j)
                if(addnew && j != val[i-1] && (i < 2 || j != val[i-2]))
                    nw[val[i-1]][j] += 1;
            if(val[i] == val[i-1] || (i >= 2 && val[i] == val[i-2]))
                addnew = 0;
        }
        //for(ll a = 0; a <= 10; ++a)
        //    for(ll b = 0; b <= 10; ++b)
        //        cout << i << ' ' << a << ' ' << b << ' ' << nw[a][b] << '\n';  
        cur = nw;
        nw = vector<vector<ll>>(11, vector<ll>(11));
    }
    ll ans = dp[val.size()-1];
 
    for(ll a = 0; a <= 10; ++a)
        for(ll b = 0; b <= 10; ++b)
            ans += cur[a][b];
    ans += addnew;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    dp[0] = 1;
    dp[1] = 9;
    dp[2] = 9*9;
    for(ll i = 3; i <= 18; ++i)
        dp[i] = dp[i-1]*8;
    for(ll i = 1; i <= 18; ++i)
        dp[i] += dp[i-1];
 
    ll x, y;
    cin >> x >> y;
    cout << calc(y)-calc(x-1) << '\n';
}
