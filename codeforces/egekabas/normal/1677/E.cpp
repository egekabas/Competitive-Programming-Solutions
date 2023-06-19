#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n, q;
ll a[200009];
vector<pii> qu[200009];

ll idx[200009];
ll big[200009];
ll mini[200009];
ll nxt[200009];

struct Seg{
    ll lazy[4*200009], seg[4*200009];

    Seg(ll n){
        memset(lazy, 0, sizeof(lazy));
        memset(seg, 0, sizeof(seg));
    } 

    void push(ll v, ll tl, ll tm, ll tr){
        
        seg[2*v] += (tm-tl+1)*lazy[v];
        seg[2*v+1] += (tr-tm)*lazy[v];
        
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
        
        lazy[v] = 0;
    }
    void upd(ll v, ll tl, ll tr, ll l, ll r, ll val){
        if(tr < l || r < tl)
            return;
        if(l <= tl && tr <= r){
            seg[v] += val*(tr-tl+1);
            lazy[v] += val;
            
        }
        else{
            ll tm = (tl+tr)/2;
            push(v, tl, tm, tr);
            upd(2*v, tl, tm, l, r, val);
            upd(2*v+1, tm+1, tr, l, r, val);
            seg[v] = seg[2*v]+seg[2*v+1];
        }
    }

    ll get(ll v, ll tl, ll tr, ll l, ll r){
        if(tr < l || r < tl)
            return 0;
        if(l <= tl && tr <= r)
            return seg[v];
        else{
            ll tm = (tl+tr)/2;
            push(v, tl, tm, tr);
            return get(2*v, tl, tm, l, r)+get(2*v+1, tm+1, tr, l, r);
        }
    }
};
ll ans[1000009];
int main(){

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%lld%lld", &n, &q);

    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);

        
        idx[a[i]] = i;
        big[i] = 0;
        mini[i] = 1e9;
        nxt[i] = n+1;
    }
    
    for(ll i = 0; i < q; ++i){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        qu[l].pb({r, i});
    }

    Seg cnt(n);
    Seg sum(n);

    vector<ll> vec = {n+1};
    a[n+1] = 1e9;

    for(ll i = n; i >= 1; --i){
        while(vec.size() && a[vec.back()] < a[i]){
            big[vec.back()] = 0;

            cnt.upd(1, 1, n, mini[vec.back()], nxt[vec.back()]-1, -1);            
            sum.upd(1, 1, n, mini[vec.back()], nxt[vec.back()]-1, -i);
            
            vec.pop_back();
        }
        
        
        big[i] = 1;
        nxt[i] = mini[i] = vec.back();
        vec.pb(i);


        if(sqrt(a[i]) < nxt[i]-i){
            for(ll j = 1; j*j < a[i]; ++j){
                if(a[i]%j == 0 && idx[a[i]/j] >= i && idx[j] >= i)
                    mini[i] = min(mini[i], max(idx[j], idx[a[i]/j]));
            }
        }
        else{
            for(ll j = i+1; j < nxt[i]; ++j)
                if(a[i]%a[j] == 0 && idx[a[i]/a[j]] >= i && a[i]/a[j] != a[j])
                    mini[i] = min(mini[i], max(j, idx[a[i]/a[j]]));
        }
        
        cnt.upd(1, 1, n, mini[i], nxt[i]-1, 1);
        sum.upd(1, 1, n, mini[i], nxt[i]-1, i);
        

        if(n/a[i] < vec.size()){
            for(ll j = a[i]; j <= n; j += a[i]){
                if(big[idx[j]] == 0 || j/a[i] == a[i]) continue;
 
                if(idx[j/a[i]] >= i && idx[j/a[i]] < mini[idx[j]]){
 
                    
                    cnt.upd(1, 1, n, max(idx[j], idx[j/a[i]]), mini[idx[j]]-1, 1);
                    sum.upd(1, 1, n, max(idx[j], idx[j/a[i]]), mini[idx[j]]-1, i);
                    mini[idx[j]] = max(idx[j], idx[j/a[i]]);
                }
            }
        }
        else{
            for(auto j : vec){
                if(j == i || j > n || a[j]%a[i]) continue;
                j = a[j];
                if(big[idx[j]] == 0 || j/a[i] == a[i]) continue;
 
                if(idx[j/a[i]] >= i && idx[j/a[i]] < mini[idx[j]]){
 
                    
                    cnt.upd(1, 1, n, max(idx[j], idx[j/a[i]]), mini[idx[j]]-1, 1);
                    sum.upd(1, 1, n, max(idx[j], idx[j/a[i]]), mini[idx[j]]-1, i);
                    mini[idx[j]] = max(idx[j], idx[j/a[i]]);
                }
            }
        }
        
        for(auto u : qu[i]){
            ans[u.ss] = sum.get(1, 1, n, i, u.ff)-(i-1)*cnt.get(1, 1, n, i, u.ff);
        }

        /*cout << i << '\n';
        //for(auto u : vec)
        //    cout << u << ' ' << mini[u] << ' ' << nxt[u] << '\n';
        for(ll i = 1; i <= n; ++i)
            cout << i << ' ' << cnt.get(1, 1, n, i, i) << ' ' << sum.get(1, 1, n, i, i) << '\n';
    
        cout << '\n';*/
    }


        
    for(ll i = 0; i < q; ++i)
        printf("%lld\n", ans[i]);
}