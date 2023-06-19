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
ll n, m, k;
vector<ll> v[505];

ll beg[505][505];
ll fin[505][505];
ll day[505][505];

ll dp[505][505];
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    char c;
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < m; ++j){
            cin >> c;
            if(c == '1')
                v[i].pb(j);
        }
    for(ll i = 0; i < n; ++i){
        if(v[i].size() == 0) continue;
        ll tot = *(v[i].end()-1)-*v[i].begin()+1;
        for(auto itr = v[i].begin(); itr < v[i].end(); ++itr)
            beg[i][itr-v[i].begin()] = (*(v[i].end()-1))-*itr+1;
        
        
        for(auto itr = v[i].end()-1; itr != v[i].begin(); --itr)
            fin[i][v[i].end()-1-itr] = *itr-*v[i].begin()+1;
        fin[i][v[i].end()-1-v[i].begin()] = 1;
        
        for(ll j = 0; j <= k; ++j) day[i][j] = 1e8;
        for(ll j = 0; j <= k; ++j)
            for(ll z = 0; z <= j; ++z)
                day[i][j] = min(day[i][j], max((ll)0, beg[i][z]+fin[i][j-z]-tot));
    }
    for(ll i = 1; i < n; ++i)
        for(ll j = 0; j <= k; ++j)
            dp[i][j] = 1e8;
    for(ll i = 0; i <= k; ++i)dp[0][i] = day[0][i];
    for(ll i = 1; i < n; ++i)
        for(ll j = 0; j <= k; ++j){
            for(ll z = 0; z <= j; ++z){
                dp[i][j] = max((ll)0, min(dp[i-1][z] + day[i][j-z], dp[i][j]));
            }
        }

    cout << dp[n-1][k] << endl;
}