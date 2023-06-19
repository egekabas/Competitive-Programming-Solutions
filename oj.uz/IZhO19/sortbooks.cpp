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
ll n, m;
ll a[1000009];
vector<pair<pii, ll>> q[1000009];
ll bit[1000009];
void upd(ll idx, ll val){
    for(++idx; idx <= n; idx += idx&(-idx))
        bit[idx] = max(bit[idx], val);
}
ll get(ll idx){
    ll ret = 0;
    for(++idx; idx > 0; idx -= idx&(-idx))
        ret = max(ret, bit[idx]);
    return ret;
}
ll ans[1000009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < m; ++i){
        ll l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        q[l].pb({{r, k}, i});
    }
    vector<ll> vec;
    for(ll i = n-1; i >= 0; --i){
        while(vec.size() && a[vec.back()] < a[i]){
            upd(vec.back(), a[vec.back()]+a[i]);
            vec.pop_back();
        }
        while(vec.size() && a[vec.back()] == a[i])
            vec.pop_back();
        vec.pb(i);
        for(auto u : q[i]){
            ans[u.ss] = (get(u.ff.ff) <= u.ff.ss);
        }        
    }
    for(ll i = 0; i < m; ++i)
        cout << ans[i] << '\n';
}
