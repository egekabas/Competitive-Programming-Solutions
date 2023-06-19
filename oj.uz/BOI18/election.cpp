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
int seg[4*500000];
int lazy[4*500000];
void push(int v){
    seg[2*v] += lazy[v];
    seg[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val){
    if(tr < l || r < tl)
        return;
    if(l <= tl && tr <= r){
        seg[v] += val;
        lazy[v] += val;
        return;
    }
    push(v);
    upd(2*v, tl, (tl+tr)/2, l, r, val);
    upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
    seg[v] = min(seg[2*v], seg[2*v+1]);
}
int get(int v, int tl, int tr, int l, int r){
    if(tr < l || r < tl)
        return 1e9;
    if(l <= tl && tr <= r)
        return seg[v];
    push(v);
    return min(get(2*v, tl, (tl+tr)/2, l, r), get(2*v+1, (tl+tr)/2+1, tr, l, r));
}
int n, q;
int a[500009];
vector<pii> ask[500009];
int ans[500009];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'C')
            a[i] = 1;
        else
            a[i] = -1;
    }
    cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        ask[l].pb({r, i});
    }
    deque<int> negs;
    for(int i = n-1; i >= 0; --i){
        if(a[i] == -1)
            negs.push_front(i);
        else{
            upd(1, 0, n, 0, i, 1);
            if(negs.size()){
                upd(1, 0, n, 0, negs[0], -1);
                negs.pop_front();
            }
        }
        for(auto u : ask[i]){
            ans[u.ss] = upper_bound(all(negs), u.ff)-negs.begin();
            ans[u.ss] += max(0, get(1, 0, n, u.ff+1, u.ff+1)-get(1, 0, n, i, u.ff));
        }
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}
