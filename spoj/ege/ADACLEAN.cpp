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
typedef long double ld;
ll t,n,k;
ll p2 = 31, p1 = 47, mod = 1e9+7;
map<ll, bool> mpp1, mpp2;
ll inv(ll x){
    ll ret = 1;
    ll y = mod-2;
    while(y > 0){
        if(y % 2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> t;
    while(t--){
        mpp1.clear();
        mpp2.clear();
        cin >> n >> k;
        ll ans = 0;
        ll cur1 = 0;
        ll mult1 = p1;
        ll rev1 = inv(p1);
        ll cur2 = 0;
        ll mult2 = p2;
        ll rev2 = inv(p2);
        
        cin >> s;
        for(int i = 0; i < k; ++i){
            cur1 += (s[i]-'a'+1)*mult1%mod; cur1 %= mod;
            cur2 += (s[i]-'a'+1)*mult2%mod; cur2 %= mod;
            if(i != k-1){
                mult1 = mult1*p1%mod;
                mult2 = mult2*p2%mod;
            }
        }
        mpp1[cur1] = 1;
        mpp2[cur2] = 1;
        ++ans;
        for(int i = k; i < n; ++i){
            cur1 -= (s[i-k]-'a'+1)*p1%mod;
            cur2 -= (s[i-k]-'a'+1)*p2%mod;
            if(cur1 < 0) cur1 += mod;
            if(cur2 < 0) cur2 += mod;
            cur1 = cur1*rev1%mod;
            cur2 = cur2*rev2%mod;
            cur1 += (s[i]-'a'+1)*mult1%mod; cur1 %= mod;
            cur2 += (s[i]-'a'+1)*mult2%mod; cur2 %= mod;
            if(mpp1[cur1] == 0 || mpp2[cur2] == 0)
                ++ans;
            mpp1[cur1] = mpp2[cur2] = 1;
        }
        cout << ans << "\n";
    }
