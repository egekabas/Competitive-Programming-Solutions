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
    struct node{
        ll l, r;
        vector<vector<ll>> vals;
        ll single;
        node(){
            l = r = -1e18;
        }
        node(ll val){
            l = r = val;
            vals = vector<vector<ll>>(3, vector<ll>(3));    
            single = 1;
        }
    };
    void merge(node &a, node &b, node &c){
        if(a.l == -1e18){
            c = b;
            return;
        }
        if(b.l == -1e18){
            c = a;
            return;
        }
        c.l = a.l;
        c.r = b.r;
        if(c.vals.empty())
            c.vals = vector<vector<ll>>(3, vector<ll>(3));
        for(ll i = 0; i < 3; ++i)
            for(ll j = 0; j < 3; ++j){
                if((a.single && i == ((a.r < b.l)^1)) || (b.single && j == ((a.r < b.l)^1))){
                    c.vals[i][j] = a.vals[i][2]+b.vals[2][j];
                    continue;
                }
                c.vals[i][j] = max(a.vals[i][2]+b.vals[2][j], abs(a.r-b.l)+a.vals[i][a.r < b.l]+b.vals[a.r < b.l][j]);
            }
        c.single = 0;
    }
    node seg[800009];
    ll lazy[800009];
    ll a[200009];
    void init(ll v, ll tl, ll tr){
        if(tl == tr){
            seg[v] = node(a[tl]);
            return;
        }
        init(2*v, tl, (tl+tr)/2);
        init(2*v+1, (tl+tr)/2+1, tr);
        merge(seg[2*v], seg[2*v+1], seg[v]);
    }
    void push(ll v){
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
        
        seg[2*v].l += lazy[v];
        seg[2*v].r += lazy[v];
        
        seg[2*v+1].l += lazy[v];
        seg[2*v+1].r += lazy[v];
        
        lazy[v] = 0;
    }
    void upd(ll v, ll tl, ll tr, ll l, ll r, ll val){
        if(r < tl || tr < l)
            return;
        if(l <= tl && tr <= r){
            lazy[v] += val;
            seg[v].l += val;
            seg[v].r += val;
        }
        else{
            push(v);
            upd(2*v, tl, (tl+tr)/2, l, r, val);
            upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
            merge(seg[2*v], seg[2*v+1], seg[v]);
        }
    }
    ll n, q;
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        cin >> n >> q;
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        init(1, 0, n-1);
        //cout << seg[1].vals[2][2] << '\n';
        while(q--){
            ll x, y, val;
            cin >> x >> y >> val;
            upd(1, 0, n-1, x-1, y-1, val);
            cout << seg[1].vals[2][2] << '\n';
        }
    }
