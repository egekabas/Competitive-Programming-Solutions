#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, m;
int obs;
int line[900000];
vector<int> g[900000];
bool in[900000];
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> line[i];
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        g[x].pb(y);
    }
    in[line[n-1]] = 1;
    obs = 1;
    for(int i = n-2; i >= 0; --i){
        int tmp = 0;
        for(auto u : g[line[i]]){
            if(in[u] == 1) ++tmp;
        }
        if(tmp != obs){
            ++obs;
            in[line[i]] = 1;
        }
    }
    cout << n-obs << endl;
}