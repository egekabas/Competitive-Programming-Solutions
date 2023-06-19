#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
ll a[3000][3000];
char ans[3000][3000];
ll n, m;
void spread(ll i, ll j);
void check(ll i, ll j){
    if(a[i][j])
        return;

    if(a[i-1][j] && a[i+1][j]){
        
        if(a[i][j+1] && !a[i][j-1]){
            a[i][j-1] = a[i][j] = 1;
            ans[i][j-1] = '<';
            ans[i][j] = '>';
            spread(i, j);
            spread(i, j-1);
            
        }

        if(!a[i][j+1] && a[i][j-1]){
            a[i][j+1] = a[i][j] = 1;
            ans[i][j+1] = '>';
            ans[i][j] = '<';
            spread(i, j);
            spread(i, j+1);
        }
        
    }

    if(a[i][j+1] && a[i][j-1]){
        
        if(a[i+1][j] && !a[i-1][j]){
            a[i-1][j] = a[i][j] = 1;
            ans[i-1][j] = '^';
            ans[i][j] = 'v';
            spread(i-1, j);
            spread(i, j);
        }

        if(!a[i+1][j] && a[i-1][j]){
            a[i+1][j] = a[i][j] = 1;
            ans[i+1][j] = 'v';
            ans[i][j] = '^';
            spread(i+1, j);
            spread(i, j);
        }
        
    }
}
void spread(ll i, ll j){
    if(i < 1 || i > n)
        return;
    if(j < 1 || j > m)
        return;
    
    check(i+1, j);
    check(i-1, j);
    check(i, j+1);
    check(i, j-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        a[i][0] = a[i][m+1] = 1;
    for(ll i = 1; i <= m; ++i)
        a[0][i] = a[n+1][i] = 1;
    
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j){
            cin >> ans[i][j];
            a[i][j] = (ans[i][j] == '*');
        }
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j)
            check(i, j);
    
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j)
            if(!a[i][j]){
                cout << "Not unique\n";
                return 0;
            }
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j)
            cout << ans[i][j];
        cout << '\n';
    }
    
}