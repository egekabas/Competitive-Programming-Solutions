#include <bits/stdc++.h>
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
int a[309][309];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                cin >> a[i][j];
            }
        int ok = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                int cur = 4;
                if(i == 0 || i == n-1) --cur;
                if(j == 0 || j == m-1) -- cur;
                if(a[i][j] > cur)
                    ok = 0;
                else
                    a[i][j] = cur;
            }
        if(ok == 0){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            for(int j = 0;j < m; ++j)
                cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
}