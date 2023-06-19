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
    ll n, a[200009];
    void calc(ll cur[]){
        cur[0] = 0;
        for(ll i = 1; i < n; ++i){
            cur[i] = cur[i-1];
            cur[i] += max(0LL, a[i-1]+1-a[i]);
        }
    }
    ll cur[2][200009];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n;
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        calc(cur[0]);
        
        reverse(a, a+n);
        calc(cur[1]);
        reverse(cur[1], cur[1]+n);
        
        ll res = 1e18;
        for(ll i = 0; i < n; ++i){
            res = min(res, max(cur[0][i], cur[1][i]));
            //cout << i << ' ' << max(cur[0][i], cur[1][i]) << '\n';
        }
        cout << res << '\n';
    }
