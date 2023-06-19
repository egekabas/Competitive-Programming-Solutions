#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pll;
typedef pair<ld, ld>  pld;
ll n;
ll a[20009], b[20009], c[20009];
ll m;
ll ac[20009];
vector<pair<ll, pii>> v;
pair<ll, pii> go(pair<ll, pii> x, ll goal){
    if(x.ss.ff >= goal)
        return x;
    if(x.ss.ff <= 100 && goal >= 100){
        x.ss.ss += (100-x.ss.ff)*a[x.ff];
        x.ss.ff = 100;
    }
    if(x.ss.ff <= 200 && goal >= 200){
        x.ss.ss += (200-x.ss.ff)*b[x.ff];
        x.ss.ff = 200;
    }
    if(goal <= 100){
        x.ss.ss += (goal-x.ss.ff)*a[x.ff];
        x.ss.ff = goal;
    }
    else if(goal <= 200){
        x.ss.ss += (goal-x.ss.ff)*b[x.ff];
        x.ss.ff = goal;
    }
    else{
        x.ss.ss += (goal-x.ss.ff)*c[x.ff];
        x.ss.ff = goal;
    }
    return x;
}
ll stmp;
ll sfunc(pair<ll, pii> a, pair<ll, pii> b){
    return a.ss.ss-max((ll)0, (a.ss.ff-stmp)) > b.ss.ss-max((ll)0, (b.ss.ff-stmp));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i];
        v.pb({i, {0, 0}});
    }
    cin >> m;
    for(ll i = 0; i < m; ++i)
        cin >> ac[i];
    for(ll cur = 0; cur < m; ++cur){
        for(ll j = 0; j < v.size(); ++j)
            v[j] = go(v[j], ac[cur]);
        stmp = ac[cur];
        sort(v.begin(), v.end(), sfunc);
        ll i = 0, j = 0;
        while(i < n){
            for(j = i+1; j < n; ++j)
                if(v[i].ss.ss-max((ll)0, (v[i].ss.ff-stmp)) != v[j].ss.ss-max((ll)0, (v[j].ss.ff-stmp)))
                    break;
            ll add = (n-j)%20;
            for(ll k = i; k < j; ++k){
                if(v[k].ss.ff == ac[cur]){
                    v[k].ss.ff += add;
                    v[k].ss.ss += add;
                }
            }
            i = j;
        }
    }
    for(ll j = 0; j < v.size(); ++j){
        v[j] = go(v[j], 300);
        if(v[j].ss.ff > 300){
            v[j].ss.ss -= v[j].ss.ff - 300;
            v[j].ss.ff = 300; 
        }
    }
    sort(v.begin(), v.end());
    for(auto u : v)
        cout << u.ss.ss << "\n";
}
