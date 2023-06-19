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
struct query{
    ll x, y, z, id;
};
struct st{
    ll a, b, id;
};
query qs[100009];
ll n, q;
st sa[100009];
st sb[100009];
ll idplace[100009];
ll sortbya(st x, st y){return x.a < y.a;}
ll sortbyb(st x, st y){return x.b < y.b;}
vector<ll> compress;
ll getid(ll x){return lower_bound(compress.begin(), compress.end(), x)-compress.begin();}
vector<ll> seg[400009];
vector<ll> bit[400009];
ll build(ll v, ll tl, ll tr){
    seg[v].pb(-1);
    if(tl == tr)
        seg[v].pb(getid(sb[tl].a+sb[tl].b));
    else{
        ll tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        seg[v].resize(seg[2*v].size()+seg[2*v+1].size()-1);
        merge(seg[2*v].begin()+1, seg[2*v].end(), seg[2*v+1].begin()+1, seg[2*v+1].end(), seg[v].begin()+1);
    //cout << seg[2*v].size() << ' ' << seg[2*v+1].size() << ' ' << seg[v].size() << '\n';
    }
    bit[v].resize(seg[v].size());
}
ll getbit(ll id, vector<ll> &v){
    ll ret = 0;
    for(;id < v.size(); id += id&(-id))
        ret += v[id];
    return ret;
}
ll updbit(ll id, ll val, vector<ll> &v){
    for(;id > 0; id -= id&(-id))
        v[id] += val;
}
void upd(ll v, ll tl, ll tr, ll id, ll val){
    ll place = lower_bound(seg[v].begin(), seg[v].end(), val)-seg[v].begin();
    updbit(place, 1, bit[v]);
    if(tl != tr){
        ll tm = (tl+tr)/2;
        if(id <= tm)
            upd(2*v, tl, tm, id, val);
        else
            upd(2*v+1, tm+1, tr, id, val);
    }
}
ll get(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(tr < l || r < tl || l > r)
        return 0;
    if(l <= tl && tr <= r){
        ll place = lower_bound(seg[v].begin(), seg[v].end(), val)-seg[v].begin();    
        
        return getbit(place, bit[v]);
    }
    else{
        ll tm = (tl+tr)/2;
        return get(2*v, tl, tm, l, r, val)+get(2*v+1, tm+1, tr, l, r, val);
    }
}
ll ans[100009];
ll sortquery(query a, query b){return a.x > b.x;}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ll i = 0; i < n; ++i){
        cin >> sa[i].a >> sa[i].b;
        compress.pb(sa[i].a+sa[i].b);
        sa[i].id = i;
        sb[i] = sa[i];
    }
    sort(sa, sa+n, sortbya);
    sort(sb, sb+n, sortbyb);
    for(ll i = 0; i < n; ++i)
        idplace[sb[i].id] = i;
    for(ll i = 0; i < q; ++i){
        cin >> qs[i].x >> qs[i].y >> qs[i].z;
        compress.pb(qs[i].z);
        qs[i].id = i; 
    }
    sort(qs, qs+n, sortquery);
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end())-compress.begin());
    build(1, 0, n-1);
    ll cura = n-1;
    for(ll i = 0; i < q; ++i){
        while(cura >= 0 && sa[cura].a >= qs[i].x){
            upd(1, 0, n-1, idplace[sa[cura].id], getid(sa[cura].a+sa[cura].b));
            --cura;
        }
        ll l = 0, r = n;
        while(l < r){
            ll mid = (l+r)/2;
            if(sb[mid].b >= qs[i].y)
                r = mid;
            else
                l = mid+1;
        }
        ans[qs[i].id] = get(1, 0, n-1, l, n-1, getid(qs[i].z));
    }
    for(ll i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
