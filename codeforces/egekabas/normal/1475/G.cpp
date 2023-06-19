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
int a[200009];
int sz[200009];
int mpp[200009];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        sz[i] = 1;
        for(int j = 1; j*j <= a[i]; ++j){
            if(a[i]%j) continue;
            sz[i] = max(sz[i], mpp[j]+1);
            sz[i] = max(sz[i], mpp[a[i]/j]+1);
        }
        mpp[a[i]] = sz[i];
        ans = max(ans, sz[i]);
    }
    cout << n-ans << '\n';
    for(int i = 0; i < n; ++i)
        mpp[a[i]] = 0;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();
}