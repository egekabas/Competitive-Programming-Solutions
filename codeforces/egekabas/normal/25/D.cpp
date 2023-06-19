#include <bits/stdc++.h>
using namespace std;
int n;
int parent[1005];
int ranks[1005];
vector<pair<int,int>> null;
int ans[1005][4];
void make_set(int v) {
    parent[v] = v;
    ranks[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void union_sets(int x, int y) {
    int a = find_set(x);
    int b = find_set(y);
    if(a == b)
        null.push_back(make_pair(x,y));
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        make_set(i);
    int a,b;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        union_sets(a,b);
    }
    int t = 0;
    int par = find_set(1);
    for(int i = 1; i <= n; ++i){
        if(find_set(i) != par){
            ans[t][0] = null[t].first;
            ans[t][1] = null[t].second;
            ans[t][2] = find_set(i);
            ans[t][3] = par;
            ++t;
            union_sets(i, par);
            par = find_set(i);
        }
    }
    cout << t << endl;
    for(int i = 0; i < t; ++i)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
}