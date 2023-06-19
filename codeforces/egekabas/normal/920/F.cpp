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
ll d[1200009];
ll n, m, a[1200009];
ll sz = 8;
ll seg[1200009];
ll change[1200009];
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        seg[v] = a[tl];
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);
    seg[v] = seg[2*v]+seg[2*v+1];
}
void upd(ll v, ll tl, ll tr, ll l, ll r){
    if(r < tl || tr < l)
        return;
    if(change[v] == sz) return;
    if(tl == tr){
        change[v]++;
        seg[v] = d[seg[v]];
        return;
    }
    upd(2*v, tl, (tl+tr)/2, l, r);
    upd(2*v+1, (tl+tr)/2+1, tr, l, r);
    seg[v] = seg[2*v]+seg[2*v+1];
    change[v] = min(change[2*v], change[2*v+1]);
}
ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || r < tl)
        return 0;
    if(l <= tl && tr <= r)
        return seg[v];
    return get(2*v, tl, (tl+tr)/2, l, r)+get(2*v+1, (tl+tr)/2+1, tr, l, r);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    for(ll i = 1; i <= 1e6; ++i){
        d[i]++;
        for(ll j = 2*i; j <= 1e6; j += i)
            d[j]++;
    }
    cin >> n >> m;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n-1);
    while(m--){
        ll t, x, y;
        cin >> t >> x >> y;
        --x;
        --y;
        if(t == 1)
            upd(1, 0, n-1, x, y);
        else
            cout << get(1, 0, n-1, x, y) << '\n';
    }
}