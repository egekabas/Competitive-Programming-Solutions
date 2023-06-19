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
int n;
vector<pii> v;
int ok(int x){
    int l, r, d, u;
    l = d = 1e9;
    r = u = 0;
    for(int i = 0; i < 4*n+1; ++i){
        if(i == x) continue;
        l = min(l, v[i].ff);
        d = min(d, v[i].ss);
        r = max(r, v[i].ff);
        u = max(u, v[i].ss);
    }
    if(r-l != u-d){
        for(int i = 0; i < 4*n+1; ++i){
            if(i == x) continue;
            if(v[i].ss != u && v[i].ss != d)
                return 0;
        }    
    }
    for(int i = 0; i < 4*n+1; ++i){
        if(i == x) continue;
        if(v[i].ff != l && v[i].ff != r
        && v[i].ss != u && v[i].ss != d)
            return 0;
    }
    return 1;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    int x, y;
    for(int i = 0; i < 4*n+1; ++i){
        cin >> x >> y;
        v.pb({x, y});
    }
    for(int i = 0; i < 4*n+1; ++i){
        if(ok(i)){
            cout << v[i].ff << " " << v[i].ss << endl;
            return 0;
        }
    }
}