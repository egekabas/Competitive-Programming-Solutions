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
int a[4009][4009];
int cost[4009][4009];
int n, k;
vector<int> cur(4009, 1e9), pre(4009);
void calc(int k, int l, int r, int optl, int optr){
    if(l > r)
        return;
    int m = (l+r)/2;
    int idx = optl;
    for(int i = min(m-1, optr); i >= optl; --i)
        if(pre[i] + cost[i+1][m] <= cur[m]){
            cur[m] = pre[i] + cost[i+1][m];
            idx = i;
        }
    calc(k, l, m-1, optl, idx);
    calc(k, m+1, r, idx, r);
}
char c[9009];
int main() {
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    scanf("%d%d", &n, &k);
    char tmp = getchar();
    for(int i = 1; i <= n; ++i){
        fgets(c, 2*n, stdin);
        for(int j = 1; j <= n; ++j){
            a[i][j] = c[(j-1)*2]-'0';
        }
        char tmp = getchar();

    }
    for(int i = n; i >= 1; --i)
        for(int j = i+1; j <= n; ++j)
            cost[i][j] = cost[i][j-1] + cost[i+1][j] - cost[i+1][j-1] + a[i][j];
    
    for(int i = 1; i <= n; ++i)
        cur[i] = cost[1][i];
    
    for(int i = 2; i <= k; ++i){
        pre = cur;
        cur = vector<int>(4009, 1e9);
        calc(i, 1, n, 1, n);
    }
    
    printf("%d\n", cur[n]);
}