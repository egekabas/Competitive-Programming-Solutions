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
    typedef pair<int, int> pii;
    typedef pair<ld, ld> pld;
    ll ans[1009][1009];
    ll a[1009];
    ll n;
    ll depth[1009][3];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n;
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        for(ll i = n-1; i >= 0; --i){
            for(ll j = i+1; j < n; ++j){
                pll mini = {1e9, 1e9};
                for(ll k = 0; k < 3; ++k)
                    mini = min(mini, {depth[j][k], k});
     
                ans[i][j] = mini.ss;
                depth[i][mini.ss] = max(mini.ff+1, depth[i][mini.ss]);
            }
        }
        for(ll i = 1; i < n; ++i){
            for(ll j = 0; j < i; ++j){
                //cout << j << ' ' << i << ' ';
                cout << ans[j][i]+1 << ' ';
            }
            cout << '\n';
        }
    }
