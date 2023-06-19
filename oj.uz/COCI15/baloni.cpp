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
ll h[1000009];
ll ans;
multiset<ll> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> h[i];
    for(ll i = 0; i < n; ++i){
        auto it = s.upper_bound(h[i]);
        if(it != s.end() && *it == h[i]+1){
            s.erase(it);
            s.insert(h[i]);
        }
        else{
            ++ans;
            s.insert(h[i]);
        }
    }
    cout << ans << "\n";
}
