#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int n, m;
int a[109][109];
vector<vector<pii>> ans;
void add(vector<pii> v){
    for(auto u : v)
        a[u.ff][u.ss] ^= 1;
    ans.pb(v);
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j)
            a[i][j] = (s[j] == '1');
    }
    ans.clear();
    for(int i = 0; i < n-1; ++i)
        for(int j = 0; j < m; ++j){
            if(a[i][j] == 0) continue;
            if(j != m-1 && a[i][j+1])
                add({{i, j}, {i, j+1}, {i+1, j}});
            else{
                if(j == m-1)
                    add({{i, j}, {i+1, j}, {i+1, j-1}});
                else
                    add({{i, j}, {i+1, j}, {i+1, j+1}});
            }
        }
    for(int j = 0; j < m-1; ++j)
        if(a[n-1][j]){
            add({{n-1, j}, {n-2, j}, {n-2, j+1}});
            add({{n-1, j+1}, {n-2, j}, {n-2, j+1}});
        }
    if(a[n-1][m-1]){
        add({{n-1, m-1}, {n-2, m-1}, {n-1, m-2}});
        add({{n-1, m-1}, {n-2, m-1}, {n-2, m-2}});
        add({{n-1, m-1}, {n-1, m-2}, {n-2, m-2}});
    }
    cout << ans.size() << '\n';
    for(auto u1 : ans){
        for(auto u2 : u1)
            cout << u2.ff+1 << ' ' << u2.ss+1 << ' ';
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}