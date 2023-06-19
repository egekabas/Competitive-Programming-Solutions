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
ll n, x;
vector<int> v;
int dont[5000009];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> x;
    dont[x] = 1;
    for(int i = 1; i < (1<<n); ++i){
        if(dont[i])continue;
        else{
            dont[i^x] = 1;
            v.pb(i);
        }
    }
    cout << v.size() << endl;
    if(v.size() == 0)return 0;
    cout << *v.begin() << " ";
    for(int i = 1; i < v.size(); ++i)
        cout << (v[i]^v[i-1]) << " ";
}