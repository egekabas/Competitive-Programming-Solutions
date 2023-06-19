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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int n, m;
int a[300009];
int b[300009];
int seg[4000009];
int lazy[4000009];
int lim = 1e6; 
void push(int v){
    seg[2*v] += lazy[v];
    seg[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val){
    if(tl > r || l > tr)
        return;
    if(l <= tl && tr <= r){
        lazy[v] += val;
        seg[v] += val;
    }
    else{
        int tm = (tl+tr)/2;
        push(v);
        upd(2*v, tl, tm, l, r, val);
        upd(2*v+1, tm+1, tr, l, r, val);
        seg[v] = min(seg[2*v], seg[2*v+1]);
    }
}
int get(int v, int tl, int tr){
    if(tl == tr)
        return tl;
    else{
        int tm = (tl+tr)/2;
        push(v);
        if(seg[2*v+1] < 0)
            return get(2*v+1, tm+1, tr);
        else if(seg[2*v] < 0)
            return get(2*v, tl, tm);
        return -1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        upd(1, 0, lim, 0, a[i], -1);
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
        upd(1, 0, lim, 0, b[i], 1);
    }
    int q;
    cin >> q;
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if(t == 1){
            upd(1, 0, lim, 0, a[x], 1);
            a[x] = y;
            upd(1, 0, lim, 0, a[x], -1);
        }
        else if(t == 2){
            upd(1, 0, lim, 0, b[x], -1);
            b[x] = y;
            upd(1, 0, lim, 0, b[x], 1);
        }
        cout << get(1, 0, lim) << "\n";
    }
}