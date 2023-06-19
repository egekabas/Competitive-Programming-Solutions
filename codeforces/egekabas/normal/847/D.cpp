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
ll n, t, a;
priority_queue<ll> pq;

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> t;
    ll time = t-2;
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        cin >> a;
        if(time < 0) continue;
        pq.push(a-i);
        while(!pq.empty() && pq.top() > time) pq.pop();
        ans = max(ans, (ll)pq.size());
        --time;
    }
    cout << ans;
    
}