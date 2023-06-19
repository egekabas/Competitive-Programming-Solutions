#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int n, m, c, q;
unordered_map<int, int> mpp[100009];
unordered_map<int, int> g[100009];

int prt[100009];


int find(int x){
    if(prt[x] == x) return x;
    return x = find(prt[x]);
}
void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    if(g[x].size() > g[y].size())
        swap(x, y);
    
    for(auto u : g[x])
        if(u.ss)
            g[y][u.ff] = 1;

    prt[x] = y;
}

void addedge(int x, int y, int z){
    if(mpp[x][z])
        merge(mpp[x][z], y);
    else
        mpp[x][z] = y;

    if(mpp[y][z])
        merge(mpp[y][z], x);
    else
        mpp[y][z] = x;
    
    g[find(x)][y] = g[find(y)][x] = 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> c >> q;

    for(int i = 1; i <= n; ++i)
        prt[i] = i;

    while(m--){
        int x, y, z;
        cin >> x >> y >> z;

        addedge(x, y, z);
    }

    while(q--){
        char c;
        int x, y, z;
        cin >> c >> x >> y;
        if(c == '?'){
            if(find(x) == find(y) || g[find(x)][y])
                cout <<"Yes\n";
            else
                cout << "No\n";
        }
        else{
            cin >> z;
            
            addedge(x, y, z);
        }
    }

}