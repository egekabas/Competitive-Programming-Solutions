//#include "grader.h"
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
struct tree{
    vector<ll> seg;
    void init(ll n){
        seg.clear();
        seg.resize(4*n+9);
    }
    void upd(ll v, ll tl, ll tr, ll idx, ll val){
        if(tl == idx && tr == idx){
            seg[v] += val;
            return;
        }
        if(idx <= (tl+tr)/2)
            upd(2*v, tl, (tl+tr)/2, idx, val);
        else
            upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
        seg[v] = seg[2*v]+seg[2*v+1];
    }
    pll get(ll v, ll tl, ll tr, ll val){
        if(tl == tr)
            return {tl, max(0LL, seg[v]-val)};
        if(seg[2*v+1] >= val)
            return get(2*v+1, (tl+tr)/2+1, tr, val);
        else
            return get(2*v, tl, (tl+tr)/2, val-seg[2*v+1]);
    }
};
struct bit{
    ll n;
    vector<ll> bit;
    void init(ll sz){
        bit.clear();
        bit.resize(sz+1);
        n = sz;
    }
    void upd(ll idx, ll val){
        for(++idx; idx > 0; idx -= idx&(-idx))
            bit[idx] += val;
    }
    ll get(ll idx){
        ll ret = 0;
        for(++idx; idx <= n; idx += idx&(-idx))
            ret += bit[idx];
        return ret;
    }
};
vector<ll> mpp;
struct data{
    tree tr;
    bit bi;
    ll n;
    void init(ll N){
        n = N;
        tr.init(n);
        bi.init(n);
    }
    void add(ll x){
        tr.upd(1, 0, n-1, x, 1);
        bi.upd(x, mpp[x]);
    }
    void erase(ll x){
        tr.upd(1, 0, n-1, x, -1);
        bi.upd(x, -mpp[x]);    
    }
    ll get(ll cnt){
        if(cnt <= 0) return cnt;
        pii pi = tr.get(1, 0, n-1, cnt);
        return bi.get(pi.ff)-pi.ss*mpp[pi.ff];
    }
};
ll N, D;
vector<ll> v1, v2, v3, v4;
vector<ll> go1, come1, go2, come2;
data dt;
void opt(ll l, ll r, ll vl, ll vr, vector<ll> &v, data &dt, vector<ll> &ret, ll comeback){
    if(v.empty()){
        for(ll i = l; i <= r; ++i)
            ret[i] = 0;
        return;
    }
    if(l > r)
        return;
    ll m = (l+r)/2;
    pii maxi = {-1e9, -1e9};
    for(ll i = vl; i <= vr; ++i){
        
        dt.add(v[i]);
        if(comeback)
            maxi = max(maxi, {dt.get(m-2*i), i});
        else
            maxi = max(maxi, {dt.get(m-i), i});
    }
 
    ll vm = maxi.ss;
    ret[m] = maxi.ff;
    for(ll i = vr; i >= vm; --i)
        dt.erase(v[i]);
    opt(m+1, r, vm, vr, v, dt, ret, comeback);
    for(ll i = vm-1; i >= vl; --i)
        dt.erase(v[i]);
    opt(l, m-1, vl, vm, v, dt, ret, comeback);
}
ll getval(vector<ll> v, ll lim){
    data dt;
    dt.init(mpp.size());
    ll ans = 0;
    for(int i = 0; i < v.size(); ++i){
        dt.add(v[i]);
        ans = max(ans, dt.get(lim-i));
    }
    return ans;
}
long long int findMaxAttraction(int n, int start, int d, int attraction[]) {
    N = n;
    D = d;
    for(ll i = 0; i < n; ++i)
        mpp.pb(attraction[i]);
    sort(all(mpp));
    mpp.resize(unique(all(mpp))-mpp.begin());
    for(ll i = 0; i < n; ++i)
        attraction[i] = lower_bound(all(mpp), attraction[i])-mpp.begin();
    for(ll i = start+1; i < n; ++i)
        v1.pb(attraction[i]);
    for(ll i = start; i < n; ++i)
        v2.pb(attraction[i]);
    for(ll i = start-1; i >= 0; --i)
        v3.pb(attraction[i]);
    for(ll i = start; i >= 0; --i)
        v4.pb(attraction[i]);
    
    dt.init(mpp.size());
    go1.resize(d);
    opt(0, d-1, 0, v1.size()-1, v1, dt, go1, 0);
 
    dt.init(mpp.size());
    come1.resize(d);
    opt(0, d-1, 0, v2.size()-1, v2, dt, come1, 1);
 
    dt.init(mpp.size());
    go2.resize(d);
    opt(0, d-1, 0, v3.size()-1, v3, dt, go2, 0);
 
    dt.init(mpp.size());
    come2.resize(d);
    opt(0, d-1, 0, v4.size()-1, v4, dt, come2, 1);
 
    for(ll i = 1; i < d; ++i){
        go1[i] = max(go1[i], go1[i-1]);
        come1[i] = max(come1[i], come1[i-1]);
        go2[i] = max(go2[i], go2[i-1]);
        come2[i] = max(come2[i], come2[i-1]);
    
    }
 
    ll ans = 0;
    for(ll i = 0; i < d; ++i){
        ans = max(ans, come1[i]+go2[d-i-1]);
        ans = max(ans, come2[i]+go1[d-i-1]);
        //cout << i << ' ' << come2[i] << ' ' << d-i-1 << ' ' << go1[d-i-1] << '\n';
    }
    
    ans = max(ans, getval(v2, d));
    ans = max(ans, getval(v4, d));
    
    return ans;
}
