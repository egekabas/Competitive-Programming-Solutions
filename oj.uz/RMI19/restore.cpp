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
    int n, m;
    vector<pair<int, pii>> edges;
    int dis[5009];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n >> m;
        while(m--){
            int l, r, k, val;
            cin >> l >> r >> k >> val;
            ++l;++r;
     
            if(val == 1)
                edges.pb({k-1, {l-1, r}});
            else
                edges.pb({-k, {r, l-1}});
        
        }
        for(int i = 1; i <= n; ++i){
            edges.pb({1, {i-1, i}});
            edges.pb({0, {i, i-1}});
            dis[i] = 1e9;
        }
        int cnt = 0;
        while(1){
            if(cnt > n+5){
                cout << "-1\n";
                return 0;
            }
            ++cnt;
            int br = 1;
            for(auto u : edges)
                if(dis[u.ss.ss] > dis[u.ss.ff]+u.ff){
                    dis[u.ss.ss] = dis[u.ss.ff]+u.ff;
                    br = 0;
                }
            if(br) break;
        }
        for(int i = 1; i <= n; ++i)
            cout << ((dis[i]-dis[i-1])^1) << ' ';
    }
