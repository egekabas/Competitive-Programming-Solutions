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
ll val[1000009];
ll adj[1000009];
map<ll, ll> mpp;
ll mod = 3e9+7;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    val[1] = 1;
    for(ll i = 2; i <= 1e6; ++i)
        val[i] = (val[i-1]*3);
    cin >> n >> m;
    ll t1, t2;
    for(ll i = 0; i < m; ++i){
        cin >> t1 >> t2;
        adj[t1] = (adj[t1]+val[t2]);
        adj[t2] = (adj[t2]+val[t1]);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        ans += mpp[adj[i]]++;
        ans += mpp[(adj[i]+val[i])]++;
    }
    cout << ans << endl;
}