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
    int imp;//delete later
    int n, k;
        
    char t[240009];
    int x[240009];
    int y[240009];
        
    vector<pii> g[120009];
        
    int dad[120009][25];
    int depth[120009];
        
    int pval[120009][25];
    int incr[120009][25];
    int decr[120009][25];
        
    void dfs(int v, int prt){
        dad[v][0] = prt;
        depth[v] = depth[prt]+1;
        
        for(int i = 1; i < 25; ++i){
            dad[v][i] = dad[dad[v][i-1]][i-1];
            pval[v][i] = pval[dad[v][i-1]][i-1];
            if(incr[v][i-1] && incr[dad[v][i-1]][i-1] && pval[v][i-1] < pval[dad[v][i-1]][0])
                incr[v][i] = 1;
            if(decr[v][i-1] && decr[dad[v][i-1]][i-1] && pval[v][i-1] > pval[dad[v][i-1]][0])
                decr[v][i] = 1;
        }
        for(auto u : g[v])
            if(u.ff != prt){
                incr[u.ff][0] = decr[u.ff][0] = 1;
                pval[u.ff][0] = u.ss;
                dfs(u.ff, v);
            }
    }
    int lca(int x, int y){
        if(depth[y] > depth[x])
            swap(x, y);
        for(int i = 24; i >= 0; --i)
            if(depth[dad[x][i]] >= depth[y])
                x = dad[x][i];
        if(x == y) return x;
        for(int i = 24; i >= 0; --i)
            if(dad[x][i] != dad[y][i]){
                x = dad[x][i];
                y = dad[y][i];
            }
        return dad[x][0];
    }
    struct retst{
        int incr = 1, decr = 1, maxi = -1, last = -1;
    };
    retst goup(int x, int y){
        retst ret = retst();
        for(int i = 24; i >= 0; --i)
            if(depth[dad[x][i]] >= depth[y]){
                if((ret.last != -1 && ret.last > pval[x][0]) || incr[x][i] == 0)
                    ret.incr = 0;
                if((ret.last != -1 && ret.last < pval[x][0]) || decr[x][i] == 0)
                    ret.decr = 0;
                ret.maxi = max({ret.maxi, pval[x][0], pval[x][i]});
                ret.last = pval[x][i];
                x = dad[x][i];
            }
        return ret;
    }
    int bit[240009];
    void upd(int idx, int val){
        for(++idx; idx <= 240000; idx += idx&(-idx))
            bit[idx] += val;
    }
    int get(int idx){
        int ret = 0;
        for(++idx; idx > 0; idx -= idx&(-idx))
            ret += bit[idx];
        return ret;
    }
    vector<int> qu[240009];
    int ans[240009];
    int sz[240009];
    int block[240009];
    void getsz(int v, int prt){
        sz[v] = 1+qu[v].size();
        for(auto u : g[v]){
            if(u.ff == prt || block[u.ff]) continue;
            getsz(u.ff, v);
            sz[v] += sz[u.ff];
        }
    }
    int getcentroid(int v, int prt, int totsz){
        for(auto u : g[v]){
            if(u.ff == prt || block[u.ff]) continue;
            if(sz[u.ff]*2 > totsz)
                return getcentroid(u.ff, v, totsz);
        }
        return v;
    }
    void getvec(int v, int prt, int cur, vector<pii>&vec, int inc){
        vec.pb({v, cur});
        for(auto u : g[v]){
            if(u.ff == prt || block[u.ff]) continue;
            if(u.ss > cur && inc)
                getvec(u.ff, v, u.ss, vec, inc);
            if(u.ss < cur && !inc)
                getvec(u.ff, v, u.ss, vec, inc);
        }
    }
    void calc(int root){
        getsz(root, 0);
        root = getcentroid(root, 0, sz[root]);
        vector<pair<int, vector<pii>>> vinc;
        vector<pair<int, vector<pii>>> vdec;
        
        for(auto u : g[root]){
            if(block[u.ff]) continue;
            vector<pii> v1, v2;
            getvec(u.ff, root, u.ss, v1, 1);
            getvec(u.ff, root, u.ss, v2, 0);
            vinc.pb({u.ss, v1});
            vdec.pb({u.ss, v2});
        }
        sort(all(vinc));
        sort(all(vdec));
        
        for(int i = vinc.size()-1; i >= 0; --i){
            for(auto u : vdec[i].ss)
                for(auto u2 : qu[u.ff]){
                    ans[u2] += get(u2);
                    if(vinc[i].ff < u2)
                        ans[u2]++;
                }
            for(auto u : vinc[i].ss)
                upd(u.ss, 1);
        }
        for(auto u : qu[root])
            ans[u] += get(u);
        
        for(int i = vinc.size()-1; i >= 0; --i)
            for(auto u : vinc[i].ss)
                upd(u.ss, -1);
        
        block[root] = 1;
        for(auto u : g[root])
            if(block[u.ff] == 0)
                calc(u.ff);
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
        
        cin >> n >> k;
        for(int i = 0; i < n+k-1; ++i){
            cin >> t[i];
            if(t[i] == 'C'){
                cin >> x[i];
                qu[x[i]].pb(i);
            }
            else
                cin >> x[i] >> y[i];
            if(t[i] == 'S'){
                g[x[i]].pb({y[i], i});
                g[y[i]].pb({x[i], i});
            }
        }
        calc(1);
        dfs(1, 0);
        for(int i = 0; i < n+k-1; ++i){
            if(t[i] == 'S') continue;
            else if(t[i] == 'Q'){
                int lc = lca(x[i], y[i]);
                retst a = goup(x[i], lc);
                retst b = goup(y[i], lc);
                if(a.decr && b.incr && (a.last == -1 || b.last == -1 || a.last > b.last) && max(a.maxi, b.maxi) <= i)
                    cout << "yes\n";
                else
                    cout << "no\n";
            }
            else{
                cout << ans[i]+1 << '\n';
            }
        }
    }
