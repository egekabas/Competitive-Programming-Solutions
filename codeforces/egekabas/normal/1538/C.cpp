#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, l, r, a[200009];
void solve(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int lidx = n, ridx = n-1;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        while(lidx > 0 && (a[i]+a[lidx-1] >= l))
            --lidx;
        while(ridx >= 0 && a[i]+a[ridx] > r)
            --ridx;

        ans += max(0, ridx-max(lidx, i+1)+1);    
    }
    cout << ans << '\n';
    
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}