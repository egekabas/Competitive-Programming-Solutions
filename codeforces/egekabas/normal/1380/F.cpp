#include <bits/stdc++.h>
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
const ll mod = 998244353;
struct node{
    ll val, lval, rval, noval;
    ll l, r;
};
ll getcomb(ll x, ll y){
    if(x < 0 || y < 0) return 0;
    if(x == 0) return 0;
    x = 10*x+y;
    if(x > 18 || x < 0) return 0;
    if(x <= 9) return x+1;
    return 19-x;
}
node merge(node a, node b){
    ll mergeval = getcomb(a.r,b.l);
    node ret;
    ret.l = a.l;
    ret.r = b.r;
    ret.val = a.val*b.val%mod + a.rval*b.lval*mergeval%mod;
    ret.val %= mod;
    ret.lval = a.lval*b.val%mod + a.noval*b.lval*mergeval%mod;
    ret.lval %= mod;
    ret.rval = a.val*b.rval%mod + a.rval*b.noval*mergeval%mod;
    ret.rval %= mod;
    ret.noval = a.lval*b.rval%mod + a.noval*b.noval*mergeval%mod;
    ret.noval %= mod;
    return ret;
}
node seg[2000009];
void upd(int v, int tl, int tr, int idx, int val){
    if(idx < tl || idx > tr) 
        return;
    if(idx == tl && idx == tr){
        seg[v].val = val+1;
        seg[v].l = seg[v].r = val;
        seg[v].lval = seg[v].rval = 1;
        seg[v].noval = 0;
    }
    else{
        upd(2*v, tl, (tl+tr)/2, idx, val);
        upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
int n, m;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> s;
    for(int i = 0; i < n; ++i)
        upd(1, 0, n-1, i, s[i]-'0');
    while(m--){
        int x, y;
        cin >> x >> y;
        upd(1, 0, n-1, x-1, y);
        cout << seg[1].val << '\n';
    }   
}