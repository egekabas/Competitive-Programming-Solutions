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
ll n, k;
vector<ll> f[3009];
ll sum[3009];
ll ans = 0;
vector<ll> beg;
void calc(ll l, ll r, const vector<ll> & dp){
    if(l == r){
        ans = max(ans, dp[k]);
        ll cur = 0;
        for(ll i = 0; i < k && i < (ll)f[l].size(); ++i){
            cur += f[l][i];
            ans = max(ans, cur+dp[k-i-1]);
        }
        return;
    }
    vector<ll> cur = dp;
    ll m = (l+r)/2;
    for(ll i = m+1; i <= r; ++i)
        for(ll j = k; j >= (ll)f[i].size(); --j)
            cur[j] = max(cur[j], cur[j-(ll)f[i].size()]+sum[i]);

    calc(l, m, cur);
    cur = dp;
    for(ll i = l; i <= m; ++i)
        for(ll j = k; j >= (ll)f[i].size(); --j)
            cur[j] = max(cur[j], cur[j-(ll)f[i].size()]+sum[i]);

    calc(m+1, r, cur);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i){
        ll t;
        cin >> t;
        f[i].resize(t);
        for(ll j = 0; j < t; ++j){
            cin >> f[i][j];
            sum[i] += f[i][j];
        }
    }
    beg = vector<ll>(k+1, 0);
    calc(0, n-1, beg);
    cout << ans << '\n';
}