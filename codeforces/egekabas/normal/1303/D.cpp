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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll a[100009];
ll how[100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;

    while(t--){
        ll n, m;
        cin >> n >> m;
        for(ll j = 0; j <= 60; ++j)
            how[j] = 0;
        for(ll i = 0; i < m; ++i)
            cin >> a[i];
        for(ll i = 0; i < m; ++i)
            for(ll j = 0; j <= 60; ++j)
                if((1LL<<j) == a[i]){
                    how[j]++;
                    break;
                }
        ll ans = 0;
        for(ll i = 0; i <= 60; ++i){
            if((n&(1LL<<i)) > 0){
                ll ok = 0;
                for(ll j = i; j <= 60; ++j){
                    if(how[j] > 0){
                        for(ll k = i; k < j; ++k)
                            how[k]++;
                        ans += j-i;
                        how[j]--;
                        ok = 1;
                        break;
                    }
                }
                if(ok == 0){
                    cout << "-1\n";
                    goto END;
                }
            }
            how[i+1] += how[i]/2;
        }
        cout << ans << "\n";
        END:;
    }
}