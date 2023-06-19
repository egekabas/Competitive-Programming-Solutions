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
ll n;
ll a[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    ll add = 0;
    set<pll> s;
    for(ll i = n-1; i >= 0; --i){
        auto it = s.lower_bound({a[i]-add, -1e9});
        ll cur = a[i];
        if(it != s.end() && (*it).ff == a[i]-add){
            cur += (*it).ss;
            s.erase(it);
        }
        ans = max(ans, cur);
        s.insert({a[i]-add, cur});
        --add;
    }
    cout << ans << '\n';
}