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
ll n, k;
ll a[200009];
ll suf[200009];
ll pre[200009];
ll ans = 1e18;
map<ll, ll> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        mpp[a[i]]++;
    }
    for(auto u : mpp)
        if(u.ss >= k){
            cout << "0\n";
            return 0;
        }
    
    sort(a+1, a+1+n);
    for(ll i = n; i >= 1; --i)
        suf[i] = suf[i+1]+a[i];
    for(ll i = 1; i <= n; ++i)
        pre[i] = a[i]+pre[i-1];
    for(ll i = 1; i <= n; ++i){
        ll curans;
        if(i >= k)
            curans = (a[i]-1)*(i-1)-pre[i-1]+(k-1);
        else
            curans = a[i]*(i-1)-pre[i-1] + suf[i+1]-(n-i)*(a[i]+1)+(k-i);
        if(curans >= 0)
            ans = min(ans, curans);
    }

    reverse(a+1, a+1+n);

    for(ll i = n; i >= 1; --i)
        suf[i] = suf[i+1]+a[i];
    for(ll i = 1; i <= n; ++i)
        pre[i] = a[i]+pre[i-1];
    for(ll i = 1; i <= n; ++i){
        ll curans;
        if(i >= k)
            curans = pre[i-1]+(k-1)-(a[i]+1)*(i-1);
        else
            curans = pre[i-1]-a[i]*(i-1) + (n-i)*(a[i]-1)-suf[i+1]+(k-i);
        if(curans >= 0)
            ans = min(ans, curans);
    }
    cout << ans << '\n';
}