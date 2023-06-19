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
char grid[509][509];
int maxsq[509][509];
int pre[509][509][275];
int lg[509];
int n, m, q;
bool check(int x1, int y1, int x2, int y2, int val){
    y2 -= 2*val-1;
    x2 -= 2*val-1;
    if(val == 0)
        return 1;
    if(x1 > x2 || y1 > y2)
        return 0;
    ll cur = pre[x2][y2][val]-pre[x1-1][y2][val]-pre[x2][y1-1][val]+pre[x1-1][y1-1][val];
    return (cur > 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    for(int i = n; i >= 1; --i)
        for(int j = m; j >= 1; --j){
            int ok = 1;
            
            for(int x = j; x <= j+maxsq[i+1][j+1]/2; ++x)
                if(grid[i][x] != 'R')
                    ok = 0;
            for(int x = i; x <= i+maxsq[i+1][j+1]/2; ++x)
                if(grid[x][j] != 'R')
                    ok = 0;
            
            for(int x = j+maxsq[i+1][j+1]/2+1; x <= j+maxsq[i+1][j+1]+1; ++x)
                if(grid[i][x] != 'G')
                    ok = 0;
            for(int x = i; x <= i+maxsq[i+1][j+1]/2; ++x)
                if(grid[x][j+maxsq[i+1][j+1]+1] != 'G')
                    ok = 0;
            
            for(int x = j; x <= j+maxsq[i+1][j+1]/2; ++x)
                if(grid[i+maxsq[i+1][j+1]+1][x] != 'Y')
                    ok = 0;
            for(int x = i+maxsq[i+1][j+1]/2+1; x <= i+maxsq[i+1][j+1]+1; ++x)
                if(grid[x][j] != 'Y')
                    ok = 0;
            
            for(int x = j+maxsq[i+1][j+1]/2+1; x <= j+maxsq[i+1][j+1]+1; ++x)
                if(grid[i+maxsq[i+1][j+1]+1][x] != 'B')
                    ok = 0;
            for(int x = i+maxsq[i+1][j+1]/2+1; x <= i+maxsq[i+1][j+1]+1; ++x)
                if(grid[x][j+maxsq[i+1][j+1]+1] != 'B')
                    ok = 0;
            
            if(ok)
                maxsq[i][j] = maxsq[i+1][j+1]+2;
            
        }
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            pre[i][j][maxsq[i][j]/2] = 1;
            for(ll k = 1; k <= 250; ++k)
                pre[i][j][k] += pre[i-1][j][k]+pre[i][j-1][k]-pre[i-1][j-1][k];
        }   
    
    
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int l = 0, r = 270;
        while(l < r){
            int mid = (l+r+1)/2;
            if(check(x1, y1, x2, y2, mid))
                l = mid;
            else
                r = mid-1;
        }
        cout << (2*l)*(2*l) << '\n';
    }
}