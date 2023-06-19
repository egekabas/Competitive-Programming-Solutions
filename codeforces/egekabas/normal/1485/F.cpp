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
const ll mod = 1e9+7;
ll b[200009];
ll n;
void solve(){
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> b[i];
    map<ll, ll> dp;
    ll sum = 1;
    ll add = 0;
    dp[0] = 1;
    for(ll i = 0; i < n; ++i){
        ll eqval = sum-dp[-add];
        eqval = (eqval+mod)%mod;

        add += b[i];

        sum += eqval;
        sum %= mod;

        dp[b[i]-add] += eqval;
        dp[b[i]-add] %= mod;
    }    
    cout << sum << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}