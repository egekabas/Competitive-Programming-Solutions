#include <bits/stdc++.h>
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
const ll mod = 1e9+7;
ll n, m, q;
vector<pll> g[2009];
ll dis[2009][2009];
priority_queue<pair<pll, ll>> pq;
struct node{
    ll w;
    vector<ll> vert;
    vector<pll> vals;
    void init(){
        for(ll i = m; i >= 0; --i){
            ll cur = -1e18;
            for(auto u : vert)
                cur = max(cur, dis[u][i]);
            if(cur == -1e18) continue;
            while(!vals.empty()){
                pll tmp = vals.back();
                if(cur + (tmp.ss-i)*w >= tmp.ff)
                    vals.pop_back();
                else
                    break;
            }
            vals.pb({cur, i});
        }
        reverse(vals.begin(), vals.end());
    }
    ll getval(ll x){
        if(vals[0].ss > x) return -1e18-w;
        ll l = 0, r = vals.size()-1;
        while(l < r){
            ll mid = (l+r+1)/2;
            if(vals[mid].ss > x)
                r = mid-1;
            else
                l = mid;
        }
        return vals[l].ff + w*(x-vals[l].ss);
    }
    ll getrange(ll l, ll r){
        if(l > r) return 0;
        ll ans = 0;
        for(int i = 0; i < vals.size(); ++i){
            if(vals[i].ss > r) break;
            if(i != vals.size()-1 && vals[i+1].ss <= l) continue;
            ll l1 = max(vals[i].ss, l);
            ll r1 = r;
            if(i != vals.size()-1)
                r1 = min(r1, vals[i+1].ss-1);
            ans += (r1-l1+1)*vals[i].ff%mod - (r1-l1+1)*w%mod*vals[i].ss%mod;
            ans = (ans+mod)%mod;
            ans += (r1-l1+1)*(l1+r1)/2%mod*w%mod;
            ans %= mod;
        }
        return ans;
    }
};
vector<node> ns;
ll comp(node x, node y){
    ll l = m, r = 1e9;
    while(l < r){
        ll mid = (l+r+1)/2;
        if(x.getval(mid) >= y.getval(mid))
            l = mid;
        else
            r = mid-1;
    }
    return l;
}
vector<pair<node, ll>> use;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> q;
    for(ll i = 0; i < m; ++i){
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 0; j <= m; ++j)
            dis[i][j] = -1e18;
    dis[1][0] = 0;
    pq.push({{0, 0}, 1});
    while(!pq.empty()){
        ll v = pq.top().ss;
        ll cur = -pq.top().ff.ff;
        ll val = pq.top().ff.ss;
        pq.pop();
        if(dis[v][cur] > val || cur == m)
            continue;
        for(auto u : g[v])
            if(dis[u.ff][cur+1] < val + u.ss){
                dis[u.ff][cur+1] = val + u.ss;
                pq.push({{-(cur+1), val + u.ss}, u.ff});
            }
    }
    vector<pll> v;
    for(ll i = 1; i <= n; ++i){
        ll maxi = 0;
        for(auto u : g[i])
            maxi = max(u.ss, maxi);
        v.pb({maxi, i});
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < n; ++i){
        if(i > 0 && v[i].ff == v[i-1].ff)
            ns.back().vert.pb(v[i].ss);
        else{
            node nw;
            nw.w = v[i].ff;
            nw.vert = {v[i].ss};
            ns.pb(nw);
        }
    }
    for(auto & u : ns){
        u.init();
        while(!use.empty()){
            use.back().ss = comp(use.back().ff, u);
            if(use.size() >= 2 && use[use.size()-2].ss >= use.back().ss)
                use.pop_back();
            else
                break;
        }
        use.pb({u, 1e9});
    }
    ll ans = 0;
    for(ll i = 0; i <= min(m, q); ++i){
        ll maxi = 0;
        for(ll j = 1; j <= n; ++j)
            maxi = max(maxi, dis[j][i]);
        ans = (ans + maxi)%mod;
    }
    ll cur = m+1;
    for(auto u : use){
        if(cur > q) break;
        ans = (ans + u.ff.getrange(cur, min(q, u.ss)))%mod;
        cur = u.ss+1;
    }
    cout << ans << '\n';
}