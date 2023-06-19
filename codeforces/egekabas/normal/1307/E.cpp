#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n, m;
ll mod = 1e9+7;
ll a[5009];
vector<ll> cow[5009];
ll lef[5009];
ll rig[5009];
pll merge(pll a, pll b){
    if(a.ff > b.ff)
        return a;
    else if(a.ff < b.ff)
        return b;
    return {a.ff, (a.ss+b.ss)%mod};
}
pll get(ll cid, ll a, ll b){
    if(a > b)
        swap(a, b);
    ll aid = upper_bound(cow[cid].begin(), cow[cid].end(), a)-cow[cid].begin();
    ll bid = upper_bound(cow[cid].begin(), cow[cid].end(), b)-cow[cid].begin();
    //cout << aid << ' ' << bid << '\n';
    if(aid == 0 && bid == 0)
        return {0, 1};
    else if(aid == 0)
        return {1, bid};
    else if(bid < 2)
        return {1, aid+bid};
    else
        return {2, aid*(bid-aid)+(aid-1)*aid};
}
pll calc(ll must){
    pll cur = {0, 1};
    for(ll i = 1; i <= n; ++i){
        if(cow[i].empty() && must == i) return {0, 1};
        if(cow[i].empty()) continue;
        pll tmp;
        if(i != must)
            tmp = get(i, lef[i], rig[i]);   
        else{
            ll lid = lower_bound(cow[i].begin(), cow[i].end(), lef[i])-cow[i].begin();
            if(lid == cow[i].size() || cow[i][lid] != lef[i])
                return {0, 1};
            ll rid = upper_bound(cow[i].begin(), cow[i].end(), rig[i])-cow[i].begin();
            //cout << rig[i] << ' ' << lid << " aa " << rid << '\n';
            if(lid < rid)--rid;
            if(rid == 0)
                tmp = {1, 1};
            else
                tmp = {2, rid};
        }
        cur.ff += tmp.ff;
        cur.ss *= tmp.ss;
        cur.ss %= mod;
    }
    return cur;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        rig[a[i]]++;
    }
    while(m--){
        ll x, y;
        cin >> x >> y;
        cow[x].pb(y);
    }
    for(ll i = 1; i <= n; ++i)
        sort(cow[i].begin(), cow[i].end());
    pll ans = {0, 1};
    ans = merge(ans, calc(-1));
    for(ll i = 0; i < n; ++i){
        rig[a[i]]--;
        lef[a[i]]++;
        ans = merge(ans, calc(a[i]));
//        cout << calc(a[i]).ff << ' ' << calc(a[i]).ss << '\n';
    }
    if(ans.ff == 0)
        ans.ss = 1;
    cout << ans.ff << ' ' << ans.ss << '\n';
}