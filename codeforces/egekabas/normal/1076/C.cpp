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

long double a, b, d;
int t;

int main(){
    cin >> t;
    while(t--){
        cin >> d;
        if(d*d-4*d < 0)
            cout << "N" << endl;
        else{
            cout << "Y ";
            a = (-d+sqrt(d*d-4*d))/(-2);
            b = d-a;
            cout<<fixed<<setprecision(10) << a << " " << b << endl;
        }
    }
}