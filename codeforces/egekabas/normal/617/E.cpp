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
ll sq;
ll n, m, k;
ll a[100009];
ll mpp[3000009];
ll cnt;
void remove(ll idx){
    cnt -= mpp[a[idx]^k];
    if((a[idx]^k) == a[idx])
        cnt++;
    
    --mpp[a[idx]];
}
void add(ll idx){
    cnt += mpp[a[idx]^k];
    ++mpp[a[idx]];
}
struct quer{
    ll l, r, no, ans;
};
quer q[100009];
ll sort1(quer x, quer y){
    if(x.l/sq != y.l/sq)
        return x.l/sq < y.l/sq;
    return x.r > y.r;
}
ll sort2(quer x, quer y){
    return x.no < y.no;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m >> k;
    sq = sqrt(n);
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    for(ll i = 1; i <= n; ++i)
        a[i] ^= a[i-1];
    for(ll i = 0; i < m; ++i){
        ll x, y;
        cin >> x >> y;
        --x;
        q[i] = {x, y, i, 0};
    }
    sort(q, q+m, sort1);
    ll l = 0;
    ll r = 0;
    add(0);
    for(ll i = 0; i < m; ++i){
        while(l < q[i].l){
            remove(l);
            ++l;
        }
        while(l > q[i].l){
            add(l-1);
            --l;
        }
        while(r < q[i].r){
            add(r+1);
            ++r;
        }
        while(r > q[i].r){
            remove(r);
            --r;
        }
        q[i].ans = cnt;
    }
    sort(q, q+m, sort2);
    for(ll i = 0; i < m; ++i)
        cout << q[i].ans << "\n";
}