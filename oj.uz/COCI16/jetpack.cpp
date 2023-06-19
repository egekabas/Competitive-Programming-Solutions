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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n;
string fi[10];
ll dp[10][200009];
ll boost[200009];
vector<pll> ans;
void func(ll i, ll j){
    if(i == 0)
        return;
    if(j != 0 &&  dp[j-1][i-1] == 1){
        func(i-1, j-1);
    }
    else if(j == 0 && dp[j][i-1] == 1){
        boost[i-1] = 1;
        func(i-1, j);
    }
    else if(j != 9 && dp[j+1][i-1] == 1){
        boost[i-1] = 1;
        func(i-1, j+1); 
    }
    else if(j == 9 && dp[j][i-1] == 1){
        func(i-1, j);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(ll i = 0; i < 10; ++i)
        cin >> fi[i];
    dp[9][0] = 1;
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < 10; ++j){
            if(fi[j][i] == 'X')
                dp[j][i] = 0;
            if(dp[j][i] == 0)
                continue;
            if(j != 9)
                dp[j+1][i+1] = 1;
            else
                dp[j][i+1] = 1;
            if(j != 0)
                dp[j-1][i+1] = 1;
            else
                dp[j][i+1] = 1;
        }
    }
    for(ll j = 0; j < 10; ++j)
        if(dp[j][n-1] == 1){
            func(n-1, j);
            break;
        }
 
    ll last = -1;
    for(ll i = 0; i < n; ++i){
        //cout << i << " " << boost[i] << "\n";
        if(last != -1 && boost[i] == 0){
            ans.pb({last, i-last});
            last = -1;
        }
        else if(last == -1 && boost[i] == 1){
            last = i;
        }
    }
    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
}
