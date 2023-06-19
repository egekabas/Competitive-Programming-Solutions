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
ll maxn = 18;
struct node{
    vector<ll> sw;
    vector<ll> rev;
    ll sum = 0, lev;
    node *lef = nullptr, *rig = nullptr;
    node(ll l){
        lev = l;
        sw.resize(maxn+1);
        rev.resize(maxn+1);
    }
    void push(){
        if(lev == 0) return;
        if(sw[lev])
            swap(lef, rig);
        if(rev[lev]){
            swap(lef, rig);
            rev[lev-1] ^= 1;
        }
        for(ll i = 0; i < lev; ++i){
            lef->sw[i] ^= sw[i];
            lef->rev[i] ^= rev[i];
            rig->sw[i] ^= sw[i];
            rig->rev[i] ^= rev[i];
        }
        for(ll i = 0; i <= maxn; ++i)
            sw[i] = rev[i] = 0;
    }
    void build(){
        if(lev == 0)
            return;
        lef = new node(lev-1);
        rig = new node(lev-1);
        lef->build();
        rig->build();
    }
    ll get(ll tl, ll tr, ll l, ll r){
        if(tr < l || r < tl)
            return 0;
        if(l <= tl && tr <= r)
            return sum;
        push();
        return lef->get(tl, (tl+tr)/2, l, r)+rig->get((tl+tr)/2+1, tr, l, r);
    }
    void upd(ll tl, ll tr, ll idx, ll val){
        if(tr < idx || idx < tl)
            return;

        if(idx == tl && idx == tr){
            //cout << lev << ' ' << sum << '\n';
            sum = val;
            return;
        }
        push();
        lef->upd(tl, (tl+tr)/2, idx, val);
        rig->upd((tl+tr)/2+1, tr, idx, val);
        sum = lef->sum+rig->sum;
    }
};
ll n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    node root = node(n);
    root.build();
    for(ll i = 0; i < (1<<n); ++i){
        ll val;
        cin >> val;
        root.upd(0, (1<<n)-1, i, val);
    }
    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll x, k;
            cin >> x >> k;
            root.upd(0, (1<<n)-1, x-1, k);
        }
        else if(t == 2){
            ll k;
            cin >> k;
            root.rev[k] ^= 1;
        }
        else if(t == 3){
            ll k;
            cin >> k;
            root.sw[k+1] ^= 1;
        }
        else{
            ll l, r;
            cin >> l >> r;
            cout << root.get(0, (1<<n)-1, l-1, r-1) << '\n';
        }
    }
}