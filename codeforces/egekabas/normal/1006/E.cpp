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
vector<int> g[200009];
int w[200009];
vector <int> hold;
int place[200009];
int n, q;
int dfs(int v){
    hold.pb(v);
    place[v] = hold.end()-hold.begin()-1;
    w[v] = 1;
    for(auto u : g[v]){
        w[v] += dfs(u);
    }
    //cout << v << endl;
    return w[v];
}
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> q;
    int tmp;
    for(int i = 0; i < n-1; ++i){
        cin >> tmp;
        g[tmp].pb(i+2);
    }
    dfs(1);
    int a, b;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(w[a] >= b)
            cout << hold[place[a]+b-1] << endl;
        else
            cout << "-1\n";
    }


}