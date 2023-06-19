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
ll t, n;
pll a[200009];
ll need[200009];
multiset<ll> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> t;
    while(t--){
        cin >> n;
        s.clear();
        for(ll i = 0; i < n; ++i)
            cin >> a[i].ff >> a[i].ss;
        sort(a, a+n);
        for(ll i = 0; i < n; ++i){
            if(i == 0 || a[i].ff != a[i-1].ff){
                need[a[i].ff] = max((ll)0, a[i].ff-i);
            }
        }
        ll sums = 0;
        ll ans = 0;
        for(ll i = n-1; i >= 0; --i){
            s.insert(a[i].ss);
            if(i == 0 || a[i].ff != a[i-1].ff){
                need[a[i].ff] -= sums;
                while(max((ll)0, need[a[i].ff]--) && s.size() > 0){
                    ans += *s.begin();
                    s.erase(s.begin());
                    ++sums;
                }
            }
        }
        cout << ans << "\n";
    }
}