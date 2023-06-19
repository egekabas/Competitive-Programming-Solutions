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
const ll mod = 998244353;
ll cnt[26];
ll n;
ll ans;
int dp[409][9][209][209];
ll fin[209][209];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < 26; ++i)
        cin >> cnt[i];
    
    ans = 1;
    for(ll i = 0; i < n; ++i){
        if(i-2 >= 0)
            ans = ans*25%mod;
        else
            ans = ans*26%mod;
    }
    for(ll bit = 0; bit < 9; ++bit){
        ll cnt[2] = {0, 0};
        ll val = 1;
        if(bit%3 != 0)
            cnt[bit%3-1]++;
        else
            val *= 24;
        if((bit/3)%3 != 0)
            cnt[(bit/3)%3-1]++;
        else
            val *= 24;
        dp[2][bit][cnt[0]][cnt[1]] = val;
    }
    for(ll i = 2; i < n; ++i)
        for(ll bit = 0; bit < 9; ++bit){
            ll cnt[2];
            for(cnt[0] = 0; cnt[0] <= n/2+1; ++cnt[0])
                for(cnt[1] = 0; cnt[1] <= n/2+1; ++cnt[1])
                    for(ll j = 0; j < 3; ++j){
                        if(j != 0 && j == bit%3) continue;
                        ll nbit = bit/3 + 3*j;
                        ll ncnt[2] = {cnt[0], cnt[1]};
                        if(j != 0)
                            ncnt[j-1]++;
                        ll nval = dp[i][bit][cnt[0]][cnt[1]];
                        if(j == 0){
                            if(bit%3 == j)
                                nval = nval*23%mod;
                            else
                                nval = nval*24%mod;
                        }
                        dp[i+1][nbit][ncnt[0]][ncnt[1]] += nval;
                        dp[i+1][nbit][ncnt[0]][ncnt[1]] %= mod;
                    }
        }
    for(ll i = 0; i <= n/2+1; ++i)
        for(ll j = 0; j <= n/2+1; ++j)
            for(ll k = 0; k < 9; ++k){
                fin[i][j] += dp[n][k][i][j];
                fin[i][j] %= mod;
            }
    for(ll i = 0; i < 26; ++i){
        for(ll cnt0 = cnt[i]+1; cnt0 <= n/2+1; ++cnt0)
            for(ll cnt1 = 0; cnt1 <= n/2+1; ++cnt1)
                ans = (ans+mod-fin[cnt0][cnt1])%mod;
        for(ll j = i+1; j < 26; ++j)
            for(ll cnt0 = cnt[i]+1; cnt0 <= n/2+1; ++cnt0)
                for(ll cnt1 = cnt[j]+1; cnt1 <= n/2+1; ++cnt1)
                    ans = (ans+fin[cnt0][cnt1])%mod;
    }
    cout << ans << '\n';
}