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
ll k, l, r, t, x, y;
ll vis[1000009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> k >> l >> r >> t >> x >> y;
    k -= l;
    r -= l;
    if(y <= x){
        if(k + y <= r)
            k += y;
        k -= x;
        if(k < 0){
            cout << "No\n";
            return 0;
        }
        if(x == y){
            cout << "Yes\n";
            return 0;
        }
        ll ans = k/(x-y)+1;
        if(ans >= t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else{
        if(x > r-y+1){
            ll cur = k;
            while(1){
                t -= cur/x;
                cur %= x;
                if(t <= 0) break;
                if(vis[cur]) break;
                vis[cur] = 1;
                if(r-y < cur){
                    cout << "No\n";
                    return 0;
                }
                cur = (cur+y);
            }
        }
        cout << "Yes\n";
    }
}