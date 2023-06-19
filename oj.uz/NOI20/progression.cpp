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
const ll inf = 1e18;
struct node{
    ll lval, rval, sz;
    
    ll lcnt, lslope;
    ll rcnt, rslope;
 
    ll ans, empty;
    node(){
        empty = 1;   
    }
    node(ll val){
        lval = rval = val;
        sz = 1;
        lcnt = rcnt = 1;
        lslope = rslope = inf;
        ans = 1;
        empty = 0;
    }
    node(ll constant, ll slope, ll sz){
        lval = constant;
        rval = constant+(sz-1)*slope;
        this->sz = sz;
 
        ans = lcnt = rcnt = sz;
        lslope = rslope = slope;
 
        empty = 0;
    }
    void updlazy(ll constant, ll slope){
        lval += constant;
        rval += constant+(sz-1)*slope;
        lslope += slope;
        rslope += slope;
    }
};
node merge(node a, node b){
    if(a.empty) return b;
    if(b.empty) return a;
    
    node ret;
    ret.empty = 0;
 
    ret.sz = a.sz+b.sz;
    ret.lval = a.lval;
    ret.rval = b.rval;
 
    ret.lcnt = a.lcnt;
    ret.lslope = a.lslope;
 
    ret.rcnt = b.rcnt;
    ret.rslope = b.rslope;
 
    ret.ans = max(a.ans, b.ans);
    
    
    ll mslope = b.lval-a.rval;
    
    ll acnt = 1;
    if(mslope == a.rslope)
        acnt = a.rcnt;
    
    ll bcnt = 1;
    if(mslope == b.lslope)
        bcnt = b.lcnt;
    
    ret.ans = max(ret.ans, acnt+bcnt);
    if(acnt == a.sz){
        ret.lcnt = acnt+bcnt;
        ret.lslope = mslope;
    }
    if(bcnt == b.sz){
        ret.rcnt = acnt+bcnt;
        ret.rslope = mslope;
    }
    return ret;
}
ll change[1200009];
pll cval[1200009];
pll add[1200009];
node seg[1200009];
void push(int v, int tl, int tm, int tr){
    if(change[v]){
        change[v] = 0;
        
        seg[2*v] = node(cval[v].ff, cval[v].ss, (tm-tl+1));
        change[2*v] = 1;
        cval[2*v] = {cval[v].ff, cval[v].ss};
        add[2*v] = {0, 0};
 
        cval[v].ff += (tm-tl+1)*cval[v].ss;
        seg[2*v+1] = node(cval[v].ff, cval[v].ss, (tr-tm));
        change[2*v+1] = 1;
        cval[2*v+1] = {cval[v].ff, cval[v].ss};
        add[2*v+1] = {0, 0};
    }
 
    seg[2*v].updlazy(add[v].ff, add[v].ss);
    add[2*v].ff += add[v].ff;
    add[2*v].ss += add[v].ss;
    
    add[v].ff += (tm-tl+1)*add[v].ss;
    seg[2*v+1].updlazy(add[v].ff, add[v].ss);
    add[2*v+1].ff += add[v].ff;
    add[2*v+1].ss += add[v].ss;
    
    add[v] = {0, 0};
}
ll a[300009];
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        seg[v] = node(a[tl]);
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);
    seg[v] = merge(seg[2*v], seg[2*v+1]);
}
node get(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || l > tr)
        return node();
    if(l <= tl && tr <= r)
        return seg[v];
    ll tm = (tl+tr)/2;
    push(v, tl, tm, tr);
    return merge(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
}
void upd(ll v, ll tl, ll tr, ll l, ll r, ll type, ll con, ll slope){
    if(tl > r || l > tr)
        return;
    if(l <= tl && tr <= r){
        con += (tl-l)*slope;
        if(type == 0){
            add[v].ff += con;
            add[v].ss += slope;
            seg[v].updlazy(con, slope);
        }
        else{
            add[v] = {0, 0};
            change[v] = 1;
            cval[v] = {con, slope};
            seg[v] = node(con, slope, tr-tl+1);
        }
        return;
    }
    ll tm = (tl+tr)/2;
    push(v, tl, tm, tr);
    upd(2*v, tl, tm, l, r, type, con, slope);
    upd(2*v+1, tm+1, tr, l, r, type, con, slope);
    seg[v] = merge(seg[2*v], seg[2*v+1]);
}
ll n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> q;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n-1);
    while(q--){
        ll type;
        cin >> type;
        if(type == 1){
            ll l, r, s, c;
            cin >> l >> r >> s >> c;
            --l;
            --r;
            upd(1, 0, n-1, l, r, 0, s, c);
        }
        else if(type == 2){
            ll l, r, s, c;
            cin >> l >> r >> s >> c;
            --l;
            --r;
            upd(1, 0, n-1, l, r, 1, s, c);
        }
        else{
            ll l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << get(1, 0, n-1, l, r).ans << '\n';
        }
    }
}
