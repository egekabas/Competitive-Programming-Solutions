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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n, m;
ll a[200009];
bool dig[800009][10];
pll seg[800009][10];
pll merge(pll a, pll b){
    pll ret;
    if(a.ff < b.ff){
        ret.ff = a.ff;
        ret.ss = min(a.ss, b.ff);
    }
    else if(b.ff < a.ff){
        ret.ff = b.ff;
        ret.ss = min(b.ss, a.ff);
    }
    else if(b.ff == a.ff)
        ret.ff = ret.ss = a.ff;
    return ret;
}
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        for(ll i = 0; i <= 9; ++i){
            if(dig[tl][i] == 1)
                seg[v][i] = {a[tl], 1e18};
            else
                seg[v][i] = {1e18, 1e18};
        }
    }
    else{
        ll tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        for(ll i = 0; i <= 9; ++i)
            seg[v][i] = merge(seg[2*v][i], seg[2*v+1][i]);
        
    }
}
void update(ll v, ll tl, ll tr, ll idx){
    if(idx < tl || idx > tr)
        return;
    else if(tl == tr){
        for(ll i = 0; i <= 9; ++i){
            if(dig[tl][i] == 1)
                seg[v][i] = {a[tl], 1e18};
            else
                seg[v][i] = {1e18, 1e18};
        }
    }
    else{
        ll tm = (tl+tr)/2;
        update(2*v, tl, tm, idx);
        update(2*v+1, tm+1, tr, idx);
        for(ll i = 0; i <= 9; ++i)
            seg[v][i] = merge(seg[2*v][i], seg[2*v+1][i]);
    }
}

pll quer(ll v, ll tl, ll tr, ll l, ll r, ll d){
    if(tl > r || tr < l){
        return {1e18, 1e18};
    }
    else if(tl >= l && tr <= r){
        return seg[v][d];
    }
    else{
        ll tm = (tl+tr)/2;;
        return merge(quer(2*v, tl, tm, l, r, d), quer(2*v+1, tm+1, tr, l, r, d));
    }
}
int main() {
 
 
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);
        ll cur = 0;
        ll temp = a[i];
        while(temp > 0){
            if(temp%10 > 0)
                dig[i][cur] = 1;
            temp /= 10;
            ++cur;
        }
    }
    build(1, 1, n);
    while(m--){
        ll c, x, y;
        scanf("%lld %lld %lld", &c, &x, &y);
        if(c == 1){
            a[x] = y;
            for(ll i = 0; i <= 9; ++i)
                dig[x][i] = 0;
            ll temp = a[x];
            ll cur = 0;
            while(temp > 0){
                if(temp%10 > 0)
                    dig[x][cur] = 1;
                temp /= 10;
                ++cur;
            }
            update(1, 1, n, x);
        }
        else{
            ll ans = 1e18;
            for(ll i = 0; i <= 9; ++i){
                pll par = quer(1, 1, n, x, y, i);
                ans = min(ans, par.ff + par.ss);
            }
            if(ans >= 1e18)
                printf("-1\n");
            else
                printf("%lld\n", ans);
        }
    }
}