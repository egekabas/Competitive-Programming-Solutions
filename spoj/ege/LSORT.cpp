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
ll n;
ll pos[2009];
ll dp[2009][2009];
ll bit[2009];
void upd(ll idx, ll val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx&(-idx);
    }
}
ll get(ll idx){
    ll ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= idx&(-idx);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 1; i <= n; ++i){
            ll tmp;
            cin >> tmp;
            pos[tmp] = i;
        }
        for(ll i = 1; i <= n; ++i)
            bit[i] = 0;
        for(ll i = 1; i <= n; ++i){
            dp[i][i] = pos[i];
        }
        for(ll j = 1; j <= n-1; ++j){
            for(ll i = 1; i <= n; ++i)
                bit[i] = 0;
            for(ll i = j+2; i <= n; ++i)
                upd(pos[i], 1);
            for(ll i = 1; i + j <= n; ++i){
                dp[i][i+j] = min(dp[i+1][i+j]+(get(pos[i])+1)*(j+1),
                dp[i][i+j-1]+(get(pos[i+j])+1)*(j+1));
                upd(pos[i], 1);
                if(i+j+1 <= n)
                    upd(pos[i+j+1], -1);
            }
        }
        cout << dp[1][n] << "\n";
    }
