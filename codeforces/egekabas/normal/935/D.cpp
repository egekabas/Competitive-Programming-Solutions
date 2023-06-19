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
ll mod = (ll)1e9 + 7;
ll n, m;
int a[100009], b[100009];

ll inv(ll x){
    ll ans = 1;
    ll y = mod-2;
    while(y > 0){
        if(y % 2) ans = (ans*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    ll ans = 0;
    ll multip = 1;
    ll cnst = inv(m);
    ll cnst2 = inv(2*m);
    for(int i = 0; i < n; ++i){
        if(a[i] == 0 && b[i] == 0){
            ans = (multip*((m-1)*(cnst2)%mod)%mod+ans)%mod;
            multip = (multip*cnst)%mod;
        }
        else if(a[i] == 0){
            ans = (multip*(m-b[i])%mod*cnst%mod+ans)%mod;
            multip = (multip*cnst)%mod;
        }
        else if(b[i] == 0){
            ans = (multip*(a[i]-1)%mod*cnst%mod+ans)%mod;
            multip = (multip*cnst)%mod;    
        }
        else if(a[i] > b[i]){
            ans = (ans+multip)%mod;
            break;
        }
        else if(a[i] < b[i]){
            break;
        }

    }
    cout << ans << endl;
}