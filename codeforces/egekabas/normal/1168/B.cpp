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
string s;
vector<ll> o;
vector<ll> z;
vector<pii> lr;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    ll cur = n;
    for(ll i = n-3; i >= 0; --i){
        for(ll k = 1; i+2*k < cur; ++k)
            if(s[i] == s[i+k] && s[i] == s[i+2*k])
                cur = i+2*k;
        //cout << i << " " << cur << endl;
        ans += n-cur;
    }
    cout << ans << endl;
}