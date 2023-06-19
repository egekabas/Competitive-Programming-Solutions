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
ll a[3000009];
ll d[3000009];
ll pl[3000009];
ll h, g;
ll n;
void erase(ll v){
    if(a[v] == 0) return;
    if(a[2*v] > a[2*v+1]){
        pl[a[2*v]] = v;
        a[v] = a[2*v];
        erase(2*v);
    }
    else{
        pl[a[2*v+1]] = v;
        a[v] = a[2*v+1];
        erase(2*v+1);    
    }
}
void dfs(ll v, ll depth){
    if(depth > 20) return;
    d[v] = depth;
    dfs(2*v, depth+1);
    dfs(2*v+1, depth+1);
}
ll check(ll v){
    if(a[2*v] == 0 && a[2*v+1] == 0){
        if(d[v] == g) return 0;
        return 1;
    }
    if(a[2*v] > a[2*v+1])
        return check(2*v);
    return check(2*v+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    dfs(1, 1);
    ll t;
    cin >> t;
    while(t--){
        cin >> h >> g;
        n = (1<<h)-1;
        ll sum = 0;
        vector<ll> v;
        for(ll i = 1; i <= n; ++i){
            cin >> a[i];
            sum += a[i];
            pl[a[i]] = i;
            v.pb(a[i]);
        }
        sort(v.begin(), v.end(), greater<ll>());
        vector<ll> ans;
        for(auto u : v){
            if(check(pl[u])){
                ans.pb(pl[u]);
                sum -= u;
                erase(pl[u]);
            }
        }
        cout << sum << '\n';
        for(auto u : ans)
            cout << u << ' ';
        cout << '\n';
        for(ll i = 1; i <= n; ++i)
            a[i] = pl[v[i-1]] = 0;
    }
}