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
ll n, q = 13;
ll ans[1009];
ll newval[1009];
vector<ll> ask[30];
ll orval[1009];
ll query(vector<ll> v){
    if(v.empty()) return 0;
    cout << "? " << v.size();
    for(auto u : v)
        cout << ' ' << u+1;
    cout << endl;
    ll ret;
    cin >> ret;
    return ret;
}
int main() {
    cin >> n;
    ll curassign = 0;
    for(ll i = 0; i < (1<<q) && curassign < n; ++i){
        if(__builtin_popcountll(i) != q/2)
            continue;
        newval[curassign] = i;
        for(ll j = 0; j < q; ++j)
            if((i&(1<<j)) == 0)
                ask[j].pb(curassign);
        ++curassign;
    }
    for(ll i = 0; i < q; ++i)
        orval[i] = query(ask[i]);
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < q; ++j)
            if((newval[i]&(1<<j)))
                ans[i] |= orval[j];
    cout << "! ";
    for(ll i = 0; i < n; ++i)
        cout << ans[i] << ' ';
}