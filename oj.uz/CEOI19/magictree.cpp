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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
vector<pii> v1;
vector<pii> v2;
struct vertex{
    ll left, right;
    ll maxi = 0, lazy = 0, sz = 0;
    vertex *lchild = nullptr, *rchild = nullptr;
    vertex(){}
    vertex(ll lb, ll rb){
        left = lb;
        right = rb;
    }
    void push(){
        if(lchild){
            lchild->lazy += lazy;
            lchild->maxi += lazy;
        }
        if(rchild){
            rchild->lazy += lazy;
            rchild->maxi += lazy;
        }
        lazy = 0;
    }
    void pull(){
        maxi = 0;
        if(lchild)
            maxi = max(maxi, lchild->maxi);
        if(rchild)
            maxi = max(maxi, rchild->maxi);
    }
    void add(ll idx, ll val){
        ++sz;
        if(left == idx && right == idx){
            maxi = max(maxi, val);
            return;
        }
        push();
        if(idx <= (left+right)/2){
            if(!lchild)
                lchild = new vertex(left, (left+right)/2);
            lchild->add(idx, val);
        }
        else{
            if(!rchild)
                rchild = new vertex((left+right)/2+1, right);
            rchild->add(idx, val);    
        }
        pull();
    }
    void upd(ll l, ll r, ll val){
        if(right < l || r < left)
            return;
        if(l <= left && right <= r){
            maxi += val;
            lazy += val;
            return;
        }
        push();
        if(lchild)
            lchild->upd(l, r, val);
        if(rchild)
            rchild->upd(l, r, val);
        pull();
    }
    ll get(ll l, ll r){
        if(right < l || r < left)
            return 0;
        if(l <= left && right <= r){
            return maxi;
        }
        push();
        ll ret = 0;
        if(lchild)
            ret = max(ret, lchild->get(l, r));
        if(rchild)
            ret = max(ret, rchild->get(l, r));
        return ret;
    }
    void dfs(){
        if(left == right){
            v1.pb({left, maxi});
            if(v2.empty() || maxi > v2.back().ss)
                v2.pb({left, maxi});
            return;
        }
        push();
        if(lchild)
            lchild->dfs();
        if(rchild)
            rchild->dfs();
        delete lchild;
        delete rchild;
    }
};
vector<ll> g[100009];
ll n, m, k;
pii val[100009];
void merge(vertex &a, vertex &b){
    if(b.sz > a.sz)
        swap(a, b);
    v1.clear();
    v2.clear();
    b.dfs();
    for(auto &u : v1){
        u.ss += a.get(1, u.ff);
    }
    for(ll i = 0; i < v2.size(); ++i){
        ll val;
        if(i == 0)
            val = v2[i].ss;
        else
            val = v2[i].ss-v2[i-1].ss;
        a.upd(v2[i].ff, k, val);
    }
    for(auto u : v1){
        a.add(u.ff, u.ss);
    }
    //cout << '\n';
}
vertex seg[100009];
void dfs(ll v){
    seg[v] = vertex(1, k);
    for(auto u : g[v]){
        dfs(u);
        merge(seg[v], seg[u]);
    }
 
    if(val[v].ff){
        seg[v].add(val[v].ff, val[v].ss+seg[v].get(1, val[v].ff));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m >> k;
 
    for(ll i = 2; i <= n; ++i){
        ll p;
        cin >> p;
        g[p].pb(i);
    }
    for(ll i = 0; i < m; ++i){
        ll v, d, w;
        cin >> v >> d >> w;
        val[v] = {d, w};
    }
    dfs(1);
    cout << seg[1].maxi << '\n';
}
