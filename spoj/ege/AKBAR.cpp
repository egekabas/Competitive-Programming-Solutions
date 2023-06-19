#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int vis[10000001];
int sold[10000001][2];
vector<int> adj[1000001];
void solve(){
    int n,r,m;
    cin >> n >> r >> m;
    for(int i=0;i<=max(n, m);i++){
        vis[i] = 0;
        sold[i][0] =0;
        sold[i][1] =0;
        adj[i].clear();
    }
    bool x=1;
    for(int i=0;i<r;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        cin >> sold[i][0] >> sold[i][1];
    }
    queue<pii> q;
    for(int i=0;i<m;i++){
        q.push({sold[i][0], sold[i][1]});
        vis[sold[i][0]] = sold[i][0];
    }
    while (!q.empty()) {
            int v = q.front().first;
            int p = q.front().second;
            q.pop();
            if(p == 0)continue;
            for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = vis[v];
                q.push({u,p-1});
            }
            else if(vis[u] != vis[v]){
                x=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!(vis[i])){
            x=0;
            break;
        }
    }
    if(x){
        cout << "Yes"<<endl;
    }
    else{
        cout << "No" <<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
