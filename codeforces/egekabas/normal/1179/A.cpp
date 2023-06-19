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
ll n, q;
deque<ll> de;
vector<pii> quer;
pii ans[300009];
ll fin = -1;
ll maxi;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(ll i = 0; i < n; ++i){
        ll t1;
        cin >> t1;
        de.push_back(t1);
        maxi = max(maxi, t1);
    }
    for(ll i = 0; i < q; ++i){
        ll t1;
        cin >> t1;
        quer.pb({t1, i});
    }
    sort(quer.begin(), quer.end());
    ll cur = 0;
    ll a, b;
    for(auto u : quer){
        while(cur < u.ff && fin == -1){
            a = de[0];
            b = de[1];
            if(a == maxi){
                fin = cur+1;
                break;
            }
            de.pop_front();
            de.pop_front();
            if(a > b){
                de.push_front(a);
                de.push_back(b);
            }
            else{
                de.push_front(b);
                de.push_back(a);    
            }
            ++cur;
        }
        if(fin == -1){
            ans[u.ss] = {a, b};
        }
        else{
            ans[u.ss] = {maxi, de[(u.ff-fin)%(n-1)+1]};
        }
    }
    for(ll i = 0; i < q; ++i){
        cout << ans[i].ff << " " << ans[i].ss << "\n";
    }
}