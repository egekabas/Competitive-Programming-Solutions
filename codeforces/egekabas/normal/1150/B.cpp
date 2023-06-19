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

int n;
char a[55][55];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(a[i][j] == '.'){
                if(i >= n-2 || j == n-1 || j == 0){
                    cout << "NO\n";
                    return 0;
                }
                else if(a[i+1][j] == '.' && a[i+1][j+1] == '.'
                && a[i+1][j-1] == '.' && a[i+2][j] == '.'){
                    a[i+1][j] = '#';
                    a[i+1][j+1] = '#';
                    a[i+1][j-1] = '#';
                    a[i+2][j] = '#';
                    a[i][j] = '#';
                }
                else{
                    cout << "NO\n";
                    return 0;
                }
            }
    cout << "YES\n";

}