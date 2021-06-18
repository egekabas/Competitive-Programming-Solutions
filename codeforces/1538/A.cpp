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
int n, a[100009];
void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    pii mini = {1e9, 1e9};
    pii maxi = {-1e9, -1e9};
    for(int i = 0; i < n; ++i){
        mini = min(mini, {a[i], i});
        maxi = max(maxi, {a[i], i});
    }
    int x = mini.ss, y = maxi.ss;
    if(x > y)
        swap(x, y);
    int ans = min({x+1 + n-y, y+1, n-x});
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}