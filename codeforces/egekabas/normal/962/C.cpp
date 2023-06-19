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

ll a[15];
char s[15];

int main(){
    cin >> s;
    ll len;
    for(len = 0; s[len] != '\0'; ++len)
        a[len] = (ll)s[len] - (ll)'0';
    for(ll i = 100000; i > 0; --i){
        ll tmp = i*i;
        for(ll j = len-1; j >= 0; --j){
            if(a[j] == tmp%10)
                tmp /= 10;
            if(tmp == 0 )
                break;
        }
        if(tmp == 0){
            tmp = i*i;
            ll j;
            for(j = 0; tmp != 0; ++j)
                tmp /= 10;
            cout << len-j << endl;
            return 0;
        }
    }
    cout << "-1\n";

}