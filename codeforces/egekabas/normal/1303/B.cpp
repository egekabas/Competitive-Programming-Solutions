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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    
    
    ll t;
    cin >> t;
    while(t--){
        ll n, g, b;
        cin >> n >> g >> b;
        ll l = 0;
        ll r = 1e18;
        while(l < r){
            ll m = (l+r)/2;
            ll cur = m/(g+b)*g + min(m%(g+b), g);
            if(cur >= (n+1)/2)
                r = m;
            else
                l = m+1;
        }
        cout << max(n, l) << "\n";
    }
}