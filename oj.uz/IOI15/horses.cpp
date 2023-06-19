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
const ll mod = 1e9+7;
struct node{
    ll y, lef, rig, lefmod, rigmod;
};
node merge(node a, node b){
    node ret;
    if(a.y > min(mod, a.rig*b.lef)*b.y){
        ret.y = a.y;
        ret.lef = a.lef;
        ret.rig = min(mod, min(mod, a.rig*b.lef)*b.rig);
        ret.lefmod = a.lefmod;
        ret.rigmod = a.rigmod*b.lefmod%mod*b.rigmod%mod;
    }
    else{
        ret.y = b.y;
        ret.lef = min(mod, min(mod, a.lef*a.rig)*b.lef);
        ret.rig = b.rig;
        ret.lefmod = a.lefmod*a.rigmod%mod*b.lefmod%mod;
        ret.rigmod = b.rigmod;
    }
    return ret;
}
node seg[2000009];
ll x[500009];
ll y[500009];
void upd(ll v, ll tl, ll tr, ll idx, ll xval, ll yval){
    if(tl == idx && tr == idx){
        seg[v] = {yval, xval, 1, xval, 1};
        return;
    }
    if(idx <= (tl+tr)/2)
        upd(2*v, tl, (tl+tr)/2, idx, xval, yval);
    else
        upd(2*v+1, (tl+tr)/2+1, tr, idx, xval, yval);
    seg[v] = merge(seg[2*v], seg[2*v+1]);    
}
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        seg[v] = {y[tl], x[tl], 1, x[tl], 1};
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);
    seg[v] = merge(seg[2*v], seg[2*v+1]);    
}
ll n;
int init(int N, int X[], int Y[]) {
  n = N;
    for(int i = 0; i < N; ++i){
        x[i] = X[i];
        y[i] = Y[i];
    }
    build(1, 0, n-1);
    return seg[1].lefmod*seg[1].y%mod;
}
 
int updateX(int pos, int val) {	
    x[pos] = val;
    upd(1, 0, n-1, pos, x[pos], y[pos]);
    return seg[1].lefmod*seg[1].y%mod;
}
 
int updateY(int pos, int val) {
  y[pos] = val;
    upd(1, 0, n-1, pos, x[pos], y[pos]);
    return seg[1].lefmod*seg[1].y%mod;
}
