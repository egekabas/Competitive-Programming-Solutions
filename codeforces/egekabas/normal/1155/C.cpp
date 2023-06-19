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
ll gcd(ll x, ll y){
    if(y > x) swap(x, y);
    if(y == 0) return x;
    return gcd(y, x%y);
}

ll n, m;
ll a[300009];
ll p[300009];

int main() {
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    
    for(ll i = 0; i < n; ++i)
        cin >> a[i]; 
    for(ll i = 0; i < m; ++i)
        cin >> p[i];
    
    ll dif = a[1]-a[0];
    for(ll i = 2; i < n; ++i){
        dif = gcd(dif, a[i]-a[i-1]);
        //cout << a[i] << " " << a[i-1] << endl;    
    }

    ll ind = -1;

    for(ll i = 0; i < m; ++i){
        if(dif % p[i] == 0){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        cout << "NO\n";
        return 0;
    }
    else{
        cout << "YES\n";
        cout << a[0] << " " << ind+1 << endl;
    }
}