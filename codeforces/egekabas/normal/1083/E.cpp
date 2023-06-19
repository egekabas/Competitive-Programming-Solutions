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
ld cross(pll l1, pll l2){
    return ((ld)(l1.ff-l2.ff))/((ld)(l2.ss-l1.ss));
}
deque<pll> eq;
void add(pll x){
    while(eq.size() >= 2){
        pll a1 = eq[0];
        pll a2 = eq[1];
        if(cross(x, a1) >= cross(x, a2))
            eq.pop_front();
        else
            break;
    }
    eq.push_front(x);
}
ll func(pll a, ll x){
    return a.ff+a.ss*x;
}
ll find(ll x){
    ll l = 0;
    ll r = eq.size()-1;
    while(l < r){
        ll m = (l+r)/2;
        if(func(eq[m+1], x) > func(eq[m], x))
            l = m+1;
        else
            r = m;
    }
    return func(eq[l], x);
} 
struct rect{
    ll x, y, c;
};
rect a[1000000];
ll dp[1000000];
ll n;
ll sf(rect x, rect y){
    return x.y > y.y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y >> a[i].c;
    sort(a, a+n, sf);
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        ll constant = a[i].x*a[i].y-a[i].c;
        dp[i] = constant;
        if(eq.size() > 0){
            dp[i] = max(dp[i], constant+find(a[i].y));
        }
        add({dp[i], -a[i].x});
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}