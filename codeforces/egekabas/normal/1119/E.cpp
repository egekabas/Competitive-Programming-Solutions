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
ll n;
ll a[3000009];
ll dp[3000009];
ll sum[3000009];

int main(){
    cin >> n;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sum[0] = a[0];
    for(ll i = 1; i < n; ++i)
        sum[i] = sum[i-1] + a[i];
    dp[0] = a[0]/3;
    for(ll i = 1; i < n; ++i){
        dp[i] = 0;
        ll crt;

        if(a[i] % 2 == 0)
            crt = min(a[i]/2, sum[i-1]);
        else
            crt = min((a[i]-3)/2, sum[i-1]);

        crt = max((ll)0, crt);
        dp[i] += (a[i]-2*crt)/3;
        ll need = ((crt-(sum[i-1]-3*dp[i-1])+2)/3);
        need = max((ll)0, need);
        dp[i] += dp[i-1]-need;
        dp[i] += crt;
    }
    cout << dp[n-1] << endl;
}