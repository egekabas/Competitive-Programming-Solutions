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
ll dif(pll x, pll y){
    return abs(x.ff-y.ff)+abs(x.ss-y.ss);
}
ll getval(vector<ll> &v, ll dif){
    ll ret = v[1]-v[0]+v[3]-v[2];
    ll maxdis = max(abs(v[3]-v[0]), abs(v[1]-v[2]));
    ll mindis = abs(v[2]-v[1]);
    if((v[2] <= v[0] && v[0] <= v[3]) || (v[2] <= v[1] && v[1] <= v[3]))
        mindis = 0;
    if((v[0] <= v[2] && v[2] <= v[1]) || (v[0] <= v[3] && v[3] <= v[1]))
        mindis = 0;

    if(dif < mindis)
        return ret + (mindis-dif)*2;
    if(dif > maxdis)
        return ret + (dif-maxdis)*2;
    return ret;
}
vector<ll> f, s;
ll getans(ll val){
    return getval(f, val)+getval(s, val);
}
void solve(){
    vector<pii> v(4);
    for(ll i = 0; i < 4; ++i){
        cin >> v[i].ff >> v[i].ss;
    }
    sort(all(v));
    ll ans = 1e18;
    while(1){
        f.clear();
        s.clear();
        for(auto u : v){
            f.pb(u.ff);
            s.pb(u.ss);
        }
        swap(s[0], s[2]);

        if(f[0] > f[1]) swap(f[0], f[1]);
        if(s[0] > s[1]) swap(s[0], s[1]);
        
        if(f[2] > f[3]) swap(f[2], f[3]);
        if(s[2] > s[3]) swap(s[2], s[3]);
        
        ll l = 0, r = 1e18+7;
        while(l < r){
            ll m = (l+r)/2;
            if(getans(m) < getans(m+1))
                r = m;
            else
                l = m+1;
        }
        
        ans = min(ans, getans(l));
        if(!next_permutation(all(v)))
            break;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}