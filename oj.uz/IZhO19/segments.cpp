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
    ll n;
    ll a[500009], pre[500009];
    pll val[500009];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n;
        for(ll i = 0; i < n; ++i){
            cin >> a[i];
            pre[i] = a[i];
            if(i)
                pre[i] += pre[i-1];
            val[i] = {0LL, 1e9};
        }
        val[0] = {1, -a[0]};
        ll ans = 0;
        for(ll i = 0; i < n; ++i){
            ll curv = val[i].ff;
            ll curs = -val[i].ss;
            ans = max(ans, curv);
            ll idx = lower_bound(pre, pre+n, pre[i]+curs)-pre;
            val[idx] = max(val[idx], {curv+1, -(pre[idx]-pre[i])});
            val[i+1] = max(val[i+1], {curv, -curs-a[i+1]});
        }
        cout << ans << '\n';
    }
