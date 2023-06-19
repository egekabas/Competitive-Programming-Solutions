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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, k;
vector<pii> v;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> k;
    pii bef = {-1, -1};
    for(int i = 1; i <= k && v.size() < n; ++i)
        for(int j = i+1; j <= k && v.size() < n; ++j){
            if(i == bef.ff ||  j == bef.ss){
                v.pb({j, i});
                v.pb({i, j});
                bef = {i, j};
            }
            else{
                v.pb({i, j});
                v.pb({j, i});
                bef = {j, i};
            }
        }
    if(v.size() < n){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i)
        cout << v[i].ff << " " << v[i].ss << endl;
    
}