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
void solve(){
    int n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    for(int bit = 0; bit < (1<<4); ++bit){
        int d = ((bit&(1<<0)) > 0);
        int c = ((bit&(1<<1)) > 0);
        int b = ((bit&(1<<2)) > 0);
        int a = ((bit&(1<<3)) > 0);
        

        int up = U-a-b;
        int ri = R-b-d;
        int le = L-a-c;
        int dwn = D-c-d;
        if(0 <= up && up <= n-2 && 0 <= ri && ri <= n-2 &&
            0 <= le && le <= n-2 && 0 <= dwn && dwn <= n-2){
                cout << "YES\n";
                return ;
            }
    }
    cout << "NO\n";
}
/*a b c d
3 2 1 0

0 0 0 0     0
0 0 0 1     1
0 0 1 0     2
0 0 1 1     3
0 1 0 0     4
0 1 0 1     5
0 1 1 0     6
0 1 1 1     7
1 0 0 0     8
1 0 0 1     9
1 0 1 0     10
1 0 1 1     11
1 1 0 0     12
1 1 0 1     13
1 1 1 0     14
1 1 1 1     15*/

int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();    
}

/*
a ------------------- b
-
-
-
-                     -
-                     -
-                     -
-                     -
c---------------------d
*/