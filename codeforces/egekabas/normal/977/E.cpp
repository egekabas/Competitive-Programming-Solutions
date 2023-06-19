#include <bits/stdc++.h>
using namespace std;
int vis[200009];
vector<int> gr[200009];
vector<int> con[200009];

int n,m;
int ans;
dfs(int u, vector<int> *hold){
    vis[u] = 1;
    for(auto v: gr[u])
        if(vis[v] == 0){
            (*hold).push_back(v);
            dfs(v, hold);
        }
}

int main(){
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        gr[x-1].push_back(y-1);
        gr[y-1].push_back(x-1);
    }
    int temp = 0;
    for(int i = 0; i < n; ++i)
        if(vis[i]==0 ){
            con[temp].push_back(i);
            dfs(i, &con[temp]);
            ++temp;
        }
    int count;
    for(int i = 0; i < temp; ++i){
        count = 0;
        for(auto u: con[i]){
            if(gr[u].size() != 2){
                ++count;
                break;
            }
        }
        if(count == 0){
            ++ans;
        }
    }
    //for(int i = 0; i < temp; ++i){
    //    for(auto u: con[i])
    //        cout << u+1 << " ";
    //    cout << endl;
    //}
    cout << ans ;
}