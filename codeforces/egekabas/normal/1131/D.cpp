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
int n, m;
vector<int> ls[2009];
int col[2009];
int val[2009];
int siz[2009];
int parent[2009];
char table[2009][2009];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b]) 
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
void dfs(int v){
    int add = 0;
    col[v] = 1;
    for(auto u : ls[v]){
        int s = find_set(u);
        if(col[s] == 1 ){
            cout << "No\n";
            exit(0);
        }
        else if(col[s] == 0){
            dfs(u);
            add = max(add, val[s]);
        }
        else if(col[s] == 2){
            add = max(add, val[s]);
        }
    }
    col[v] = 2;
    val[v] = 1+add;
}
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    char c;
    for(int i = 0; i < m+n; ++i) make_set(i);
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> table[i][j];
            c = table[i][j];            
            if(c == '='){
                union_sets(i, n+j);
            }
        }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            c = table[i][j];
            if(c == '<') {
                ls[find_set(n+j)].pb(find_set(i));
            }
            else if(c == '>'){
                ls[find_set(i)].pb(find_set(n+j));
            }
        }
    for(int i = 0; i < m+n; ++i){
        if(col[find_set(i)]) continue;
        dfs(find_set(i));
    }
    cout << "Yes\n";
    for(int i = 0; i < n; ++i)
        cout << val[find_set(i)] << " ";
    cout << endl;
    for(int i = n; i < m+n; ++i)
        cout << val[find_set(i)] << " ";
    
}