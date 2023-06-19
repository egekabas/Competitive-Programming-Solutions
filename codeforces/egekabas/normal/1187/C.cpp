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
int n, m;
int big[1009];
int a[1009];
vector<pii> so;
vector<pii> noso;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    int t, l, r;
    for(int i = 0; i < m; ++i){
        cin >> t >> l >> r;
        if(t == 1)
            so.pb({l-1, r-1});
        else
            noso.pb({l-1, r-1});
    }
    for(auto u : so){
        for(int i = u.ff+1; i <= u.ss; ++i)
            big[i] = 1;
    }
    for(auto u : noso){
        int ok = 0;
        for(int i = u.ff+1; i <= u.ss; ++i)
            if(big[i] == 0)
                ok = 1;
        if(ok == 0){
            cout << "NO\n";
            return 0;
        }
    }
    a[0] = 1100;
    for(int i = 1; i < n; ++i){
        if(big[i] == 1) a[i] = a[i-1];
        else a[i] = a[i-1]-1;
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i)
        cout << a[i] << endl;
}