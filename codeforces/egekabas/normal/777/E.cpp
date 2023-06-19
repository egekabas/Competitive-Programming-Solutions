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
struct node{
    ll a , b, h;
};
node v[100009];
ll n;
stack<ll> dp;
ll func(node a, node b){
    if(a.b != b.b)
        return a.b > b.b;
    if(a.a != b.a)
        return a.a > b.a;
    return a.h > b.h;
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
    ll t1, t2, t3;
    for(ll i = 0; i < n; ++i){
        cin >> t1 >> t2 >> t3;
        v[i] = {t1, t2 ,t3};
    }
    sort(v, v+n, func);    
    ll cur = 0;
    ll ans = 0;
    //dp.push(0);
    for(ll i = 0; i < n; ++i){
        while(!dp.empty() && v[dp.top()].a >= v[i].b){
            cur -= v[dp.top()].h;
            dp.pop();
        }
        cur += v[i].h;
        dp.push(i);
        ans = max(ans, cur);
    }
    cout << ans << endl;
}