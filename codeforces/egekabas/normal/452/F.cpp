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
ll mod = 1e9+7;
ll p = 3;
ll ps[300010];
pll hashmerge(pll h1, ll s1, pll h2, ll s2){
    ll t1 = (h2.ff*ps[s1]%mod+h1.ff)%mod;
    ll t2 = (h1.ss*ps[s2]%mod+h2.ss)%mod;
    return {t1, t2};
}
pll seg[1200000];
void upd(ll v, ll tl, ll tr, ll idx){
    if(idx < tl || idx > tr)
        return;
    else if(tl == idx && tr == idx){
        seg[v] = {1, 1};
        return;
    }
    else{
        ll tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx);
        upd(2*v+1, tm+1, tr, idx);
        seg[v] = hashmerge(seg[2*v], tm-tl+1, seg[2*v+1], tr-tm);
    }
}
pll get(ll v, ll tl, ll tr, ll l, ll r){
    if(r < tl || tr < l)
        return {0, 0};
    else if(l <= tl && tr <= r)
        return seg[v];
    else{
        ll tm = (tl+tr)/2;
        pll h1 = get(2*v, tl, tm, l, r);
        ll s1 = min(r, tm)-max(tl, l)+1; s1 = max(s1, (ll)0);
        pll h2 = get(2*v+1, tm+1, tr, l, r);
        ll s2 = min(r, tr)-max(tm+1, l)+1;s2 = max(s2, (ll)0);
        return hashmerge(h1, s1, h2, s2);
    }
}

ll n;
ll a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    

    ps[0] = 1;
    for(ll i = 1; i <= 300002; ++i)
        ps[i] = p*ps[i-1]%mod;

    
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> a;
        upd(1, 1, n, a);
        if(a == 1 || a == n)
            continue;
        int size = min(a-1, n-a);
        pll tmp = get(1, 1, n, a-size, a+size);

        if(tmp.ff != tmp.ss){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    
}