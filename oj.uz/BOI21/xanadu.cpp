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
    ll n;
    vector<ll> g[100009];
    ll st[100009];
    ll dp[100009][2][2];
    ll sf(pii a, pii b){
        return (a.ss-a.ff) < (b.ss-b.ff);
    }
    void dfs(ll v, ll prt){
        for(auto u : g[v])
            if(u != prt)
                dfs(u, v);
        for(ll use = 0; use < 2; ++use)
            for(ll res = 0; res < 2; ++res){
                ll curst = (st[v]^use);
                ll curv = use;
                vector<pii> vec;
                for(auto u : g[v])
                    if(u != prt)
                        vec.pb({dp[u][0][use], dp[u][1][use]});
                sort(all(vec), sf);
                if(vec.empty()){
                    if(curst == res)
                        dp[v][use][res] = curv;
                    else
                        dp[v][use][res] = 1e9;
                    continue;
                }
                ll idx = 0;
                if(curst != res){
                    curv += vec[idx].ss;
                    curst ^= 1;
                    ++idx;
                }
                for(; idx < vec.size(); ++idx){
                    if(idx != vec.size()-1 && vec[idx].ss+vec[idx+1].ss<vec[idx].ff+vec[idx+1].ff){
                        curv += vec[idx].ss+vec[idx+1].ss;
                        idx++;
                    }
                    else
                        curv += vec[idx].ff;
                    
                }
                dp[v][use][res] = min(curv, (ll)1e9);
            }
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n;
        for(ll i = 0; i < n-1; ++i){
            ll x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        for(ll i = 1; i <= n; ++i)
            cin >> st[i];
        dfs(1, 0);
        if(min(dp[1][0][0], dp[1][1][0]) == 1e9)
            cout << "impossible\n";
        else
            cout << min(dp[1][0][0], dp[1][1][0]) << '\n';
    }
