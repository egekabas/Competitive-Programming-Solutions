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
string s;
int main(){
    cin >> n;
    cin >> s;
    int ans = (int)1e9;
    for(int i = 0; i < n-3; ++i){
        int tmp1 = min(abs(s[i] - 'A'), 26-abs(s[i] - 'A'));
        int tmp2 = min(abs(s[i+1] - 'C'), 26-abs(s[i+1] - 'C'));
        int tmp3 = min(abs(s[i+2] - 'T'), 26-abs(s[i+2] - 'T'));
        int tmp4 = min(abs(s[i+3] - 'G'), 26-abs(s[i+3] - 'G'));
        ans = min(ans, tmp1+tmp2+tmp3+tmp4);
        
    }
    cout << ans << endl;
}