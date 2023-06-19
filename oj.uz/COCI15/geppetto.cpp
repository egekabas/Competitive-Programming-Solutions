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
ll n, m;
vector<pll> v;
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m;
    while(m--){
        ll t1, t2;
        cin >> t1 >> t2;
        --t1, --t2;
        v.pb({t1, t2});
    }
    ll ret = 0;
    for(ll bit = 0; bit < (1<<n); ++bit){
        for(auto u : v)
            if((bit&(1<<(u.ff))) > 0 && (bit&(1<<(u.ss))) > 0)
                goto END;
        ++ret;
 
        END:;
    }
    cout << ret << "\n";
}
