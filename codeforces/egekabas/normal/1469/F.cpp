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
ll n, k;
ll a[200009];
ll check(ll val){
    multiset<pair<pll, pll>> s;
    //curdis begdis curcnt totcnt

    s.insert({{0, 0}, {0, 1}});
    ll tot = 1;
    for(ll i = 0; i < n; ++i){
        pair<pll, pll> p = *s.begin();
        s.erase(s.begin());
        ll con = p.ff.ff;
        p.ss.ff++;
        if(p.ss.ff < p.ss.ss){
            p.ff.ff = p.ff.ss+(p.ss.ff+1)/2;
            s.insert(p);
        }
        --tot;
        tot += min((val-con-1)*2, a[i]-1);
        s.insert({{con+2, con+1}, {1, a[i]}});
        if(tot >= k)
            return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n, greater<ll>());
    
    ll l = 0, r = 2e9+9;
    while(l < r){
        ll m = (l+r)/2;
        if(check(m))
            r = m;
        else
            l = m+1;
    }
    if(l == 2e9+9)
        cout << "-1\n";
    else
        cout << l << '\n';
}