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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    int cur = -1;
    string ans;
    int tot = 0;
    while(n--){
        string s;
        int a, b;
        cin >> s >> a >> b;
        int ev = 0;
        while(b >= a){
            b -= a;
            b += 2; 
            ++ev;
        }
        tot += ev;
        if(ev > cur){
            cur = ev;
            ans = s;
        }
    }
    cout << tot << "\n" << ans << "\n";
}
