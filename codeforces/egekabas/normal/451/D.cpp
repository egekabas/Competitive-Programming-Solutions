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
string s;
vector<pii> v;
ll even, odd;
ll pre[2][2];
ll use = 0;

ll func1(ll x){
    if(x%2 == 0)
        return ((x-2)/2+1)*x/2;
    else
        return ((x-1)/2+1)*(x-1)/2;
}
ll func2(ll x){
    if(x % 2 == 0)
        return (x/2+1)*x/2;
    else
        return ((x-1)/2+1)*(x+1)/2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> s; 
    ll last = 0;
    for(auto u : s){
        if(last != 0 && v[last-1].ff == (u-'a'))
            v[last-1].ss++;
        else{
            v.pb({(u-'a'), 1});
            ++last;
        }
    }
    for(ll i = 0; i < last; ++i){
        even += pre[v[i].ff][0^use]*(v[i].ss/2);
        even += pre[v[i].ff][1^use]*(v[i].ss-v[i].ss/2);
        odd += pre[v[i].ff][1^use]*(v[i].ss/2);
        odd += pre[v[i].ff][0^use]*(v[i].ss-v[i].ss/2);
        if(v[i].ss % 2 == 1)
            use ^= 1;
        pre[v[i].ff][0^use] += (v[i].ss/2);
        even += func1(v[i].ss);
        pre[v[i].ff][1^use] += (v[i].ss-v[i].ss/2);
        odd += func2(v[i].ss);
    }
    cout << even << " " << odd << "\n";
}