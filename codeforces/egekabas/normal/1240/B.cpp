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
map<ll, ll> mini;
map<ll, ll> maxi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0; i < n; ++i){
            ll t1;
            cin >> t1;
            if(maxi[t1] == 0)
                mini[t1] = i+1;
            maxi[t1] = max(maxi[t1], i+1);
            mini[t1] = min(mini[t1], i+1);
        }
        vector<pll> v;
        for(auto u : mini)
            if(u.ss > 0)
                v.pb({u.ss, maxi[u.ff]});
        mini.clear();
        maxi.clear();
        
        n = v.size();
        set<pii> s;
        ll maxi = 1;
        ll cur = 1;
        for(ll i = 1; i < n; ++i){
            if(v[i].ff > v[i-1].ss)
                cur++;
            else
                cur = 1;
            maxi = max(cur, maxi);
        }
        cout << n-maxi << "\n";
    }
}