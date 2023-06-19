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
ll n, k;
ll bit[200009];
string s;
void upd(ll idx, ll val){
    ++idx;
    while(idx > 0){
        bit[idx] = min(bit[idx], val);
        idx -= idx&(-idx);
    }
}
ll get(ll idx){
    if(idx < 0)
        return 0;
    ll ret = 1e18;
    ++idx;
    while(idx <= n+1){
        ret = min(ret, bit[idx]);
        idx += idx&(-idx);
    }
    return ret;
}
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(int i = 0; i <= n+1; ++i)
        bit[i] = 1e18;
    cin >> s;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            upd(min(n-1, i+k), get(i-k-1)+i+1);
        }
        else{
            upd(i, get(i-1)+i+1);
        }
    }
    cout << get(n-1) << "\n";
}