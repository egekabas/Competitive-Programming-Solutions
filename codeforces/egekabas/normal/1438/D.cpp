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
int a[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int tot = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        tot ^= a[i];
    }
    if(n%2 == 0 && tot != 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<pair<int, pii>> v;
    if(n%2 == 0){
        for(int i = 1; i+2 < n; i += 2){
            v.pb({i, {i+1, i+2}});
            v.pb({i, {i+1, 0}});
        }
    }
    else{
        for(int i = 0; i + 2 < n; i += 2)
            v.pb({i, {i+1, i+2}});
        for(int i = 0; i + 1 < n-3; i += 2)
            v.pb({i, {i+1, n-1}});
    }
    cout << v.size() << '\n';
    for(auto u : v){
        cout << u.ff+1 << ' ' << u.ss.ff+1 << ' ' << u.ss.ss+1 << '\n';
        int tmp = a[u.ff]^a[u.ss.ff]^a[u.ss.ss];
        a[u.ff] = a[u.ss.ff] = a[u.ss.ss] = tmp;
    }
    //for(int i = 0; i < n; ++i)
    //    cout << a[i] << '\n';
}