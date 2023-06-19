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
ll a[109];
ll check(){
    ll sum = 0;
    for(ll i = n-2; i >= 0; i -= 2){
        ll tmp = a[i]*2;
        while(tmp > 0){
            sum += tmp%10;
            tmp /= 10;
        }
    }
    for(ll i = n-3; i >= 0; i -= 2)
        sum += a[i];
    if((sum*9)%10 == a[n-1])
        return 1;
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    ll idx = 0;
    for(ll i = 0; i < n; ++i){
        char c ;
        cin >> c;
        if(c == 'x')
            idx = i;
        else
            a[i] = c-'0';
    }
    for(ll i = 0; i < 10; ++i){
        a[idx] = i;
        if(check()){
            cout << i;
            return 0;
        }
    }
}
