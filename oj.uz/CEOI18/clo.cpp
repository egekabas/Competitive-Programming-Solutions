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
const ll inf = 1e17;
struct st{
    ll c, f, v;
};
 
ll sf(st a, st b){
    return a.f > b.f;
}
ll n, m;
st a[2009];
st b[2009];
ll dp[2000*50+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i].c >> a[i].f >> a[i].v;
    cin >> m;
    for(ll i = 0; i < m; ++i)
        cin >> b[i].c >> b[i].f >> b[i].v;
    
    sort(a, a+n, sf);
    sort(b, b+m, sf);
    
    for(ll i = 1; i <= 2000*50; ++i)
        dp[i] = -inf;
 
    ll i = 0, j = 0;
    while(i < n || j < m){
        if(i < n && (j == m || a[i].f >= b[j].f)){
            for(ll k = 2000*50-a[i].c; k >= 0; --k)
                dp[k+a[i].c] = max(dp[k+a[i].c], dp[k]-a[i].v);
            ++i;
        }
        else{
            for(ll k = b[j].c; k <= 2000*50; ++k)
                dp[k-b[j].c] = max(dp[k-b[j].c], dp[k]+b[j].v);
            ++j;
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= 2000*50; ++i)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}
