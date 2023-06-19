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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll a[500000];
ll sum;
vector<ll> v;
ll n, k;
ll comp(ll a, ll b){
    return b<a;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sum = a[n-1];
    v.pb(sum);
    for(ll i = n-2; i >= 1; --i){
        sum = a[i]+sum;
        v.pb(sum);
    }
    sort(v.begin(), v.end(), comp);
    ll ans = sum + a[0];
    for(ll i = 0 ;i < k-1; ++i){
        ans += v[i];
        //cout << v[i] << endl;
    }
    cout << ans << endl;
}