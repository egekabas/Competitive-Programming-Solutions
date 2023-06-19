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
    typedef pair<ll, ll>  pii;
    typedef pair<ld, ld>  pld;
    int n, m, q, sq = 320;
    vector<int> s[100009];
    ll a[100009];
    bool isbig[100009];
    vector<int> big;
    vector<int> small;
    int stob[100009][400];
    int btob[400][400];
    bool isin[400][100009];
    int id[100009];
    ll val[400];
    ll add[400];
    ll comp(ll x, ll y){
        ll ret = 0;
        for(auto u : s[x]){
            if(isin[id[y]][u] == 1)
                ++ret;
        }
        return ret;
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
        
        cin >> n >> m >> q;
        
        for(ll i = 1; i <= n; ++i)
            cin >> a[i];
        for(ll i = 1; i <= m; ++i){
            ll t1, t2;
            cin >> t1;
            if(t1 > sq){
                isbig[i] = 1;
                big.pb(i);
                id[i] = big.size()-1;    
            }
            else{
                small.pb(i);
            }
            for(int j = 0; j < t1; ++j){
                cin >> t2;
                s[i].pb(t2);
                if(t1 > sq){
                    val[id[i]] += a[t2];
                    isin[id[i]][t2] = 1;
                }
            }
        }
        for(auto i : big)
            for(auto j : small)
                stob[j][id[i]] = comp(j, i);
        for(auto i : big)
            for(auto j : big){
                if(j > i)
                    continue;
                btob[id[i]][id[j]] = btob[id[j]][id[i]] = comp(i, j);
            }
        while(q--){
            char t;
            int k;
            int x;
            cin >> t;
            if(t == '+'){
                cin >> k >> x;
                if(isbig[k] == 1)
                    add[id[k]] += x;
                else{
                    for(auto u : s[k])
                        a[u] += x;
                    for(auto u : big)
                        val[id[u]] += x*(stob[k][id[u]]);
                }
            }
            if(t == '?'){
                cin >> k;
                ll ret;
                if(isbig[k] == 1){
                    ret = val[id[k]];
                    for(auto u : big)
                        ret += add[id[u]]*btob[id[k]][id[u]];
                }
                else{
                    ret = 0;
                    for(auto u : s[k])
                        ret += a[u];
                    for(auto u : big)
                        ret += add[id[u]]*stob[k][id[u]];   
                }
                cout << ret << "\n";
            }
        }
    }