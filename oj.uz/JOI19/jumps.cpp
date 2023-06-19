#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pii;
typedef pair<ull, ull>    pull;
typedef pair<ld, ld>  pld;
pii merge(pii a, pii b){
    return mp(max(a.ff, b.ff), max(a.ss, b.ss));
}
int n;
int a[500009];
pii seg[2000009];
int lazy[2000009];
void push(int v){
    lazy[2*v] = max(lazy[2*v], lazy[v]);
    lazy[2*v+1] = max(lazy[2*v+1], lazy[v]);
    seg[2*v].ff = max(seg[2*v].ff, seg[2*v].ss+lazy[2*v]);
    seg[2*v+1].ff = max(seg[2*v+1].ff, seg[2*v+1].ss+lazy[2*v+1]);
    lazy[v] = 0;
}
void build(int v, int tl, int tr){
    if(tl == tr){
        seg[v] = {a[tl], a[tl]};
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);
    seg[v] = merge(seg[2*v], seg[2*v+1]);
}
void upd(int v, int tl, int tr, int l, int r, int val){
    if(r < tl || tr < l)
        return;
    if(l <= tl && tr <= r){
        lazy[v] = max(lazy[v], val);
        seg[v].ff = max(seg[v].ff, seg[v].ss+lazy[v]);
    }
    else{
        push(v);
        upd(2*v, tl, (tl+tr)/2, l, r, val);
        upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
pii get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return {0, 0};
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        push(v);
        return merge(get(2*v, tl, (tl+tr)/2, l, r), get(2*v+1, (tl+tr)/2+1, tr, l, r));
    }
}
int q;
vector<pii> qu[500009];
int ans[500009];
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n-1);
    cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        qu[l-1].pb({r-1, i});
    }
    deque<pii> inc;
    for(int i = n-1; i >= 0; --i){
        for(auto u : inc){
            upd(1, 0, n-1, 2*u.ss-i, n-1, a[i]+u.ff);
            if(u.ff >= a[i])
                break;
        }
        while(inc.size() > 0){
            if(inc.front().ff <= a[i])
                inc.pop_front();
            else
                break;
        }
        inc.push_front({a[i], i});
        for(auto u : qu[i])
            ans[u.ss] = get(1, 0, n-1, i+2, u.ff).ff;
 
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
