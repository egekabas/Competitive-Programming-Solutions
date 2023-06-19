#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;

bool prime(ll x){
    for(ll i = 2; i*i <= x; ++i){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    ll a, b;
    while(t--){
        cin >> a >> b;
        if(a-b == 1 && prime(a+b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}