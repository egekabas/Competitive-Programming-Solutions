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

ll b;

int main(){
    cin >> b;
    ll count = 0;
    ll i;
    for(i = 1; i*i < b; ++i){
        if(b % i == 0)
            count += 2;
    }
    if(i*i == b)
        ++count;
    cout << count << endl;
}