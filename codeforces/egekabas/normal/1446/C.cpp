#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
vector<int> a;
int calc(vector<int> v, int bit){
    if(bit == -1) return 0;
    if(v.size() <= 3) return 0;
    vector<int> g[2];
    for(auto u : v)
        g[(u&(1<<bit)) > 0].pb(u);
    return min(calc(g[0], bit-1)+max(0, (int)g[1].size()-1), 
    calc(g[1], bit-1)+max(0, (int)g[0].size()-1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << calc(a, 29) << '\n';
}