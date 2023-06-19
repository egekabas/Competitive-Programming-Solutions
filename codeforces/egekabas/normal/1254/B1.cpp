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
vector<ll> v;
vector<ll> divi;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i){
        ll t1;
        cin >> t1;
        if(t1)
            v.pb(i);
    }
    ll tmp = v.size();
    for(ll div = 2; div*div <= tmp; ++div){
        if(tmp % div == 0)
            divi.pb(div);
        while(tmp%div == 0)
            tmp /= div;
    }
    if(tmp > 1)
        divi.pb(tmp);
    ll ans = 1e18;
    for(auto div : divi){
        ll curans = 0;
        for(ll i = 0; i < v.size(); i += div){
            ll after = 0, bef = 0, mini = 1e18;
            for(ll j = i; j < i+div; ++j){
                after += v[j];
            }
            for(ll j = i; j < i+div; ++j){
                after -= v[j];
                mini = min(mini, v[j]*(j-i)-bef + after-v[j]*(i+div-1-j));
                bef += v[j];
            }
            curans += mini;
        }
        ans = min(ans, curans);
    }
    if(ans == 1e18)
        cout << "-1\n";
    else
        cout << ans << "\n";
}