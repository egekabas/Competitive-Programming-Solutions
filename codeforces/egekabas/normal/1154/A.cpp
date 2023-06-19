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
ll x1, x2, x3, x4;
ll a, b, c, big;
int main(){
    cin >> x1 >> x2 >> x3 >> x4;
    if(2*x1 == (x2 + x3 + x4)){
        big = x1;
        a = x2;
        b = x3; 
        c = x4;
    }
    else if(2*x2 == (x1 + x3 + x4)){
        big = x2;
        a = x1;
        b = x3; 
        c = x4;
    }
    else if(2*x3 == (x2 + x1 + x4)){
        big = x3;
        a = x2;
        b = x1; 
        c = x4;
    }
    else if(2*x4 == (x2 + x3 + x1)){
        big = x4;
        a = x2;
        b = x3; 
        c = x1;
    }
    cout << big-a << " " << big-b << " " << big-c << endl;
}