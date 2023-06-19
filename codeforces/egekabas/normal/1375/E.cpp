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
int a[1009];
vector<int> g[1009];
int sf(int x, int y){
    if(a[x] == a[y])
        return x > y;
    return a[x] > a[y];
}
vector<pii> ans;
void change(int x, int y){
    ans.pb({x, y});
    swap(a[x], a[y]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> v;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j)
            if(a[i] < a[j])
                g[i].pb(j);
        v.pb(i);
    }
    sort(v.begin(), v.end(), sf);   
    for(auto i : v){
        sort(g[i].begin(), g[i].end());
        for(auto j : g[i])
            change(j, i);
    }
    for(int i = 2; i <= n; ++i)
        if(a[i] < a[i-1]){
            cout << -1;
            return 0;
        }
    cout << ans.size() << '\n';
    for(auto u : ans)
        cout << u.ff << ' ' << u.ss << '\n';
}