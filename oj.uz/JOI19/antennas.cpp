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
const int inf = 1e9+5;
struct node{
    int ans, val;
    node(){
        ans = -1;
        val = inf; 
    }
};
node merge(node &a, node &b){
    node ret;
    ret.ans = max(a.ans, b.ans);
    ret.val = min(a.val, b.val);
    return ret;
}
int n, q;
struct seg{
    node t[800009];
    int lazy[800009];
    void start(){
        for(int i = 0; i <= 4*n; ++i)
            lazy[i] = -inf;
    }
    void push(int v){
        lazy[2*v] = max(lazy[2*v], lazy[v]);
        lazy[2*v+1] = max(lazy[2*v+1], lazy[v]);
        lazy[v] = -inf;
        t[2*v].ans = max(t[2*v].ans, lazy[2*v]-t[2*v].val);
        t[2*v+1].ans = max(t[2*v+1].ans, lazy[2*v+1]-t[2*v+1].val);
    }
    void changeval(int v, int tl, int tr, int idx, int val){
        if(tl == idx && tr == idx){
            t[v].val = val;
            lazy[v] = -inf;
            return;
        }
        push(v);
        if(idx <= (tl+tr)/2)
            changeval(2*v, tl, (tl+tr)/2, idx, val);
        else
            changeval(2*v+1, (tl+tr)/2+1, tr, idx, val);
        t[v] = merge(t[2*v], t[2*v+1]);
    }
    void updrange(int v, int tl, int tr, int l, int r, int val){
        if(tr < l || r < tl)
            return;
        if(l <= tl && tr <= r){
            lazy[v] = max(lazy[v], val);
            t[v].ans = max(t[v].ans, lazy[v]-t[v].val);
        }
        else{
            push(v);
            updrange(2*v, tl, (tl+tr)/2, l, r, val);
            updrange(2*v+1, (tl+tr)/2+1, tr, l, r, val);
            t[v] = merge(t[2*v], t[2*v+1]);
        }
    }
    int get(int v, int tl, int tr, int l, int r){
        if(tr < l || r < tl)
            return -1;
        if(l <= tl && tr <= r){
            return t[v].ans;
        }
        else{
            push(v);
            return max(get(2*v, tl, (tl+tr)/2, l, r), get(2*v+1, (tl+tr)/2+1, tr, l, r));
        }
    }
};
struct ant{
    int h, a, b;
};
ant a[200009];
vector<pii> query[200009];
seg s1, s2;
vector<int> add[200009];
vector<int> erase[200009];
int ans[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i].h >> a[i].a >> a[i].b;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l; --r;
        query[l].pb({r, i});
    }
    s1.start();
    s2.start();
    for(int i = n-1; i >= 0; --i){
        for(auto u : add[i]){
            s1.changeval(1, 0, n-1, u, a[u].h);
            s2.changeval(1, 0, n-1, u, -a[u].h);
        }
        s1.updrange(1, 0, n-1, i+a[i].a, i+a[i].b, a[i].h);
        s2.updrange(1, 0, n-1, i+a[i].a, i+a[i].b, -a[i].h);
    
        for(auto u : query[i])
            ans[u.ss] = max(s1.get(1, 0, n-1, i, u.ff), s2.get(1, 0, n-1, i, u.ff));
        if(i-a[i].a >= 0)
            add[i-a[i].a].pb(i);
        if(i-a[i].b >= 0)
            erase[i-a[i].b].pb(i);
        for(auto u : erase[i]){
            s1.changeval(1, 0, n-1, u, inf);
            s2.changeval(1, 0, n-1, u, inf);
        }
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}   
