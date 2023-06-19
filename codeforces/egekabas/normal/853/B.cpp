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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n, m, k;
vector<pair<ll, pii>> vec[2];
ll cur[100009];
ll cost[2][1000009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> k;

    for(ll i = 0; i < m; ++i){
        ll d, x, y, c;
        cin >> d >> x >> y >> c;
        if(y == 0)
            vec[0].pb({d, {x, c}});
        else
            vec[1].pb({d, {y, c}});
    }
    sort(all(vec[0]));
    sort(all(vec[1]));
    reverse(all(vec[1]));

    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        cur[i] = 1e11+7;
        ans += cur[i];
    }
    auto it = vec[0].begin();
    for(ll i = 0; i <= 1e6; ++i){
        while(it != vec[0].end() && it->ff < i){
            ans -= cur[it->ss.ff];
            cur[it->ss.ff] = min(cur[it->ss.ff], (ll)it->ss.ss);
            ans += cur[it->ss.ff];
            ++it;
        }
        cost[0][i] = ans;
    }
    
    ans = 0;
    for(ll i = 1; i <= n; ++i){
        cur[i] = 1e11+7;
        ans += cur[i];
    }
    it = vec[1].begin();
    for(ll i = 1e6; i >= 0; --i){
        while(it != vec[1].end() && it->ff > i){
            ans -= cur[it->ss.ff];
            cur[it->ss.ff] = min(cur[it->ss.ff], (ll)it->ss.ss);
            ans += cur[it->ss.ff];
            ++it;
        }
        cost[1][i] = ans;
    }

    ll fin = 1e18+7;
    for(ll i = 0; i+k-1 <= 1e6; ++i)
        fin = min(fin, cost[0][i]+cost[1][i+k-1]);
    if(fin < 1e11+7)
        cout << fin << '\n';
    else
        cout << "-1\n";
}