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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n;
bool a[5201][5201];
int ans = n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif  

    cin >> n;
    char c; int tmp;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n/4; ++j){
            cin >> c;
            if(c <= '9' && c >= '0')
                tmp = c-'0';
            else if(c <= 'F' && c >= 'A')
                tmp = c - 'A' + 10;
            for(int k = j*4+3; k >= 4*j; --k){
                a[i][k] = tmp%2;
                tmp /= 2;
            }
        }
    }
    int len = 0;
    int cur;
    for(int i = 0; i < n; ++i){
        cur = a[i][0];
        len = 1;
        for(int j = 1; j < n; ++j){
            if(a[i][j] == cur)++len;
            else{
                ans = gcd(ans, len);
                cur = a[i][j];
                len = 1;
            }
        }
        ans = gcd(ans, len);
    }
    for(int i = 0; i < n; ++i){
        cur = a[0][i];
        len = 1;
        for(int j = 1; j < n; ++j){
            if(a[j][i] == cur)++len;
            else{
                ans = gcd(ans, len);
                cur = a[j][i];
                len = 1;
            }
        }
        ans = gcd(ans, len);
    }
    cout << ans << endl;
}