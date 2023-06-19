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
ll mini[300009];
ll maxi[300009];
ll bit[600009];
ll place[300009];
ll last = 300001;
ll n, m;
void upd(ll idx, ll val){
    while(idx <= 300001+n){
        bit[idx] += val;
        idx += idx&(-idx);
    }
}
ll get(ll idx){
    ll ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= idx&(-idx);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    
    for(ll i = 1; i <= n; ++i){
        upd(last+i, 1);
        place[i] = last+i;
        mini[i] = maxi[i] = i;
    }
    while(m--){
        int x;
        cin >> x;
        mini[x] = 1;
        maxi[x] = max(maxi[x], get(place[x]));
        upd(place[x], -1);
        upd(last, 1);
        place[x] = last;
        last--;
    }
    for(ll i = 1; i <= n; ++i)
        maxi[i] = max(maxi[i], get(place[i]));
    for(ll i = 1; i <= n; ++i)
        cout << mini[i] << " " << maxi[i] << "\n";
}