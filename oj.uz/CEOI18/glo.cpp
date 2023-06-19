#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
struct lis{
    set<pii> s;
    void add(pii nw){
        s.insert(nw);
        auto it = s.lower_bound(nw);
        if(it != s.begin()){
            auto it2 = it;
            --it2;
            if(it2->ss >= it->ss){
                s.erase(it);
                return;
            }
        }
        ++it;
        while(it != s.end()){
            if(it->ss <= nw.ss)
                it = s.erase(it);
            else
                break;
        }
    }
    ll get(ll x){
        auto it = s.lower_bound({x, 0});
        if(it == s.begin())
            return 0;
        --it;
        return it->ss;    
    }
};
lis s1, s2;
ll n, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> x;
    ll ans = 0;
    while(n--){
        ll a;
        cin >> a;
        
        ll val = max(s1.get(a+x), s2.get(a));
        ans = max(ans, val+1);
        s2.add({a, val+1});
 
        
        val = s1.get(a);
        ans = max(ans, val+1);
        s1.add({a, val+1});
 
        
    }
    cout << ans << '\n';
}
