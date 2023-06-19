#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll get(ll x){
    ll ret = x/9*45;
    for(ll i = 1; i <= x%9; ++i)
        ret += i;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << get(r)-get(l-1) << '\n';
    }
}
