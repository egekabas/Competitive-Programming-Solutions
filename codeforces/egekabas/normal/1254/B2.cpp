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
ll n;
vector<pll> v;
vector<ll> divi;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    cin >> n;
    
    ll tmp = 0;
    for(ll i = 0; i < n; ++i){
        ll t1;
        cin >> t1;
        tmp += t1;
        if(t1)
            v.pb({i, t1});
    }
    for(ll div = 2; div*div <= tmp; ++div){
        if(tmp % div == 0)
            divi.pb(div);
        while(tmp%div == 0)
            tmp /= div;
    }
    if(tmp > 1)
        divi.pb(tmp);
    ll ans = 1e18;
    for(auto div : divi){
        vector<pll> v2;
        ll sum = 0;
        for(auto u : v){
            if(u.ss%div == 0)
                continue;
            if(sum + u.ss%div <= div){
                v2.pb({u.ff, u.ss%div});
            }
            else{
                v2.pb({u.ff, div-sum});
                v2.pb({u.ff, u.ss%div-(div-sum)});
            }
            sum = (sum + u.ss%div)%div;
        }
        //for(auto u : v2)
        //    cout << u.ss << " ";
        //cout << "\n";
        ll curans = 0;
        for(ll i = 0; i < v2.size();){
            ll sum = 0;
            ll right;
            for(right = i; right < v2.size();++right){
                sum += v2[right].ss;
                if(sum >= div){
                    break; 
                }
            }
            if(right == v2.size())
                --right;
            ll mini = 1e18;
            ll after = 0;
            ll before = 0;
            ll aftersing = 0;
            ll beforesing = 0;
            for(ll j = i; j <= right; ++j){
                after += v2[j].ss*(v2[j].ff-v2[i].ff);
                aftersing += v2[j].ss;
            }
            for(ll j = i; j <= right; ++j){
                mini = min(mini, before+after);
                if(j < right){
                    aftersing -= v2[j].ss;
                    after -= aftersing*(v2[j+1].ff-v2[j].ff);
                    beforesing += v2[j].ss;
                    before += beforesing*(v2[j+1].ff-v2[j].ff);
                }
            }
            curans += mini;
            i = right+1;
        }
        ans = min(ans, curans);
    }
    if(ans == 1e18)
        cout << "-1\n";
    else
        cout << ans << "\n";
}