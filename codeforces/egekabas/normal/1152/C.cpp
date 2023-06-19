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
ll a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> a >> b;
    if(a > b) swap(a, b);
    ll dif = abs(a-b);
    ll k = 1e18; 
    if(dif == 0){
        cout << 0; return 0;
    }
    else if(dif > a){
        for(ll i = 1; i*i <= dif; ++i){
            if(dif % i == 0){
                if(i >= a){
                    k = min(k, i-a);
                    break;
                }
                else if(dif/i >= a){
                    k = min(k, dif/i-a);
                }
            }
        }
        if(k == 1e18) k = dif-a;
    }
    else
        k = (dif-a%dif)%dif; 

    cout << k << endl;
}