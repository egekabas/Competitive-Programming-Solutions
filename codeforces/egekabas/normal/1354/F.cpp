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
struct minion{
    int a, b, id;
};
bool sortb(minion x, minion y){
    return x.b < y.b;
}
int n, k;
minion ar[100];
int dp[100][100];
void calc(){
    sort(ar, ar+n, sortb);
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            dp[i][j] = -1e9;
    dp[0][0] = ar[0].b*(k-1);
    dp[0][1] = ar[0].a;
    for(int i = 1; i < n; ++i){
        dp[i][0] = dp[i-1][0] + ar[i].b*(k-1);
        for(int j = 1; j <= k; ++j)
            dp[i][j] = max(dp[i-1][j-1] + ar[i].a + (j-1)*ar[i].b, dp[i-1][j]+ar[i].b*(k-1));
    }
    int place = k;
    vector<minion> used, notused;
    for(int i = n-1; i > 0; --i){
        if(place == 0 || dp[i][place] == dp[i-1][place]+ar[i].b*(k-1))
            notused.pb(ar[i]);
        else{
            --place;
            used.pb(ar[i]);
        }
    }
    if(place == 1)
        used.pb(ar[0]);
    else
        notused.pb(ar[0]);
    cout << 2*n-k << '\n';
    for(int i = used.size()-1; i > 0; --i)
        cout << used[i].id << " ";
    for(auto u : notused)
        cout << u.id << " -" << u.id << ' ';
    cout << used[0].id << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; ++i){
            cin >> ar[i].a >> ar[i].b;
            ar[i].id = i+1;
        }
        calc();
    }
}