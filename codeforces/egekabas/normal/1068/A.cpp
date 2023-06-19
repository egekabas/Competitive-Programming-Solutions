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

ll n, m , k, l;

int main(){
    cin >> n >> m >> k >> l;
    ll tmp = (k + l +(m-1))/m;
    if(m*tmp > n || k + l > n){
        cout << "-1\n";
    }
    else{
        cout << tmp << endl;
    }
}