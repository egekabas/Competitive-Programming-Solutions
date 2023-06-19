#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll p, k;
vector<ll> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> p >> k;
    ll bef = p;
    ll neg = 0;
    while(bef != 0){
        if(neg == 0){
            v.pb(bef%k);
            bef = bef/k;
        }
        else{
            if(bef%k == 0){
                v.pb(bef%k);
                bef = bef/k;
            }
            else{
                v.pb((k-bef%k));
                bef = bef/k+1;
            }
        }
        neg ^= 1;
    }
    //reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto u : v)
        cout << u << " ";
}