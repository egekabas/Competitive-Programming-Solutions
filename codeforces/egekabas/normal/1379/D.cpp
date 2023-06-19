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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n, h, m, k;
ll a[100009];
vector<ll> mpp;
ll get(ll x){
    return upper_bound(mpp.begin(), mpp.end(), x)-mpp.begin();
}
ll bit[100009];
ll getval(ll x){
    ll ret = 0;
    for(; x > 0; x -= x&(-x))
        ret += bit[x];
    return ret;
}
ll getsum(ll x, ll y){
    if(x > y) return 0;
    return getval(y)-getval(x-1);
}
void upd(ll x, ll y){
    for(; x <= mpp.size(); x += x&(-x))
        bit[x] += y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> h >> m >> k;
    for(ll i = 0; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        a[i] = y%(m/2);
        mpp.pb(a[i]);
    }
    sort(mpp.begin(), mpp.end());
    mpp.resize(unique(mpp.begin(), mpp.end())-mpp.begin());

    for(ll i = 0; i < n; ++i){
        upd(get(a[i]), 1);
    }
    
    pii ans = {1e9, 1e9};
    for(ll i = 0; i < n; ++i){
        ll cur = getsum(get(a[i])+1, get(a[i]+k-1)) + getsum(1, get(a[i]+k-1-m/2));
        ans = min(ans, {cur, a[i]});
    }
    cout << ans.ff << ' ' << (ans.ss+k)%(m/2) << '\n';
    for(ll i = 0; i < n; ++i){
        if(ans.ss < a[i] && a[i] <= ans.ss+k-1)
            cout << i+1 << '\n';
        else if(a[i] <= ans.ss+k-1-m/2)
            cout << i+1 << '\n';
    }
}