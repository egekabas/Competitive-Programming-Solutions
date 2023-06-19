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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        for(ll i = 0; i < a.size(); ++i){
            if(a[i] == c[i] || b[i] == c[i])
                continue;
            cout << "NO\n";
            goto END;
        }
        cout << "YES\n";
        END:;
    }
}