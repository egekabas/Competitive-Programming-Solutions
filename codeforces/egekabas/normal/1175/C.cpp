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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int a[200009];
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = -1; int mini = 1e9;
        for(int i = 0; i+k < n; ++i){
            int r = (a[i]+a[i+k])/2;
            if(a[i+k]-r <= mini){
                mini = a[i+k]-r;
                ans = r;
            }
        }
        cout << ans << endl;
    }
}