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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n;
vector<ll> a;
vector<ll> idx[100009];
ll dp[100009][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    while(n--){
        ll tmp;
        cin >> tmp;
        if(a.empty() || tmp != a.back())
            a.pb(tmp);
    }
    n = a.size();
    for(ll i = 0; i < n; ++i)
        idx[a[i]].pb(i);
    for(ll i = 0; i < n; ++i)
        dp[i][0] = dp[i][1] = 1e9+7; 
    dp[0][0] = 1;  
    for(ll i = 0; i < n-1; ++i){
        for(ll t = 0; t < 2; ++t){
            //cout << i << ' ' << t << ' ' << dp[i][t] << '\n';
            auto it = upper_bound(all(idx[a[i]]), i);
            if(it != idx[a[i]].end()){
                ll nxt = *it;
                ll val = dp[i][t]+nxt-i-1-t;
                //cout << i << ' ' << t << ' ' << nxt << ' ' << val << '\n';
                dp[nxt][0] = min(dp[nxt][0], val);
                dp[nxt-1][1] = min(dp[nxt-1][1], val);
            }
            if(t == 0)
                dp[i+1][0] = min(dp[i+1][0], dp[i][t]+1);
        }
    }
    cout << dp[n-1][0] << '\n';
}