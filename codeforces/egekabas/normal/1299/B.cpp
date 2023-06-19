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
ll n;
pld pnt[300009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> pnt[i].ff >> pnt[i].ss;
    }
    if(n%2){
        cout << "NO\n";
        return 0;
    }
    pld center;
    for(ll i = 0; i + n/2 < n; ++i){
        if(i == 0)
            center = {(pnt[i].ff+pnt[i+n/2].ff)/2.0, (pnt[i].ss+pnt[i+n/2].ss)/2.0};
        else{
            pld look = {(pnt[i].ff+pnt[i+n/2].ff)/2.0, (pnt[i].ss+pnt[i+n/2].ss)/2.0};
            if(abs(look.ff-center.ff) > 0.001 || abs(look.ss-center.ss) > 0.001){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}