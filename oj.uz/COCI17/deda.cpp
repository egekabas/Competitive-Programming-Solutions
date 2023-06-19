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
int seg[1000000];
int n, q;
 
void upd(int v, int tl, int tr, int idx, int val){
    if(idx < tl || tr < idx)
        return;
    if(tl == idx && tr == idx)
        seg[v] = val;
    else{
        int tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx, val);
        upd(2*v+1, tm+1, tr, idx, val);
        seg[v] = min(seg[2*v], seg[2*v+1]);
    }
}
int getmini(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return 1e9;
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        int tm = (tl+tr)/2;
        return min(
            getmini(2*v, tl, tm, l, r),
            getmini(2*v+1, tm+1, tr, l, r));
    }
}
int get(int v, int tl, int tr, int sta, int idx){
    if(tr < idx)
        return -1;
    if(tl == tr)
        return tl;
    else{
        int tm = (tl+tr)/2;
        if(tm >= idx && getmini(2*v, tl, tm, idx, n) <= sta)
            return get(2*v, tl, tm, sta, idx);
        if(getmini(2*v+1, tm+1, tr, idx, n) <= sta)
            return get(2*v+1, tm+1, tr, sta, idx);
        return -1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> q;
    for(int i = 0; i <= 4*n+1; ++i)
        seg[i] = 1e9;
    while(q--){
 
        char c;
        cin >> c;
        if(c == 'M'){
            int x, a;
            cin >> x >> a;
            upd(1, 1, n, a, x);
        }
        else{
            int b, y;
            cin >> b >> y;
            cout << get(1, 1, n, b, y) << "\n";
        }
    }
}
