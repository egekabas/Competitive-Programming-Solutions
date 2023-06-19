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
int n, k;
int v[1009][1009];
int sz[1009];
int ans[1009];
int used[1009];
int query(int l, int r){
    cout << "? "  << (r-l+1) << ' ';
    for(int i = l; i <= r; ++i)
        cout << i << ' ';
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}
int func(int l, int r, int maxi){
    if(l == r) return l;
    int m = l + (r-l)/2;
    if(query(l, m) == maxi)
        return func(l, m, maxi);
    return func(m+1, r, maxi);
}
int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < k; ++i){
            cin >> sz[i];
            assert(0 < sz[i] && sz[i] <= 1000);
            for(int j = 0; j < sz[i]; ++j)
                cin >> v[i][j];
        }
        for(int i = 1; i <= n; ++i) used[i] = 0;
        int maxi = query(1, n);
        int idx = func(1, n, maxi);
        for(int i = 0; i < k; ++i){
            int okay = 1;
            for(int j = 0; j < sz[i]; ++j)
                if(idx == v[i][j])
                    okay = 0;
            if(okay)
                ans[i] = maxi;
            else{
                cout << "? " << n-sz[i] << ' ';
                for(int j = 0; j < sz[i]; ++j)
                    used[v[i][j]] = 1;
                for(int j = 1; j <= n; ++j)
                    if(used[j] == 0)
                        cout << j << ' ';
                cout << endl;
                cin >> ans[i];
            }
        }   
        cout << "! ";
        for(int i = 0; i < k; ++i)
            cout << ans[i] << ' ';
        cout << endl;
        string s;
        cin >> s;
    }
}