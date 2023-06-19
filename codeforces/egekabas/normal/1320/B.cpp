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
int n, m, k;
vector<int> inc[200009];
vector<int> out[200009];

int p[200009];
int d[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        out[x].pb(y);
        inc[y].pb(x);
    }
    cin >> k;
    for(int i = 0; i < k; ++i)
        cin >> p[i];
    for(int i = 1; i <= n; ++i)
        d[i] = 1e9;
    d[p[k-1]] = 0;
    queue<int> q;
    q.push(p[k-1]);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : inc[v])
            if(d[u] == 1e9){
                d[u] = d[v]+1;
                q.push(u);
            }
    }
    int maxi = 0, mini = 0;
    for(int i = 0; i < k-1; ++i){
        if(d[p[i+1]] != d[p[i]]-1)
            ++mini;
        for(auto u : out[p[i]]){
            if(u != p[i+1] && d[u] == d[p[i]]-1){
                ++maxi;
                break;
            }
        }
    }
    cout << mini << ' ' << maxi << '\n';
    
}