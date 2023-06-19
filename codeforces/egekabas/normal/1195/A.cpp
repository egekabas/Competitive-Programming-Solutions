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
int k;
int a[1009];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> k;
    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        ++a[tmp];
    }
    int sing = 0;
    int dub = 0;
    for(int i = 1; i <= k; ++i){
        dub += a[i]/2;
        sing += a[i]%2;
    }
    int set = (n+1)/2;
    int ans = 0;
    ans += 2*min(dub, set);
    set -= min(dub, set);
    ans += min(sing, set);
    cout << ans << endl;
}