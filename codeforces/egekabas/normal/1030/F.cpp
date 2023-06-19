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
ll mod = 1e9+7;
struct node{
    ll inc = 0, dec = 0, sum = 0, sz = 0, sumpos = 0;
};
node merge(node a, node b){
    node ret;
    ret.sum = a.sum+b.sum;
    ret.sumpos = (a.sumpos+b.sumpos)%mod;
    ret.sz = a.sz+b.sz;
    ret.inc = (a.inc+b.inc+b.sum%mod*a.sz%mod)%mod;
    ret.dec = (b.dec+a.dec+a.sum%mod*b.sz%mod)%mod;
    return ret;
}
node seg[800009];
void upd(ll v, ll tl, ll tr, ll idx, ll val, ll pos){
    if(idx < tl || idx > tr)
        return;
    if(idx == tl && idx == tr)
        seg[v] = {val, val, val, 1, val*pos%mod};
    else{
        ll tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx, val, pos);
        upd(2*v+1, tm+1, tr, idx, val, pos);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
node get(ll v, ll tl, ll tr, ll l, ll r){
    if(r < tl || tr < l)
        return {0, 0, 0, 0};
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        ll tm = (tl+tr)/2;
        return merge(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
    }
}

ll n, q;
ll bit[200009];
ll getbit(ll idx){
    ll ret = 0;
    for(++idx; idx > 0; idx-=idx&(-idx))
        ret += bit[idx];
    return ret;
}
void updbit(ll idx, ll val){
    for(++idx; idx <= n; idx+=idx&(-idx))
        bit[idx] += val;
}
ll a[200009], w[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i){
        cin >> w[i];
        upd(1, 0, n-1, i, w[i], a[i]);
        updbit(i, w[i]);
    }
    while(q--){
        ll x, y;
        cin >> x >> y;
        if(x < 0){
            x = -x;
            --x;
            updbit(x, y-w[x]);
            w[x] = y;
            upd(1, 0, n-1, x, w[x], a[x]);
        }
        else{
            --x;
            --y;
            ll befsum = getbit(x-1);
            ll cursum = (getbit(y)-befsum+1)/2;
            ll l = x, r = y;
            while(l < r){
                ll m = (l+r)/2;
                if(getbit(m)-befsum >= cursum)
                    r = m;
                else
                    l = m+1;
            }
            ll pivot = l;
            node ndlef = get(1, 0, n-1, x, pivot-1);
            node ndrig = get(1, 0, n-1, pivot+1, y);
            ll ans = (ndlef.sum%mod*a[pivot]%mod-ndlef.sumpos-ndlef.dec)%mod;
            ans = (ans+mod)%mod;
            ans += (-ndrig.sum%mod*a[pivot]%mod+ndrig.sumpos-ndrig.inc)%mod;
            ans = (ans+mod)%mod;
            cout << ans << '\n';
        }
    }
}