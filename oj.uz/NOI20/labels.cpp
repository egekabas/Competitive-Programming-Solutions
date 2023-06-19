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
    typedef pair<ll, ll> pii;
    typedef pair<ld, ld> pld;
    ll n, a[300009];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n;
        for(ll i = 0; i < n-1; ++i)
            cin >> a[i];
        ll cur = 0, mini = 0, maxi = 0;
        for(ll i = 0; i < n-1; ++i){
            cur += a[i];
            mini = min(mini, cur);
            maxi = max(maxi, cur);
        }
        if(maxi-mini == n-1){
            ll cur = n-maxi;
            cout << cur << '\n';
            for(ll i = 0; i < n-1; ++i){
                cur += a[i];
                cout << cur << '\n';
            }
        }
        else
            cout << "-1\n";
    }
