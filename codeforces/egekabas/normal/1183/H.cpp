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
ll n, k, ans;
string s;
ll dp[109][109];
ll f(ll idx, ll size){
    if(idx < 0 && size == 0) return 1;    
    if(idx < 0) return 0;
    if(idx == 0 && size == 1) return dp[idx][size] = 1;
    if(size == 0) return 1;
    if(size > idx+1) return 0;
    if(dp[idx][size] != 0) return dp[idx][size];
    
    dp[idx][size] = f(idx-1, size)+f(idx-1, size-1);
    for(ll i = idx-1; i >= 0; --i){
        if(s[i] == s[idx]){
            dp[idx][size] -= f(i-1, size-1);
            break;
        } 
    }
    //cout << idx+1 << " " << size << " " <<  dp[idx][size] << endl;
    return dp[idx][size];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> k >> s;
    ll ans = 0;
    for(ll curs = n; curs >= 0; --curs){
        ll tmp = f(n-1, curs);
        //cout << curs << " " << tmp << endl;
        if(tmp >= k){
            ans += k*(n-curs);
            cout << ans << endl;
            return 0;
        }
        k -= tmp;
        ans += tmp*(n-curs);
    }
    if(k > 0)
        cout << "-1\n";
    else
        cout << ans << endl; 
}