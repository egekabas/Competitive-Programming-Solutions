    #include <bits/stdc++.h>
    #define ff first
    #define ss second
    #define pb push_back
    #define mp make_pair
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
    typedef pair<ll, ll>    pll;
    typedef pair<ull, ull>    pull;
    typedef pair<int, int>  pii;
    typedef pair<ld, ld>  pld;
    pll a[200009];
    ll b[200009];
    ll n;
    ll ls[200009];
    ll rs[200009];
    ll ans[200009];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
     
        //freopen("in.txt", "r", stdin);                                                                                             
        //freopen("out.txt", "w", stdout);
        
        cin >> n;
        for(ll i = 0; i <= n; ++i){
            cin >> a[i].ff;
            a[i].ss = i;
        }
        for(ll i = 0; i < n; ++i)
            cin >> b[i];
        sort(a, a+n+1);
        sort(b, b+n);
        ls[0] = max(0LL, a[0].ff-b[0]);
        for(ll i = 1; i < n; ++i)
            ls[i] = max(a[i].ff-b[i], ls[i-1]);
        for(ll i = n-1; i >= 0; --i)
            rs[i] = max(rs[i+1], a[i+1].ff-b[i]);
     
        for(ll i = 0; i <= n; ++i){
            ans[a[i].ss] = rs[i];
            if(i != 0)
                ans[a[i].ss] = max(ans[a[i].ss], ls[i-1]);
        }
        for(ll i = 0; i <= n; ++i)
            cout << ans[i] << ' ';
    }
