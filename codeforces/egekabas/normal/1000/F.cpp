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
int n, q;
int a[500009];
vector<pii> qs[500009];
int ans[500009];

pii seg[2000009];

pii merge(pii a, pii b){
    if(a.ff < b.ff)
        return a;
    return b;
}

void upd(int v, int tl, int tr, int idx, int val){
    if(tr < idx || idx < tl) return;
    if(idx == tl && tr == idx){
        seg[v] = {val, a[idx]};
    }
    else{
        int tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx, val);
        upd(2*v+1, tm+1, tr, idx, val);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
pii get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return {1e9, 1e9};
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        int tm = (tl+tr)/2;
        return merge(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
    }
}
int bef[500009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        qs[r].pb({l, i});
    }

    for(int i = 1; i <= n; ++i){
        upd(1, 1, n, i, bef[a[i]]+1);;
        upd(1, 1, n, bef[a[i]], 1e9);;
        
        bef[a[i]] = i;
        for(auto u : qs[i]){
            pii tmp = get(1, 1, n, u.ff, i);
            if(tmp.ff <= u.ff)
                ans[u.ss] = tmp.ss;
        }
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}