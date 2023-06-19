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
int op[400000];
int n, no;
vector<int> g[400000];

int dfs(int v){
    if(g[v].size() == 0)
        return 1;
    int cnt = 0; int mini = 1e9;
    for(auto u : g[v]){
        int s = dfs(u); 
        cnt += s;
        mini = min(mini, s);
    }
    //cout << mini << " " << cnt << endl;
    if(op[v] == 1) return mini;
    else return cnt;
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> op[i];
    int tmp;
    for(int i = 2; i <= n; ++i){
        cin >> tmp;
        g[tmp].pb(i);
    }
    for(int i = 1; i <= n; ++i){
        if(g[i].size() == 0) ++no;
    }
    int ans = dfs(1);
    ans = no-ans+1;
    cout << ans << endl;
}