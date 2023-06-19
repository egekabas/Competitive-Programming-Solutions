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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
const ll mod = 1e9+7;
ll N;
ll n, q;
ll a[600009];
pll query[600009];
ll twopr[600009];
ll pwr(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = x*ret%mod;
        y /= 2;
        x = x*x%mod;
    }
    return ret;
}
vector<ll> comp;
struct node{
    ll lval = 0, rval = 0, size = 0, ans = 0;
};
ll lval[2400009];
ll rval[2400009];
ll sz[2400009];
ll ans[2400009];

void merge(ll a, ll b, ll c){
    sz[c] = sz[a]+sz[b];
    ans[c] = (ans[a]*twopr[sz[b]]%mod+ans[b]*twopr[sz[a]]%mod)%mod;
    ans[c] = (ans[c] + lval[a]*rval[b]%mod)%mod;
    lval[c] = (lval[a] + lval[b]*twopr[sz[a]]%mod)%mod;
    rval[c] = (rval[b] + rval[a]*twopr[sz[b]]%mod)%mod;
}
void print(node a){
    cout << a.lval << ' ' << a.rval << ' ' << a.size << ' ' << a.ans << '\n';
    //Haydi gel, bulusalim,
    //Eski koprunun altinda.
}
ll cnt[600009];
inline ll func(ll x){
    if(x == 0) return 0;
    return (twopr[x-1]*(x-2)%mod+1)%mod;
}

void upd(ll v, ll tl, ll tr, ll idx){
    if(idx < tl || idx > tr)
        return;
    if(idx == tl && idx == tr){
        lval[v] = rval[v] = (twopr[cnt[tl]]-1)*comp[tl]%mod;
        sz[v] = cnt[tl];
        ans[v] = comp[tl]*comp[tl]%mod*func(cnt[tl])%mod; 
    }
    else{
        ll tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx);
        upd(2*v+1, tm+1, tr, idx);
        merge(2*v, 2*v+1, v);
    }
}
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        lval[v] = rval[v] = (twopr[cnt[tl]]-1)*comp[tl]%mod;
        sz[v] = cnt[tl];
        ans[v] = comp[tl]*comp[tl]%mod*func(cnt[tl])%mod;}
    else{
        ll tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        merge(2*v, 2*v+1, v);
    }
}
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    scanf("%lld", &n);
    twopr[0] = 1;
    for(ll i = 1; i <= n; ++i)
        twopr[i] = 2*twopr[i-1]%mod;
    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);
        comp.pb(a[i]);
    }
    ll rev2n = pwr(pwr(2, n), mod-2);
    cin >> q;
    for(ll i = 1; i <= q; ++i){
        scanf("%lld%lld", &query[i].ff, &query[i].ss);
        comp.pb(query[i].ss);
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end())-comp.begin());
    N = comp.size();
    for(ll i = 1; i <= n; ++i){
        a[i] = lower_bound(comp.begin(), comp.end(), a[i])-comp.begin();
        cnt[a[i]]++;
        //print(seg[1]);
    }
    build(1, 0, N-1);
    printf("%lld\n", (ans[1]*rev2n%mod));
    for(ll i = 1; i <= q; ++i){
        query[i].ss = lower_bound(comp.begin(), comp.end(), query[i].ss)-comp.begin();
        if(query[i].ss != a[query[i].ff]){
            cnt[a[query[i].ff]]--;
            upd(1, 0, N-1, a[query[i].ff]);
            a[query[i].ff] = query[i].ss;
            cnt[a[query[i].ff]]++;
            upd(1, 0, N-1, a[query[i].ff]);
        }
        printf("%lld\n", (ans[1]*rev2n%mod));
    }
}