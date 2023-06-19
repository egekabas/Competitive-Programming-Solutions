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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
ll sq = 300;
ll mod = 2987623948576237;
ll n;
ll a[70009];
vector<pll> v[70009];
unordered_map<ll, ll> val[70009];
    
ll ans[70009];
char s[70009];
ll tmp[70009];
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        scanf("%s", s);
        for(int j = 0; s[j] != '\0'; ++j){
            a[i] = a[i]*10%mod;
            a[i] += s[j]-'0';
            if(a[i] >= mod)
                a[i]-=mod;
        }
    }
    for(ll i = n; i >= 1; --i){
        a[i] = a[i]-a[i-1]+mod;
        if(a[i] >= mod)
            a[i] -= mod;
    }
    for(ll i = 1; i <= n; ++i){
        ll lookfor = a[i]-1;
        for(ll j = 0;; ++j){
            if(a[i] == 1 || val[j][lookfor]){
                ll seg = j, idx = val[j][lookfor]-1, num = i;
                if(idx == -1)
                    v[seg].insert(v[seg].begin()+idx+1, {a[num], num});
                else
                    v[seg].insert(v[seg].begin()+idx+1, {(seg[v][idx].ff+a[num])%mod, num});
                for(int i = idx+2; i < v[seg].size(); ++i)
                    val[seg].erase(v[seg][i].ff);      
                val[seg][seg[v][idx+1].ff] = idx+2;
                for(int i = idx+2; i < v[seg].size(); ++i){
                    v[seg][i].ff = (a[v[seg][i].ss]+v[seg][i-1].ff);
                    if(v[seg][i].ff >= mod)
                        v[seg][i].ff -= mod;
                    val[seg][v[seg][i].ff] = i+1;
                    //cout << i << " -- " << v[seg][i].ff << '\n';
                }
                
                break;
            }
            lookfor = lookfor-v[j].back().ff+mod;
            if(lookfor >= mod)
                lookfor -= mod;
        }
        if(i%1000 == 0){
            ll tmpcnt = 0;
            for(ll i = 0; v[i].size(); ++i){
                val[i].clear();
                for(auto u : v[i])
                    tmp[tmpcnt++] = (u.ss);
                v[i].clear();
            }
            for(ll i = 0; i < tmpcnt; ++i){
                if(v[i/sq].empty())
                    v[i/sq].pb({a[tmp[i]], tmp[i]});
                else
                    v[i/sq].pb({(a[tmp[i]]+v[i/sq].back().ff)%mod, tmp[i]});    
                
                val[i/sq][v[i/sq].back().ff] = v[i/sq].size();
            }
        }
    }
    ll cur = 1;
    for(ll i = 0; v[i].size(); ++i)
        for(auto u : v[i])
            ans[u.ss] = cur++;
    for(ll i = 1; i <= n; ++i){
        printf("%lld ", ans[i]);
    }
}
