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
ll n, k, a, b;
ll mini = (ll)1e15;
ll maxi = 0;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
void calc(ll l){
    if(l <= 0 || l > n*k) return;
    ll tmp =  n*k/gcd(n*k, l);
    mini = min(tmp, mini);
    maxi = max(tmp, maxi);
}
int main(){
    cin >> n >> k >> a >> b;
    for(int i = -2; i <= n; ++i){
        calc(k*i+b-a);
        calc(k*i-b-a);
        calc(k*i+b+a);
        calc(k*i-b+a);
    }
    cout << mini << " " << maxi << endl;
}