#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pll;
typedef pair<ld, ld>  pld;
ll n;
ll a[200009];
vector<pll> v;
pll found[200009];
ll mod = 1e9+7;
 
pll seg[800009];
void upd(ll v, ll tl, ll tr, ll id, pll val){
    if(id < tl || id > tr)
        return;
    if(tl == id && tr == id){
        seg[v] = val;
    }
    else{
        ll tm = (tl+tr)/2;
        upd(2*v, tl, tm, id, val);
        upd(2*v+1, tm+1, tr, id, val);
        if(seg[2*v].ff == seg[2*v+1].ff)
            seg[v] = {seg[2*v].ff, (seg[2*v].ss + seg[2*v+1].ss)%mod};
        else if(seg[2*v].ff > seg[2*v+1].ff)
            seg[v] = seg[2*v];
        else
            seg[v] = seg[2*v+1];
    }
}
pll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l < 0)
        return {0, 0};
    if(tl > r || tr < l)
        return {0, 0};
    if(l <= tl && tr <= r){
        return seg[v];
    }
    else{
        ll tm = (tl+tr)/2;
        pll t1 = get(2*v, tl, tm, l, r);
        pll t2 = get(2*v+1, tm+1, tr, l, r);
        if(t1.ff == t2.ff)
            return {t1.ff, (t1.ss + t2.ss)%mod};
        else if(t1.ff > t2.ff)
            return t1;
        else
            return t2;
    }
}
pll dc[200009];
pll ac[200009];
pll tot[200009];
ll pw(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        y /= 2;
        x = x*x%mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        v.pb({a[i], i});
    sort(v.begin(), v.end());
    ll i = 0, j = 0;
    while(i < n){
        for(j = i; j < n; ++j){
            if(v[i].ff != v[j].ff)
                break;
            found[j] = get(1, 0, n-1, v[j].ss+1, n-1);
            found[j].ff++;
            if(found[j].ss == 0 && found[j].ff == 1)
                ++found[j].ss;
        }
        for(ll k = i; k < j; ++k)
            upd(1, 0, n-1, v[k].ss, found[k]);
        i = j;
    }
    for(ll i = 0; i < n; ++i){
        dc[i].ff = get(1, 0, n-1, i, i).ff;
        dc[i].ss = get(1, 0, n-1, i, i).ss%mod;
        
    }
    for(ll i = 0; i <= 4*n; ++i)
        seg[i] = {0, 0};
    reverse(v.begin(), v.end());
    i = 0, j = 0;
    while(i < n){
        for(j = i; j < n; ++j){
            if(v[i].ff != v[j].ff)
                break;
            found[j] = get(1, 0, n-1, v[j].ss+1, n-1);
            found[j].ff++;
            if(found[j].ss == 0 && found[j].ff == 1)
                ++found[j].ss;
        }
        for(ll k = i; k < j; ++k)
            upd(1, 0, n-1, v[k].ss, found[k]);
        i = j;
    }
    for(ll i = 0; i < n; ++i){
        ac[i].ff = get(1, 0, n-1, i, i).ff;
        ac[i].ss = get(1, 0, n-1, i, i).ss%mod;
        
    }
    for(ll i = 0; i < n; ++i)
        tot[i] = {ac[i].ff + dc[i].ff-1, ac[i].ss*dc[i].ss%mod};
    ll len = 0;
    ll ans = 0;
    for(ll i = 0; i < n; ++i)
        len = max(len, tot[i].ff);
    for(ll i = 0; i < n; ++i)
        if(tot[i].ff == len){
            ans += pw(2, n-len)*tot[i].ss%mod;
            ans %= mod;
        }
    cout << len << " " << ans << "\n";
}
