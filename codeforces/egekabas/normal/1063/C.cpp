#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll n;
string sl;
string sm;
string sr;
int main(){

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    cout << "1 0\n";
    cin >> sl;
    ll l = 1, r = 1e9, m;
    n--;
    while(n--){
        m = (l+r)/2;
        cout << "1 " << m << endl;
        cin >> sm;
        if(sl[0] == sm[0]){
            l = m+1;
        }
        else{
            r = m;
        }
    }
    cout << "0 " << r << " 2 " << r - 1 << endl;
}