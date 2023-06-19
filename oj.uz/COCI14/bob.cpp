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
int a[1009][1009];
int down[1009][1009];
ll ans;
stack<pii> s;
int n, m;
ll ctwo(ll x){
    return x*(x-1)/2 + x;
}
void spop(int idx, int line, int cur){
    pii tmp = s.top();
 
    s.pop();
    if(s.empty()){
        ans += ctwo(idx-tmp.ss)*(down[line][tmp.ff]-cur);
    }
    else{
        ans += ctwo(idx-tmp.ss)*(down[line][tmp.ff]- max(cur, down[line][s.top().ff]));
 
    }
}
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
 
    for(int i = n; i > 0; --i)
        for(int j = m; j > 0; --j){
            if(i == n || a[i][j] != a[i+1][j])
                down[i][j] = 1;
            else
                down[i][j] = down[i+1][j]+1;
        }
 
    int beg = -1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] != a[i][j-1]){
                while(!s.empty())
                    spop(j, i, 0);
                beg = j;
            }
            while(!s.empty() && down[i][s.top().ff] > down[i][j])
                spop(j, i, down[i][j]);
            if(!s.empty() && down[i][s.top().ff] == down[i][j]){
                int t1 = s.top().ss;
                s.pop();
                s.push({j, t1});
                continue;
            }
            if(!s.empty())
                s.push({j, s.top().ff+1});
            else
                s.push({j, beg});
        }
        while(!s.empty())
            spop(m+1, i, 0);
    }
    cout << ans << "\n";
    
}
