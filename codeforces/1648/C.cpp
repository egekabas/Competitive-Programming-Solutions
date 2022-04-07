#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const ll mod = 998244353;
const ll N = 200000;

ll bit[N+1];
void upd(ll idx, ll val){
    for(; idx <= N; idx += idx&(-idx))
        bit[idx] += val;
}
ll get(ll idx){
    ll ret = 0;
    for(; idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}

ll n, m;
ll a[N+1], b[N+1];
ll cnt[N+1];

ll fact[N+1];

ll exp(ll x, ll y = mod-2){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fact[0] = 1;
    for(ll i = 1; i <= N; ++i)
        fact[i] = fact[i-1]*i%mod;

    cin >> n >> m;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        upd(a[i], 1);
    }

    ll divfin = 1;
    for(ll i = 1; i <= N; ++i)
        divfin = divfin*fact[cnt[i]]%mod;

    for(ll i = 0; i < m; ++i)
        cin >> b[i];
    
    ll ans = 0;
    ll cursit = 1;

    for(ll i = 0; i < min(n, m); ++i){
        ans += get(b[i]-1)*cursit%mod*fact[n-i-1]%mod;
        ans %= mod;

        cursit = cursit*cnt[b[i]]%mod;
        cnt[b[i]]--;
        upd(b[i], -1);
    }
    if(n < m)
        ans = (ans+cursit)%mod;

    ans = ans*exp(divfin)%mod;
    cout << ans << '\n';

}