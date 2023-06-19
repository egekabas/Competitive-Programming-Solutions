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
ll fen[15][100009];
ll n, a, k;
void update(ll idx, ll val, ll lay){
    while(idx <= n+1){
        fen[lay][idx] += val;
        idx += idx&(-idx);        
    }
}
ll get(ll idx, ll lay){
    ll ret = 0;
    while(idx > 0){
        ret += fen[lay][idx];
        idx -= idx&(-idx);
    }
    return ret;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a;
        update(a, 1, 0);
        for(int j = 1; j <= k; ++j)
            update(a, get(a-1 ,j-1), j);
    }
    cout << get(n+1, k) << endl;
}