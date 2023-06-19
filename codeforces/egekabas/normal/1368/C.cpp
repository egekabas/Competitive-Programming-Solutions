#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n;
vector<pii> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    ans.pb({0, 0});
    for(int i = 1; i <= n+1; ++i){
        ans.pb({i, i});
        ans.pb({i-1, i});
        ans.pb({i, i-1});
    }
    cout << ans.size() << '\n';
    for(auto u : ans)
        cout << u.ff << ' ' << u.ss << '\n';
}