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
ll a, b;
vector<ll> first;
vector<ll> second;
ll hold[1000000];

int main(){
    cin >> a >> b;
    ll n = sqrt(2*(a+b));
    while(n*(n+1)/2 > (a+b))
        --n;
    for(ll i = n; i > 0; --i){
        if(a >= i){
            a = a-i;
            first.pb(i);
        }
        else{
            b = b-i;
            second.pb(i);
        }
    }
    cout << first.size() << endl;
    for(auto u : first)
        cout << u << " ";
    cout << endl;

    cout << second.size() << endl;
    for(auto u : second)
        cout << u << " ";
    cout << endl;
}