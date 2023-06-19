#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, m;
int a[505][505];
bool dp[505][1040];
int road[505][1040];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i< n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    for(int j = 0; j < m; ++j){
        dp[0][a[0][j]] = 1;
        road[0][a[0][j]]=j;
    }
    for(int i = 1; i< n; ++i){
        for(int j = 0; j < m; ++j){
            for(int u = 0; u <= 1023; ++u){
                if(dp[i-1][u] == 0) continue;
                dp[i][u^a[i][j]] = 1;
                road[i][u^a[i][j]] = j;
            }
        }
    }
    int it;
    for(it = 1;it <= 1023; ++it) if(dp[n-1][it]) break;
    if(it != 1024){
        cout << "TAK\n";
        vector<int> tmp;
        int l = it;
        for(int i = n-1; i >= 0; --i){
            tmp.pb(road[i][l]);
            l = l^a[i][road[i][l]];
        }
        reverse(tmp.begin(), tmp.end());
        for(auto u : tmp)
            cout << u+1 << " ";
    }
    else{
        cout << "NIE\n"; 
    }
    
}