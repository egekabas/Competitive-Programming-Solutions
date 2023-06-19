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
int n;
vector<ld> a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    for(int i = 0; i < n; ++i){
        ld x, y;
        cin >> x >> y;
        a.pb(x);
        b.pb(y);
    }
    sort(all(a), greater<ld>());
    sort(all(b), greater<ld>());
    ld cura = 0, curb = 0;
 
    int j = 0;
    ld ans = 0;
    for(int i = 0; i < n; ++i){
        cura += a[i]-1;
        curb += -1;
 
        while(j < n && min(cura, curb) < min(cura-1, curb+b[j]-1)){
            curb += b[j]-1;
            cura += -1;
            ++j;
        }
        ans = max(ans, min(cura, curb));
    }
    cout << fixed << setprecision(4) << ans << '\n';
}
