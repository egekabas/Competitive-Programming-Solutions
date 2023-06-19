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
int a[3000009];
vector<int> g[3000009];
int ans;
int f(int v, int p){
    vector<int> vec;
    for(auto u : g[v]){
        if(u == p)
            continue;
        vec.pb(f(u, v));
    }
    sort(vec.begin(), vec.end());
    int cur = a[v];
    for(auto u : vec){
        if(u + cur > k)
            ++ans;
        else
            cur += u;
    }
    return cur;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
    }
    f(1, -1);
    cout << ans << "\n";
    
}
