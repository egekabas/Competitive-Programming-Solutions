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
int mod = 1e9+7;
int eul(int x, int y){
    if(x == 0 && y == 0) return 0;
    if(x == y) return -1e9;
    if(x > y)
        return (x/(y+1))+eul(x%(y+1), y);
    else
        return (y/(x+1))+eul(x, y%(x+1));
}
void getans(int x, int y){
    if(x == 0 && y == 0) return;
    if(x > y){
        for(int i = 0; i < x/(y+1); ++i)
            cout << "0 ";
        getans(x%(y+1), y);
    }
    else{
        for(int i = 0; i < y/(x+1); ++i)
            cout << "1 ";
        getans(x, y%(x+1));
    }
    
}
void solve(){
    int k;
    cin >> k;
    int ans = 0;
    pii use = {1e9, 1e9};
    for(int i = 0; i <= k; ++i){
        int cur = eul(i, k-i);
        if(cur >= 0){
            ++ans;
            use = min(use, {cur, i});
        }
    }
    cout << ans << '\n';
    getans(use.ss, k-use.ss);
    cout << '\n';
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
