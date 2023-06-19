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
vector<pll> v;
ll n;
ll dp[100009];
ll a[100009];
ll b[100009];
ld inter(pll a, pll b){
    return ((ld)a.ff-(ld)b.ff)/((ld)b.ss-(ld)a.ss);
}
void add(pll a){
    while(v.size() > 1){
        pll b = *(v.end()-1);
        pll c = *(v.end()-2);
        ld fint = inter(b, c);
        ld sint = inter(a, b);
        if(sint <= fint){
            v.pop_back();
        }
        else{
            v.pb(a);
            return;
        }
    }
    v.pb(a);        
}
ll get(ll x){
    ll l = 0;
    ll r = v.size()-1;
    while(l < r){
        //cout << l << " " << r << "\n";
        ll m = (l+r)/2;
        if(x > inter(v[m], v[m+1]))
            l = m+1;
        else
            r = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    

    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        cin >> b[i];
    dp[0] = b[0];
    add({dp[0], b[0]});
    for(ll i = 1; i < n; ++i){
        ll bef = get(a[i]-1);
        dp[i] = b[i] + v[bef].ff + (a[i]-1)*v[bef].ss;
        add({dp[i], b[i]});
    }
    cout << dp[n-1] << "\n";
}