#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;

bool b[109];
vector<int> g[109];
vector<int> o[109];
vector<string> a;
int col[109];
stack<char> c;
void dfs(int v){
    if(col[v])
        return;
    col[v] = 1;
    b[v] = 1;
    int count = 0;
    for(auto u : g[v]){
        if(col[u] == 0){
            dfs(u);
        }
        else if(col[u] == 1 ){
            cout << "Impossible\n";
            exit(0);
        }
    }
    c.push((char)((int)v + (int)'a'));
    col[v] = 2;
}
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        a.pb(tmp);
    }
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < min(a[i].size(), a[i+1].size()); ++j){
            if(a[i][j] != a[i+1][j]){
                int x = (int)a[i][j] - (int)'a';
                int y = (int)a[i+1][j] - (int)'a';
                g[x].pb(y);
                o[y].pb(x);
                goto END;
            }
        }
    if(a[i].size() > a[i+1].size()){
        cout << "Impossible\n";
        return 0;
    }
    END:;
    }
    for(int i = 0; i < 26; ++i){
        if(col[i] == 0)
            dfs(i);
    }
    while(!c.empty()){
        cout << c.top();
        c.pop();
    }
}