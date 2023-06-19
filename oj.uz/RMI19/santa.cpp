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
    int n;
    struct node{
        int x, h, v;
    } a[500009];
    int seg[2000009];
    int lazy[2000009];
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
        }
        else{
            push(v);
            upd(2*v, tl, (tl+tr)/2, l, r, val);
            upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
            seg[v] = min(seg[2*v], seg[2*v+1]);
        }
    }
    int get(int v, int tl, int tr, int l, int r){
        if(tr < l || r < tl)
            return 1e9;
        if(l <= tl && tr <= r)
            return seg[v];
        else{
            push(v);
            return min(
                get(2*v, tl, (tl+tr)/2, l, r),
                get(2*v+1, (tl+tr)/2+1, tr, l, r)
            );
        }
    }
    int used[500009];
    int ans[500009];
    void solve(){
        cin >> n;
        int latest = 0;
        for(int i = 0; i <= 4*n+4; ++i)
            seg[i] = lazy[i] = 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i].x;
        for(int i = 0; i < n; ++i){
            cin >> a[i].h;
            if(a[i].h == 0) latest = i;
        }
        for(int i = 0; i < n; ++i){
            cin >> a[i].v;
            used[i] = -1;
        }
        multiset<int> elf;
        for(int i = 0; i < n; ++i){
            if(a[i].h){
                if(elf.lower_bound(a[i].v) != elf.end()){
                    used[i] = *elf.lower_bound(a[i].v);
                    upd(1, 0, n, used[i], n, 1);
                    elf.erase(elf.lower_bound(a[i].v));
                }
            }   
            else{
                elf.insert(a[i].v);
                upd(1, 0, n, a[i].v, n, -1);
            }
        }
        //cout << seg[1] << '\n';
        int j = n-1;
        for(int i = n-1; i >= 0; --i){
            if(i < latest){
                ans[i] = -1;
                continue;
            }
            while(j >= i || (seg[1] < 0 && j >= 0)){
                if(a[j].h){
                    upd(1, 0, n, a[j].v, n, 1);
                    if(used[j] != -1)
                        upd(1, 0, n, used[j], n, -1);
                }
                --j;
            }
            if(seg[1] < 0) 
                ans[i] = -1;
            else
                ans[i] = 2*a[i].x-a[j+1].x;
            upd(1, 0, n, a[i].v, n, -1);
        }
        for(int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
     
        int t;
        cin >> t;
        while(t--){
            solve();
        }
    }
