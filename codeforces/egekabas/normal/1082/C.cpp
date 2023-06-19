#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n, m;
multiset<ll> s[100009];
ll vals[100009];

int main(){
    cin >> n >> m;
    ll x, y;
    for(ll i = 0; i < n; ++i){
        cin >> x >> y;
        s[x].insert(-y);
    }
    for(ll i = 1; i <= m; ++i){
        set<ll>::iterator itr;
        ll tmp = 0;
        ll cnt = 0;
        for(itr = s[i].begin();itr != s[i].end() ; ++itr){
            tmp += *itr;
            if(tmp <= 0)
                vals[cnt] += tmp;
            //cout << "speciality==>" << i << "   " 
            //<< "number==>" << cnt << "  "
            //<< "val==> " << tmp << endl; 
            ++cnt;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        ans = min(ans, vals[i]);
        //cout << i << " ==> " << vals[i] << endl;
    }
    if(ans >= 0)
        ans = 0;
    cout << -ans << endl;
}