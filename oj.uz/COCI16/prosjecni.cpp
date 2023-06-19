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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    if(n == 2){
        cout << "-1\n";
        return 0;
    }
    if(n%2){
        for(ll i = 1; i <= n*n; ++i){
            cout << i << " ";
            if(i%n == 0)
                cout << "\n";
        }
    }
    else{
        ll beg = 1;
        ll colcnt = 0;
        for(ll i = 1; i < n; ++i){
            colcnt += beg;
            ll cnt = 0;
            for(ll j = beg; j < beg+n-1; ++j){
                cout << j << " ";
                cnt += j;
            }
            ll end = n*(beg+n-1-1)-cnt;
            cout << end << "\n";
            if(i != n-1)
                beg = end+1;
        }
        beg = n*beg-colcnt;
        ll cnt = 0;
        for(ll j = beg; j < beg+n-1; ++j){
            cout << j << " ";
            cnt += j;
        }
        ll end = n*(beg+n-1-1)-cnt;
        cout << end << "\n";
    }
}
