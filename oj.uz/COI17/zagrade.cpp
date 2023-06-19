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
ll a[300009];
vector<ll> g[300009];
ll sz[300009];
ll block[300009];
ll ans;
void findsize(ll v, ll p){
    sz[v] = 1;
    for(auto u : g[v]){
        if(u == p || block[u])
            continue;
        findsize(u, v);
        sz[v] += sz[u];
    }
}
ll findcentroid(ll v, ll p, ll tot){
    for(auto u : g[v]){
        if(u == p || block[u])
            continue;
        if(sz[u] >= tot/2)
            return findcentroid(u, v, tot);
    }
    return v;
}
map<ll, ll> mpp1;
map<ll, ll> mpp2;
 
void dp1(ll v, ll p, ll cur, ll bal){
    cur += a[v];
    if(bal < 0 && a[v] == 1)
        bal += a[v];
    if(a[v] == -1)
        bal += a[v];
    if(bal == 0 && cur >= 0)
        mpp1[cur]++;
    for(auto u : g[v]){
        if(u == p || block[u])
            continue;
        dp1(u, v, cur, bal);
    }
}
void dp2(ll v, ll p, ll cur, ll bal){
    cur += a[v];
    if(bal > 0 && a[v] == -1)
        bal += a[v];
    if(a[v] == 1)
        bal += a[v];
    if(bal == 0 && cur <= 0)
        mpp2[cur]++;
    for(auto u : g[v]){
        if(u == p || block[u])
            continue;
        dp2(u, v, cur, bal);
    }
}
    
void maincalc(ll v){
    findsize(v, -1);
    v = findcentroid(v, -1, sz[v]);
    map<ll, ll> cur1;
    map<ll, ll> cur2;
    for(auto u : g[v]){
        if(block[u])
            continue;
        dp1(u, v, 0, 0);
        dp2(u, v, 0, 0);
        //cout << v << " ----- " << u << "\n";
        for(auto u : mpp1){
            //cout << u.ff << " " << u.ss << "\n";
            if(u.ff + a[v] < 0)
                continue;
            if(u.ff + a[v] == 0)
                ans += u.ss;
            ans += cur2[-(u.ff+a[v])]*u.ss;
        }
        for(auto u : mpp2){
            if(u.ff + a[v] > 0)
                continue;
            if(u.ff + a[v] == 0)
                ans += u.ss;
            ans += cur1[-(u.ff+a[v])]*u.ss;
        }
        for(auto u : mpp1){
            if(u.ff < 0)
                continue;
            cur1[u.ff] += u.ss;
        }
        for(auto u : mpp2){
            if(u.ff > 0)
                continue;
            cur2[u.ff] += u.ss;
        }
        mpp1.clear();
        mpp2.clear();
    }
    cur1.clear();
    cur2.clear();
    block[v] = 1;
    for(auto u : g[v]){
        if(block[u] == 0)
            maincalc(u);
    }
}
    
ll input(){
    char c;
    cin >> c;
    if(c == '(')
        return 1;
    if(c == ')')
        return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 1; i <= n; ++i)
        a[i] = input();
    for(ll i = 1; i < n; ++i){
        ll t1, t2;
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
    }
    maincalc(1);
    cout << ans << "\n";
}
