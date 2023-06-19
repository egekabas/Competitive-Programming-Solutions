#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, a[1000009];
vector<pii> old, cur;
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    old.resize(n);
    for(ll i = 0; i < n; ++i)
        cin >> old[i].ff;
    for(ll bit = 0; bit < 34; ++bit){
        for(auto u : old)
            if((u.ff&(1LL<<bit)) == 0)
                cur.pb(u);
        for(auto u : old)
            if((u.ff&(1LL<<bit)))
                cur.pb({u.ff, u.ss+(1LL<<bit)});
        
        ll i1, i2, i3;
        i1 = i2 = i3 = n-1;
        ll cnt = 0;
        for(ll i = 0; i < n; ++i){
            i1 = max(i1, i-1);
            i2 = max(i2, i-1);
            i3 = max(i3, i-1);
            
            while(i1 >= i && cur[i].ss+cur[i1].ss >= (1LL<<bit))
                --i1;
            while(i2 >= i && cur[i].ss+cur[i2].ss >= (1LL<<(bit+1)))
                --i2;
            while(i3 >= i && cur[i].ss+cur[i3].ss >= (1LL<<(bit+1))+(1LL<<bit))
                --i3;
            
            cnt += i2-i1+n-1-i3;
        }
        if(cnt%2)
            ans += (1LL<<bit);
        swap(old, cur);
        cur.clear();
    }
    cout << ans << '\n';
}
