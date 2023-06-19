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
    ll n, a[1000009];
    struct line{
        ll a, b;
        ll get(ll x){
            return a*x+b;
        }
    };
    ld inter(line x, line y){
        return ld(y.b-x.b)/ld(x.a-y.a);
    }
    vector<line> vec;
    void add(line x){
        while(vec.size() >= 2){
            if(inter(vec[vec.size()-2], x) <= inter(vec[vec.size()-2], vec.back()))
                vec.pop_back();
            else
                break;
        }
        vec.pb(x);
    }
    ll get(ll lim, ll x){
        ll l = 0, r = vec.size()-1;
        while(l < r){
            ll m = (l+r)/2;
            if(-vec[m].a < lim || vec[m+1].get(x) < vec[m].get(x))
                l = m+1;
            else
                r = m;
        }
        return vec[l].get(x);
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n;
        for(ll i = 1; i <= n; ++i)
            cin >> a[i];
        a[0] = -1;
        add({0, 0});
        vector<pll> bigs;
        bigs.pb({0, 0});
        for(ll i = 1; i <= n; ++i){
            while(bigs.size() && a[bigs.back().ff] <= a[i]){
                bigs.pop_back();
            }
            ll lim = 0;
            ll dp = 1e18;
            if(bigs.size()){
                lim = bigs.back().ff;
                dp = bigs.back().ss;
            }
            
            dp = min(get(lim, a[i])+a[i]*n, dp);
            add({-i, dp});
            bigs.pb({i, dp});
        }
        cout << bigs.back().ss << '\n';
    }
