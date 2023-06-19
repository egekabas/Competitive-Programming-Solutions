#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;

char c[250*250+1];
vector<int> g[250*250+1];
int n, m;
int ans;

pair<int, int> dfs(int v){
    pair<int, int> x = mp(0, 0);
    if(c[v] == 'k')
        ++x.ff;
    else if(c[v] == 'v')
        ++x.ss;
    c[v] = '#';
    pair<int, int> tmp;
    for(auto u : g[v]){
        if(c[u] != '#'){
            tmp = dfs(u);
            x.ff += tmp.ff;
            x.ss += tmp.ss;
        }
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 0; i < n*m; ++i)
        cin >> c[i];
    for(int i = 0; i < n*m; ++i){
        if(i > 0){
            g[i].pb(i-1);
            g[i-1].pb(i);
        }
        if(i >= m){
            g[i].pb(i-m);
            g[i-m].pb(i);
        }
    }
    pair<int, int> p;
    pair<int ,int> ans = mp(0, 0);
    for(int i = 0; i < n*m; ++i){
        if(c[i] != '#'){
            p = dfs(i);
            if(p.ff > p.ss)
                ans.ff += p.ff;
            else
                ans.ss += p.ss;
        }
    }
    cout << ans.ff << " " << ans.ss << endl;
}
