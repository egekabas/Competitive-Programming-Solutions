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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
ll n, a[1000009], b[1000009], c[1000009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;
    for(ll test = 0; test < t; ++test){
        
        cin >> n;
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        for(ll i = 0; i < n; ++i){
            cin >> b[i];
            c[i] = b[i];
        }
        
        ll cur = 0;        
        ll cnt = 2;
        while(cnt--)
            for(ll i = 0; i < n; ++i){
                cur += c[i];
                c[i] = 0;
                ll er = min(cur, a[i]);
                a[i] -= er;
                cur -= er;
                cur = min(cur, b[i]);
                b[i] -= cur;
            }
        ll ok = 1;
        for(ll i = 0; i < n; ++i)
            if(a[i] != 0)
                ok = 0;
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}