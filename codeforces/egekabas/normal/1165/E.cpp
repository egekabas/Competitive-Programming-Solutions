#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
const long long mod = 998244353;
ll n;
ll a[1000009];
multiset<ll> b,s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    ll tmp;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        b.insert(tmp);
    }
    for(int i = 0; i < n; ++i){
        tmp = (i+1)*(n-i)*a[i];
        s.insert(tmp);
    }
    auto it1 = s.begin();
    auto it2 = b.end();
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        --it2;
        ans = (ans + ((*it1%mod)*(*it2%mod))%mod)%mod;
        ++it1;
    }
    cout << ans << endl;
}