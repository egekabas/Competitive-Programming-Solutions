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
int seg1[1200009];
int lazy1[1200009];
void push1(int v){
    seg1[2*v] += lazy1[v];
    seg1[2*v+1] += lazy1[v];
    lazy1[2*v] += lazy1[v];
    lazy1[2*v+1] += lazy1[v];
    lazy1[v] = 0;
}
void upd1(int v, int tl, int tr, int l, int r, int val){
    if(r < tl || tr < l) return;
    if(l <= tl && tr <= r){
        seg1[v] += val;
        lazy1[v] += val;
    }
    else{
        push1(v);
        int tm = (tl+tr)/2;
        upd1(2*v, tl, tm, l, r, val);
        upd1(2*v+1, tm+1, tr, l, r, val);
        seg1[v] = max(seg1[2*v], seg1[2*v+1]);
    }
}
int get1(int v, int tl, int tr){
    if(tl == tr) return tl;
    push1(v);
    int tm = (tl+tr)/2;
    if(seg1[2*v] > 0)
        return get1(2*v, tl, tm);
    return get1(2*v+1, tm+1, tr);
}
pii seg2[1200009];
void upd2(int v, int tl, int tr, int idx, int val){
    if(idx < tl || tr < idx) return;
    if(idx == tl && idx == tr)
        seg2[v] = {val, idx};
    else{
        int tm = (tl+tr)/2;
        upd2(2*v, tl, tm, idx, val);
        upd2(2*v+1, tm+1, tr, idx, val);
        seg2[v] = max(seg2[2*v], seg2[2*v+1]);
    }
}
pii get2(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l) return {-1e9, -1e9};
    if(l <= tl && tr <= r)
        return seg2[v];
    else{
        int tm = (tl+tr)/2;
        return max(get2(2*v, tl, tm, l, r), get2(2*v+1, tm+1, tr, l, r));
    }
}
int n;
int a[300009];
int b[300009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        upd2(1, 1, n, i, a[i]);
    }
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    for(int i = 1; i <= n; ++i){
        cout << seg2[1].ff << '\n';
        upd1(1, 1, n, b[i], n, 1);
        int idx = get1(1, 1, n);
//        cout << idx << '\n';
        int del = get2(1, 1, n, 1, idx).ss;
        upd1(1, 1, n, del, n, -1);
        upd2(1, 1, n, del, -1e9);
    }
}