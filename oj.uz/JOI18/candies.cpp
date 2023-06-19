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
ll prt[200009];
ll val[200009];
ll lef[200009];
ll rig[200009];
ll evsum[200009];
ll oddsum[200009];
 
ll findprt(ll x){
    if(prt[x] == x)
        return x;
    return (prt[x] = findprt(prt[x]));
}
void merge(ll x, ll y){
    x = findprt(x);
    y = findprt(y);
    if(x == y) return; 
    prt[x] = y;
    val[y] += val[x];
    lef[y] = min(lef[x], lef[y]);
    rig[y] = max(rig[x], rig[y]);
    evsum[y] += evsum[x];
    oddsum[y] += oddsum[x];
    
}
ll n;
ll a[200009];
ll ans[200009];
set<pll, greater<pll>> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        prt[i] = i;
        val[i] = a[i];
        lef[i] = rig[i] = i;
        if(i%2)
            oddsum[i] = a[i];
        else
            evsum[i] = a[i];
        s.insert({val[i], i});
    }
    ll sz = 0;
    ll cur = 0;
    while(sz < (n+1)/2){
        pll curit = *s.begin();
        s.erase(s.begin());
        ll curnode = curit.ss;
 
        cur += curit.ff;
        ans[++sz] = cur;
        //cout << lef[curnode] << ' ' << rig[curnode] << '\n';
        ll befl = lef[curnode];
        ll befr = rig[curnode];
        if(lef[curnode]-1 >= 0){
            ll x = findprt(lef[curnode]-1);
            s.erase({val[x], x});
            merge(x, curnode);
        }
        curnode = findprt(curnode);
        if(rig[curnode]+1 < n){
            ll x = findprt(rig[curnode]+1);
            s.erase({val[x], x});
            merge(x, curnode);
        }
        curnode = findprt(curnode);
        lef[curnode] = min(befl-1, lef[curnode]);
        rig[curnode] = max(befr+1, rig[curnode]);
 
        if(befl%2 == 0)
            val[curnode] = oddsum[curnode]-evsum[curnode];
        else
            val[curnode] = evsum[curnode]-oddsum[curnode];
        if(lef[curnode] >= 0 && rig[curnode] < n)
            s.insert({val[curnode], curnode});
    }
    for(ll i = 1; i <= (n+1)/2; ++i)
        cout << ans[i] << '\n';
}
