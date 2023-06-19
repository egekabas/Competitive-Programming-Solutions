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
ll n, m, k, x;
string s;
char a[500][500];
vector<char> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m >> k >> x;
    cin >> s;
    ll tot = 1;
    --x;
    for(ll i = 0; i < m; ++i){
        for(ll j = 0; j < k; ++j)
            cin >> a[i][j];
        sort(a[i], a[i]+k);
    }
    for(ll i = 0; i < m; ++i){
        ll tot = 1;
        for(ll j = i+1; j < m; ++j)
            tot = min(tot*k, (ll)1e18);
        ans.pb(a[i][x/tot]);
        x %= tot;        
    }
 
    int i = 0;
    for(auto u : s){
        if(u == '#')
            cout << ans[i++];
        else
            cout << u;
    }
}
