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
    ll ans = 0;
    ll sq = 500;
    ll n, m;
    ll prt[100009];
    ll sz[100009];
    ll id[100009];
    ll curbig = 1;
    bitset<100009> comesto[509];
    bitset<100009> bigin[509];
    bitset<100009> bigout[509];
    ll totin[100009];
    vector<ll> in[100009];
    vector<pll> out[100009];
    bitset<100009> tmp;
     
    ll findprt(ll x){
        if(prt[x] == x) return x;
        return prt[x] = findprt(prt[x]);
    }
    void makebig(ll x){
        id[x] = curbig++;
        for(auto u : in[x]){
            bigin[id[x]][findprt(u)] = 1;
            if(findprt(u) != x && comesto[id[x]][u] == 0){
                totin[x]++;
                comesto[id[x]][u] = 1;
            }
        }
        for(auto u : out[x])
            bigout[id[x]][findprt(u.ss)] = 1;
        
    }
    ll calc(ll x){
        if(id[x]) return totin[x]*sz[x];
        ll cur = 0;
        for(auto u : in[x])
            if(findprt(u) != x && tmp[u] == 0){
                tmp[u] = 1;
                cur += sz[x];
            }
        for(auto u : in[x])
            tmp[u] = 0;
        return cur;
    }
    void merge(ll x, ll y){
        x = findprt(x);
        y = findprt(y);
        if(x == y) return;
        if(!id[x] && ll(in[x].size()+out[x].size()) > sq)
            makebig(x);
        if(!id[y] && ll(in[y].size()+out[y].size()) > sq)
            makebig(y);
        if(id[y] || (!id[x] && in[y].size()+out[y].size() > in[x].size()+out[x].size()))
            swap(x, y);
        
        if(id[x]){
            if(bigin[id[x]][y] == 0 || bigout[id[x]][y] == 0)
                return;
        }
        else{
            ll goin = 0;
            ll goout = 0;
            for(auto u : in[y])
                if(findprt(u) == x)++goin;
            for(auto u : out[y])
                if(findprt(u.ss) == x)++goout;
            if(goin == 0 || goout == 0)
                return;
        }
        ans -= calc(x)+calc(y);
        vector<ll> mergelater;  
        if(id[x] && id[y]){
            totin[x] -= bigin[id[x]][y];
            prt[y] = x;
            bigout[id[x]] |= bigout[id[y]];
            bigin[id[x]] |= bigin[id[y]];
            comesto[id[x]] |= comesto[id[y]];
            totin[x] = 0;
            for(ll i = 1; i <= n; ++i){
                if(findprt(i) != x && comesto[id[x]][i])
                    ++totin[x];
                if(findprt(i) == i && i != x && bigout[id[x]][i] && bigin[id[x]][i])
                    mergelater.pb(i);
            }
            ans -= sz[x]*(sz[x]-1)+sz[y]*(sz[y]-1);
            sz[x] += sz[y];
            ans += sz[x]*(sz[x]-1);
        }
        else if(id[x]){
     
            prt[y] = x;
            for(auto u : in[y]){
                bigin[id[x]][findprt(u)] = 1;
                if(findprt(u) != x && comesto[id[x]][u] == 0){
                    //cout << "HEY1\n";
                    totin[x]++;
                    comesto[id[x]][u] = 1;
                }
                if(findprt(u) != x && bigout[id[x]][findprt(u)])
                    mergelater.pb(findprt(u));
            }
            for(auto u : out[y]){
                if(findprt(u.ss) == x && comesto[id[x]][u.ff] == 1){
                    //cout << "HEY2\n";
                    totin[x]--;
                    comesto[id[x]][u.ff] = 0;
                }
                bigout[id[x]][findprt(u.ss)] = 1;
                if(findprt(u.ss) != x && bigin[id[x]][findprt(u.ss)])
                    mergelater.pb(findprt(u.ss));
            }
     
            ans -= sz[x]*(sz[x]-1)+sz[y]*(sz[y]-1);
            sz[x] += sz[y];
            ans += sz[x]*(sz[x]-1);
        }
        else{
            prt[y] = x;
            for(auto u : in[y])
                if(findprt(u) != x) in[x].pb(u);
            for(auto u : out[y])
                if(findprt(u.ss) != x) out[x].pb(u);
            ans -= sz[x]*(sz[x]-1)+sz[y]*(sz[y]-1);
            sz[x] += sz[y];
            ans += sz[x]*(sz[x]-1);
            for(auto u : in[x])
                tmp[findprt(u)] = 1;
            for(auto u : out[x])
                if(tmp[findprt(u.ss)] && findprt(u.ss) != x)
                    mergelater.pb(findprt(u.ss));
            for(auto u : in[x])
                tmp[findprt(u)] = 0;
        }
        for(ll i = 1; i < curbig; ++i){
            if(bigin[i][y])
                bigin[i][x] = bigin[i][y];
            bigin[i][y] = 0;
            if(bigout[i][y])
                bigout[i][x] = bigout[i][y];
            bigout[i][y] = 0; 
        }
        if(!id[x] && ll(in[x].size()+out[x].size()) > sq)
            makebig(x);
        ans += calc(x);
        for(auto u : mergelater){
            merge(x, u);
        }
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
     
        //freopen("in.txt", "r", stdin);                                                                                             
        //freopen("out.txt", "w", stdout);
     
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i){
            sz[i] = 1;
            prt[i] = i;
        }
        while(m--){
            ll x, y;
            cin >> x >> y;
            ll dont = (findprt(x) == findprt(y));
            if(id[findprt(y)]){
                if(comesto[id[findprt(y)]][x])
                    dont = 1;   
            }
            else{
                for(auto u : in[findprt(y)])
                    if(u == x)
                        dont = 1;
            }
            if(dont){
                cout << ans << '\n';
                continue;
            }
            if(id[findprt(x)] == 0)
                out[findprt(x)].pb({x, y});
            if(id[findprt(y)] == 0)
                in[findprt(y)].pb(x);
            if(id[findprt(y)]){
                comesto[id[findprt(y)]][x] = 1;
                totin[findprt(y)]++;
            }
            x = findprt(x);
            y = findprt(y);
            ans += sz[y];
            if(id[x])
                bigout[id[x]][y] = 1;
            if(id[y])
                bigin[id[y]][x] = 1;
            merge(x, y);
            cout << ans << '\n';
        }
    }
