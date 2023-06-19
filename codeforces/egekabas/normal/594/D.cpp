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
struct quer{
    ll l, r, no;
};
ll n, q;
ll a[1000009];
quer qs[1000009];
ll mod = 1e9+7;
ll bit[1000009];
ll first[1000009];
ll ans[1000009];
ll exp(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y % 2)
            ret = (ret*x)%mod;
        y /= 2;
        x = (x*x)%mod;
    }
    return ret;
}
ll dp[1000009];
ll reverse(ll x){
    if(dp[x] != 0)
        return dp[x];
    return dp[x] = exp(x, mod-2);
}
void upd(ll idx, ll val){
    ++idx;
    while(idx <= n+5){
        bit[idx] = bit[idx]*val%mod;
        idx += idx&(-idx);
    }
}
ll get(ll idx){
    ++idx;
    ll ret = 1;
    while(idx > 0){
        ret = ret*bit[idx]%mod;
        idx -= idx&(-idx);
    }
    return ret;
}
ll sortf(quer a, quer b){
    return a.l > b.l;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    for(int i = 0; i <= n+3; ++i)
        bit[i] = 1;
    for(int i = 0; i < q; ++i){
        ll t1, t2;
        cin >> t1 >> t2;
        qs[i] = {t1, t2, i};
    }
    sort(qs, qs+q, sortf);
    int curl = n+1;
    for(ll i = 0; i < q; ++i){
        while(curl > qs[i].l){
            curl--;
            ll tmp = a[curl];
            upd(curl,a[curl]);
            for(ll j = 2; j <= tmp; ++j){
                if(j*j > tmp)
                    j = tmp;
                if(tmp % j != 0)
                    continue;
                if(first[j] != 0){
                    upd(first[j], j);
                    upd(first[j], reverse(j-1));                    
                }
                first[j]= curl;
                upd(curl, j-1);
                upd(curl, reverse(j));                    
                while(tmp % j == 0)
                    tmp /= j;  
            }
        }
        ans[qs[i].no] = get(qs[i].r);
    }
    for(ll i = 0; i < q; ++i)
        cout << ans[i] << "\n";
}