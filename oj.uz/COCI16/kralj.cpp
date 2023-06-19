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
ll n;
ll match[500009];
ll a[500009];
ll b[500009];
vector<ll> v[500009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> match[i];
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        cin >> b[i];
    for(ll i = 0; i < n; ++i)
        v[match[i]-1].pb(i);
    set<pll> s;
    ll sum = 0;
    ll beg = -1;
    for(ll i = 0; i < n; ++i){
        sum--;
        sum += v[i].size();
        s.insert({sum, i});
    }
    ll add = 0;
    ll sum2 = 0;
    for(ll i = 0; i < n; ++i){
        if((*s.begin()).ff+add >= 0){
            beg = i;
            break;
        }
        sum2--;
        sum2 += v[i].size();
        s.erase({sum, i});
        add += 1-v[i].size();
        s.insert({sum-add, i+n});
    }
    //cout << beg << "\n";
    s.clear();
    ll ans = 0;
    for(ll i = beg; i < n; ++i){
        for(auto u : v[i])
            s.insert({b[u], u});
        if(s.lower_bound({a[i], 0}) != s.end()){
            ++ans;
            s.erase(s.lower_bound({a[i], 0}));
        }
        else
            s.erase(s.begin());
    }
    for(ll i = 0; i < beg; ++i){
        //cout << i << " " << beg << "\n";exit(0);
        for(auto u : v[i])
            s.insert({b[u], u});
        if(s.lower_bound({a[i], 0}) != s.end()){
            ++ans;
            s.erase(s.lower_bound({a[i], 0}));
        }
        else
            s.erase(s.begin());
    }
    cout << ans << "\n";
}
