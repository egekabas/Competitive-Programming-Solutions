#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, int>   pli;
typedef pair<int, int>  pii;

vector<int> g[200009];
bool vis[200009];
int n;
int a[200009];
int cmp[200009];
queue<int> q;

int sorter(int a, int b){
    return cmp[a] < cmp[b];
}

int main(){
    cin >> n;
    int x, y;
    for(int i = 0; i < n-1; ++i){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cmp[a[i]] = i;
    }
    if(a[0] != 1){
        cout << "No";
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        sort(g[i].begin(), g[i].end(), sorter);
    }

    int c = 1;
    q.push(a[0]);
    vis[a[0]] = 1;
    int tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for(auto u : g[tmp] ){
            if(!vis[u]){
                if(u != a[c++]){
                    cout << "No";
                    return 0;
                }
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    cout << "Yes";
}