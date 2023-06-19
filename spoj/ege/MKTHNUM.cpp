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
struct node{
    ll val = 0;
    node *l, *r;
    node(ll x){
        val = x;
        l = r = nullptr;
    }
    node(node * x, node * y){
        l = x;
        r = y;
        val = x->val + y->val;
    }
};
node * build(ll tl, ll tr){
    if(tl == tr)
        return new node(0);
    else{
        ll tm = (tl + tr)/2;
        return new node(build(tl, tm), build(tm+1, tr));
    }
}
node * upd(node * v, ll tl, ll tr, ll idx, ll val){
    if(tl == idx && tr == idx)
        return new node(v->val + val);
    else{
        ll tm = (tl+tr)/2;
        if(idx <= tm)
            return new node(upd(v->l, tl, tm, idx, val), v->r);
        else
            return new node(v->l, upd(v->r, tm+1, tr, idx, val));        
    }
}
ll get(node * v, ll tl, ll tr, ll l, ll r){
    if(tr < l || r < tl)
        return 0;
    if(l <= tl && tr <= r)
        return v-> val;
    else{
        ll tm = (tl+tr)/2;
        return get(v->l, tl, tm, l, r) + get(v->r, tm+1, tr, l, r);
    }
}
ll n, m;
ll a[100009];
vector<ll> mpp;
vector<ll> ids[100009];
node * state[100009];
ll query(ll i, ll j, ll k){
    --i;
    --j;
    ll l = 0, r = mpp.size()-1;
    while(l < r){
        ll mid = (l + r)/2;
        if(get(state[mid], 0, n-1, i, j) < k)
            l = mid+1;
        else
            r = mid;
    }
    return mpp[l];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        mpp.pb(a[i]);
    }
    sort(mpp.begin(), mpp.end());
    mpp.resize(unique(mpp.begin(), mpp.end())-mpp.begin());
    for(ll i = 0; i < n; ++i){
        ids[lower_bound(mpp.begin(), mpp.end(), a[i])-mpp.begin()].pb(i);
    }

    state[0] = build(0, n-1);
    for(ll i = 0; i < mpp.size(); ++i){
        if(i != 0)
            state[i] = state[i-1];
        for(auto u : ids[i])
            state[i] = upd(state[i], 0, n-1, u, 1);
    }
    while(m--){
        ll i, j, k;
        cin >> i >> j >> k;
        cout << query(i, j, k) << "\n";
    }
