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
ll n, q;
ll a[200009];
ll ans[200009];
struct node{
    ll l, r, d, u, idx, ans;
};
ll s1(node a, node b){
    return a.l < b.l;
}
ll s2(node a, node b){
    return a.r > b.r;
}

ll bit[200009];
void upd(ll idx, ll val){
    for(; idx <= n; idx += idx&(-idx))
        bit[idx] += val;
}
ll get(ll idx){
    ll ret = 0;
    for(; idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}
ll comb(ll x){
    return x*(x-1)/2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    vector<node> b(q);
    for(ll i = 0; i < q; ++i){
        cin >> b[i].l >> b[i].d >> b[i].r >> b[i].u;
        b[i].idx = i;
    }
    sort(all(b), s1);
    ll idx = 1;
    for(auto &u : b){
        while(idx < u.l){
            upd(a[idx], 1);
            ++idx;
        }
        u.ans += comb(get(n));
        u.ans -= comb(get(u.d-1));
        u.ans -= comb(get(n)-get(u.u));
    }
    while(idx <= n){
        upd(a[idx], 1);
        ++idx;
    }
    for(auto &u : b){
        u.ans += comb(get(u.d-1));
        u.ans += comb(get(n)-get(u.u));
    }
    for(ll i = 0; i <= n; ++i)
        bit[i] = 0;
    
    sort(all(b), s2);
    idx = n;
    for(auto &u : b){
        while(idx > u.r){
            upd(a[idx], 1);
            --idx;
        }
        u.ans += comb(get(n));
        u.ans -= comb(get(u.d-1));
        u.ans -= comb(get(n)-get(u.u));
    }

    for(auto u : b)
        ans[u.idx] = comb(n)-u.ans;
    for(ll i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}