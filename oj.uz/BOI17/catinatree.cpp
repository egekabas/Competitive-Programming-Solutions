#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
vector<int> g[200009];
int n, d;
int ans;
int dis[200009];
void dfs(int v){
    vector<int> vec;
    for(auto u : g[v]){
        dfs(u);
        vec.pb(dis[u]+1);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    while(vec.size() >= 2 && vec.back()+vec[vec.size()-2] < d){
        vec.pop_back();
        --ans;
    }
    if(vec.empty())
        dis[v] = 1e9;
    else
        dis[v] = vec.back();
 
    if(dis[v] >= d){
        dis[v] = 0;
        ++ans;
    }
}
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> d;
    for(int i = 1; i < n; ++i){
        int prt;
        cin >> prt;
        g[prt].pb(i);
    }
    dfs(0);
    cout << ans << '\n';
}
