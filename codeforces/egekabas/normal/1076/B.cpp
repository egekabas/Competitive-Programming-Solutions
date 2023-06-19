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
int main(){
    cin >> n;
    if(n % 2 == 0){
        cout << n/2 << endl;
        return 0;
    }
    else{
        for(ll i = 3; i*i <= n; i += 2){
            if(n % i == 0){
                cout << (n-i)/2+1 << endl;
                return 0;
            }
        }
        cout << 1 << endl;
    }
}