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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n, k;
pii a[200009];

vector<pii> ar[200009];
bool check(ll x){
    if(x == 0){
        for(ll i = 0; i < n; ++i)
            if(a[i].ff/a[i].ss+1 < k)
                return 0;
        return 1;    
    }
    for(ll i = 0; i <= k; ++i)
        ar[i].clear();
    for(ll i = 0; i < n; ++i)
        ar[min(k, a[i].ff/a[i].ss+1)].pb(a[i]);
    ll cur = 0;
    for(ll i = 0; i < k; ++i){
        for(auto u : ar[i]){
            ll needed = u.ss-u.ff%u.ss;
            needed = (needed+x-1)/x;
            if(cur < needed) return 0;
            cur -= needed;
            u.ff += x*needed;
            ar[min(k, u.ff/u.ss+1)].pb(u);
        }
        ++cur;
    }
    return 1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        scanf("%lld", &a[i].ff);
    for(ll i = 0; i < n; ++i)
        scanf("%lld", &a[i].ss);
    
    ll l = 0, r = 2e12+5;
    while(l < r){
        ll m = (l+r)/2;
        if(!check(m))
            l = m+1;
        else
            r = m;
    }
    cout << ((l == 2e12+5) ? -1 : l) << '\n';
}