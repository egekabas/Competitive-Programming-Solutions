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
pii cur;
pii a[109];
ll val[109];
ll add[109];
pii query(ll a){
    ++add[a];
    cout << "+ " << a << endl;
    ll x, y;
    cin >> x >> y;
    return mp(x, y);
}
ll get(ll x){
    if(x == 0) return 2;
    for(ll i = 3; i <= 200; ++i)
        if(i*(i-1)*(i-2)/6 - (i-1)*(i-2)*(i-3)/6 == x)
            return i;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> cur.ff >> cur.ss;

    for(ll i = n-1; i >= 3; --i){
        pii newcur = query(i);
        a[i] = {newcur.ff-cur.ff, newcur.ss-cur.ss};
        cur = newcur;
    }
    pii newcur = query(1);
    a[1] = {newcur.ff-cur.ff, newcur.ss-cur.ss};
    cur = newcur;
    
    newcur = query(2);
    a[2] = {newcur.ff-cur.ff, newcur.ss-cur.ss};
    cur = newcur;
    
    newcur = query(1);
    pii tmp = {newcur.ff-cur.ff, newcur.ss-cur.ss};
    cur = newcur;
    
    val[1] = get(tmp.ff);
    val[3] = tmp.ss-a[1].ss;
    val[2] = tmp.ss/val[3];
    val[4] = (a[2].ss-(val[1]-1)*(val[3]))/val[3];
        
    for(ll i = 5; i <= n; ++i){
        val[i] = (a[i-2].ss-(val[i-3]-add[i-3])*(val[i-4]-add[i-4])-(val[i-3]-add[i-3])*(val[i-1]))/val[i-1];
    }
    cout << "! ";
    for(ll i = 1; i <= n; ++i)
        cout << val[i]-add[i] << ' ';
}