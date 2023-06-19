#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int t, r, c, k;
int a[1009][1009];
char ans[1009][1009];
vector<char> use;
int input(){
    char c;
    cin >> c;
    if(c == 'R')
        return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> t;
    for(char i = 'a'; i <= 'z'; ++i)
        use.pb(i);
    for(char i = 'A'; i <= 'Z'; ++i)
        use.pb(i);
    for(char i = '0'; i <= '9'; ++i)
        use.pb(i);
    while(t--){
        cin >> r >> c >> k;
        int tot = 0;
        for(int i = 1; i <= r; ++i)
            for(int j = 1; j <= c; ++j){
                a[i][j] = input();
                tot += a[i][j];    
            }
        int mini = tot/k;
        int maxi = mini+1;
        int nomaxi = tot-mini*k;
        int curtot = 0;
        int chicken = 0;
        for(int i = 1; i <= r; ++i){
            if(i%2)
                for(int j = 1; j <= c; ++j){
                    ans[i][j] = use[chicken];
                    curtot += a[i][j];
                    if(chicken < k-1 && (curtot == maxi || (curtot == mini && nomaxi <= 0))){
                        ++chicken;
                        --nomaxi;
                        curtot = 0;
                    }
                }
            else
                for(int j = c; j >= 1; --j){
                    ans[i][j] = use[chicken];
                    curtot += a[i][j];
                    if(chicken < k-1 && (curtot == maxi || (curtot == mini && nomaxi <= 0))){
                        ++chicken;
                        --nomaxi;
                        curtot = 0;
                    }
                }
        }
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j)
                cout << ans[i][j];
            cout << "\n";
        }
    }
}