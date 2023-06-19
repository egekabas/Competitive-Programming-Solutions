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
ll add(ll x){
    ll mini = 10;
    ll maxi = 0;
    while(x > 0){
        mini = min(mini, x%10);
        maxi = max(maxi, x%10);
        x /= 10;
    }
    return mini*maxi;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;
    while(t--){
        ll cur, k;
        cin >> cur >> k;
        for(ll i = 1; i < k; ++i){
            if(add(cur) == 0)
                break;
            cur += add(cur);
        }
        cout << cur << '\n';
    }
}