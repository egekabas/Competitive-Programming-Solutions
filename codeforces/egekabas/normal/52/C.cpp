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
 
ll t[9000009];
ll lazy[9000009];
void push(ll v){
    t[2*v] += lazy[v];
    lazy[2*v] += lazy[v];
    t[2*v+1] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    }
    else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return (ll)1e15;
    if (l == tl && r == tr) {
        return t[v];
    }
    push(v);
    ll tm = (tl + tr) / 2;
    return min(sum(v*2, tl, tm, l, min(r, tm))
           , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(ll v, ll tl, ll tr, ll l,ll r , ll add) {
    if(l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
        lazy[v] += add;
    }
    else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l,tm+1), r, add);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
ll n;
ll m;
ll a[2000009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    build(a, 1, 0, n-1);
    cin >> m;
    string str;
    getline(cin, str, '\n');
    while(m--){
        ll x, y, z;
        getline(cin, str, '\n');
        stringstream ss(str);
        ss >> x >> y;
        if(!ss.eof()){
            ss >> z;
            if(x <= y)
                update(1, 0, n-1, x, y, z);
            else{
                update(1, 0, n-1, x, n-1, z);
                update(1, 0, n-1, 0, y, z);
            }
        }
        else{
            if(x <= y)
                cout << sum(1, 0, n-1, x, y) << endl;
            else
                cout << min(sum(1, 0, n-1, x, n-1), sum(1, 0, n-1, 0, y)) << endl;
        }
    }
}