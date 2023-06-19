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
int q, n;
int a[200009];
int ch[200009];
int func(int x, int y){
    return x > y;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> q;
    while(q--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a+n, greater<int>());
        n = unique(a, a+n)-a;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, a[i]);
            if(a[i] + a[i+1] + a[i+2] <= ans) break;
            for(int j = i+1; j < n; ++j){
                if(a[i] + a[j] + a[j+1] <= ans)break;
                if(a[i] % a[j] == 0) continue;
                ans = max(ans, a[i]+a[j]);
                for(int k = j+1; k < n; ++k){
                    if(a[i] + a[j] + a[k] <= ans)break;
                    if(a[i] % a[k] == 0 || a[j] % a[k] == 0)continue;
                    ans = max(ans, a[i] + a[j] + a[k]);
                }
            }
        }
        cout << ans << endl;
    }
}