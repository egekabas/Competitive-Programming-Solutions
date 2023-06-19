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
ll go[1000009][30];
ll cnt[1000009];
ll ans[1000009];
ll dest[1000009];
ll n, k;
void precalc(ll root){
    for(ll i = 0; i <= 'z'-'a'; ++i)
        if(go[root][i] != 0){
            precalc(go[root][i]);
            cnt[root] += cnt[go[root][i]];
        }
}
void calc(ll root, ll bef, ll dis){
    if(bef >= dis)
        bef = dis;
    bef += dest[root];
    if(dest[root]){
        ans[root] = min(bef, dis);
        dis = min(bef, dis);
    }
    //ans[root] = min(bef+1, dis);
    //bef += dest[root];
    for(ll i = 0; i <= 'z'-'a'; ++i)
        if(go[root][i] != 0 && cnt[go[root][i]] != 0){
            calc(go[root][i], bef, dis+1);
            bef += cnt[go[root][i]];
        }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        ll tmp;
        char c;
        cin >> tmp >> c;
        go[tmp][c-'a'] = i;
    }
    cin >> k;
    vector<ll> v;
    for(ll i = 1; i <= k; ++i){
        ll tmp;
        cin >> tmp;
        cnt[tmp]++;
        dest[tmp]++;
        v.pb(tmp);
    }
    precalc(0);
    calc(0, 0, 0);
    for(auto u : v)
        cout << ans[u] << ' ';
}