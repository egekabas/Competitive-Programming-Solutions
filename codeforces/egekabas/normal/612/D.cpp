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
int n, k;
vector<pair<int, int>> v;
vector<pii> ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    int x, y;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        v.pb({x, 0});
        v.pb({y, 1});
    } 
    sort(v.begin(), v.end());
    int seg = 0;
    int tmp1 = 0;
    for(int i = 0 ; i < v.size(); ++i){
        if(v[i].ss == 0){
            ++seg;
            if(seg == k){
                tmp1 = v[i].ff;
            }
        }
        else if(v[i].ss == 1){
            --seg;
            if(seg == k-1){
                ans.pb({tmp1, v[i].ff});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto u : ans)
        cout << u.ff << " " << u.ss << endl;
}