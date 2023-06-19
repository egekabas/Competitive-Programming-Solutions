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
ll n;
vector<ll> querry;
ll val[100009];
vector<ll> g[100009];
ll prt[100009];
ll subsz[100009];
ll depth[100009];
void dfs1(int v){
    subsz[v] = 1;
    for(auto u : g[v]){
        prt[u] = v;
        depth[u] = depth[v]+1;
        dfs1(u);
        subsz[v] += subsz[u];
    }
}
int eul[100009];
int chain[100009];
int cureul = 0;
void dfs2(int v){
    //cout << v << " -- " << cureul << '\n';
    eul[v] = cureul++;
    if(eul[prt[v]] == eul[v]-1)
        chain[v] = chain[prt[v]];
    else
        chain[v] = v;
    int biggest = 0, id = 0;
    for(auto u : g[v])
        if(subsz[u] > biggest){
            biggest = subsz[u];
            id = u;
        }
    if(id != 0)
        dfs2(id);
    for(auto u : g[v])
        if(u != id)
            dfs2(u);
}
deque<pll> vec[100009];
    
ll bit[100009];
void updbit(ll idx, ll val){
    ++idx;
    while(idx <= n+2){
        bit[idx] += val;
        idx += idx&(-idx);
    }
}
ll getbit(ll idx){
    ++idx;
    ll ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= idx&(-idx);
    }
    return ret;
}
    
ll gettree(ll idx){
    vector<pll> all;
    while(idx != 0){
        deque<pll> &v = vec[chain[idx]];
        ll cnt = depth[idx]-depth[chain[idx]]+1;
        vector<pll> cur;
        for(auto u : v){
            ll sub = min(cnt, u.ff);
            cnt -= sub;
            cur.pb({sub, u.ss});
            if(cnt == 0)
                break;
        }
        reverse(cur.begin(), cur.end());
        for(auto u : cur)
            all.pb(u);
        idx = prt[chain[idx]];
    }
    ll ret = 0;
    for(auto u : all){
        ret += u.ff*getbit(u.ss-1);
        updbit(u.ss, u.ff);
    }
    for(auto u : all)
        updbit(u.ss, -u.ff);
    return ret;
}
void updtree(ll idx, ll val){
    while(idx != 0){
        deque<pll> &v = vec[chain[idx]];
        ll cnt = depth[idx]-depth[chain[idx]]+1;
        while(cnt > 0 && !v.empty()){
            ll sub = min(cnt, v.front().ff);
            cnt -= sub;
            v.front().ff -= sub;
            if(v.front().ff == 0)
                v.pop_front();
        }
        v.push_front({depth[idx]-depth[chain[idx]]+1, val});
        idx = prt[chain[idx]];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    vector<ll> compress;
    for(ll i = 1; i <= n; ++i){
        cin >> val[i];
        compress.pb(val[i]);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end())-compress.begin());
    for(ll i = 1; i <= n; ++i)
        val[i] = lower_bound(compress.begin(), compress.end(), val[i])-compress.begin();
    for(ll i = 1; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        querry.pb(y);
    }
    dfs1(1);
    dfs2(1);
    //updtree(1, val[1]);
    for(auto u : querry){
        
        cout << gettree(prt[u]) << '\n';
 
        updtree(u, val[u]);
    }
}
