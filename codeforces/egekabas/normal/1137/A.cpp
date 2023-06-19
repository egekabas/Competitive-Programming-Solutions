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
int str[1009][1009];
int ans[1009][1009];
vector<int> row[1009];
vector<int> col[1009];
map<int, bool> mymap;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> str[i][j];
    for(int i = 0; i < n; ++i){
        mymap.clear();
        for(int j = 0; j < m; ++j){
            if(!mymap[str[i][j]])
                row[i].pb(str[i][j]);
            mymap[str[i][j]] = 1;
        }
        sort(row[i].begin(), row[i].end());
    }
    for(int j = 0; j < m; ++j){
        mymap.clear();
        for(int i = 0; i < n; ++i){
            if(!mymap[str[i][j]])
                col[j].pb(str[i][j]);
            mymap[str[i][j]] = 1;
        }
        sort(col[j].begin(), col[j].end());
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            vector<int>::iterator f = lower_bound(row[i].begin(), row[i].end(), str[i][j]);
            vector<int>::iterator s = lower_bound(col[j].begin(), col[j].end(), str[i][j]);
            ans[i][j] = max(f-row[i].begin(), s-col[j].begin()) 
            + max(row[i].end()-f, col[j].end()-s);
        }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}