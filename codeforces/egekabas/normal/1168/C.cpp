#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, q;
int a[300009];
int dp[300009][40];
int last[40];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= 32; ++j)
            dp[i][j] = 1e9;
    for(int j = 0; j <= 32; ++j)
        last[j] = 1e9;
    for(int i = n-1; i >= 0; --i){
        vector<int> v;
        int tmp = a[i];
        int cur = 0;
        while(tmp > 0){
            if(tmp%2)
                v.pb(cur);
            ++cur;
            tmp /= 2;
        }
        for(auto u : v)
            dp[i][u] = i;
        for(auto u : v){
            if(last[u] == 1e9)
                continue;
            for(int j = 0; j <= 32; ++j)
                dp[i][j] = min(dp[i][j], dp[last[u]][j]);
        }
        for(auto u : v)
            last[u] = i;
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        --x, --y;
        vector<int> v;
        int tmp = a[y];
        int cur = 0;
        while(tmp > 0){
            if(tmp%2)
                v.pb(cur);
            ++cur;
            tmp /= 2;
        }
        int ok = 0;
        for(auto u: v){
            if(dp[x][u] <= y)
                ok = 1;
        }
        if(ok){
            cout << "Shi\n";
        }
        else{
            cout << "Fou\n";
        }
    }
}