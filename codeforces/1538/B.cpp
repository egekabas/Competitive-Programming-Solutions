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
int n, a[200009];
void solve(){
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%n){
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans += (a[i] > sum/n);
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