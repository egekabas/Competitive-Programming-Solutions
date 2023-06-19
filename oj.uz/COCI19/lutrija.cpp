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
ll isprime(ll x){
    if(x == 0 || x == 1) return 0;
    for(ll i = 2; i*i <= x; ++i)
        if(x%i == 0)
            return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll a, b;
    cin >> a >> b;
    if(a == 2 && b == 2)
        cout << "3\n2 5 2\n";
    else if(a == 2)
        cout << "3\n2 " << b+2 << ' ' << b << '\n';
    else if(b == 2)
        cout << "3\n" << a << ' ' << a+2 << " 2\n";
    else{
        vector<ll> v;
        v.pb(a);
        if(isprime(a+2)){
            v.pb(a+2);
            v.pb(2);    
        }
        else if(isprime(a-2))
            v.pb(2);
        else{
            cout << "-1\n";
            return 0;
        }
 
        if(isprime(b+2)){
            v.pb(b+2);
            v.pb(b);
        }
        else if(isprime(b-2))
            v.pb(b);
        else{
            cout << "-1\n";
            return 0;
        }
        cout << v.size() << '\n';
        for(auto u : v)
            cout << u << ' ';        
    }
}
