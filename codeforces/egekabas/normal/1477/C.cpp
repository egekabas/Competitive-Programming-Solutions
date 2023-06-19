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
pll a[5009];
ll n;
ll dis(pll x, pll y){
    return (x.ff-y.ff)*(x.ff-y.ff)+(x.ss-y.ss)*(x.ss-y.ss);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].ff >> a[i].ss;
    pll last = a[1];
    a[1] = {-1e9-7, -1e9-7};
    cout << "1 ";
    ll cnt = n-1;
    while(cnt--){
        ll maxid = -1;
        for(ll i = 1; i <= n; ++i){
            if(a[i].ff == -1e9-7) continue;
            if(maxid == -1) maxid = i;
            else if(dis(last, a[i]) > dis(last, a[maxid]))
                maxid = i;
        }
        cout << maxid << ' ';
        last = a[maxid];
        a[maxid] = {-1e9-7, -1e9-7};
    }
}