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

ll n, m;
string a, b;
ll val[200009];

char bit(char x, char y){
    if(x == '1' && y == '1')
        return '1';
    else
        return '0';
}



int main(){
    cin >> n >> m;
    cin >> a >> b;
    ll mod = 998244353;
    if(b[0] == '1')
        val[0] = 1;
    for(ll i = 1; i < m; ++i){
        if(b[i] == '1')
            val[i] = val[i-1]+1;
        else
            val[i] = val[i-1];
    }
    ll ans = 0;
    ll mult = 1;
    for(ll i = 1; i <= n; ++i){
        if(a[n-i] == '1' && m-i >= 0){
            ans = (ans + (val[m-i]*mult)%mod)%mod;
        }
        mult = (mult*2)%mod;
    }
    cout << ans << endl;
}