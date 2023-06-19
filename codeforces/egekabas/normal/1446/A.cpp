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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
pll a[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll t;
    cin >> t;
    while(t--){
        ll n, w;
        cin >> n >> w;
        for(ll i = 0; i < n; ++i){
            cin >> a[i].ff;
            a[i].ss = i;
        }
        sort(a, a+n, greater<pll>());
        vector<ll> v;
        ll cur = 0;
        for(ll i = 0; i < n; ++i){
            if(cur >= (w+1)/2) break;
            if(cur+a[i].ff > w) continue;
            cur += a[i].ff;
            v.pb(a[i].ss);
        }
        if((w+1)/2 <= cur && cur <= w){
            cout << v.size() << '\n';
            for(auto u : v)
                cout << u+1 << ' ';
            cout << '\n';
        }
        else
            cout << "-1\n";
    }
}