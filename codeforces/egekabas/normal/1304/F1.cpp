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
int seg[100009];
int lazy[100009];
void push(int v){
    seg[2*v] += lazy[v];
    seg[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val){
    if(r < tl || tr < l)
        return;
    if(l <= tl && tr <= r){
        seg[v] += val;
        lazy[v] += val;
    }
    else{
        push(v);
        int tm = (tl+tr)/2;
        upd(2*v, tl, tm, l, r, val);
        upd(2*v+1, tm+1, tr, l, r, val);
        seg[v] = max(seg[2*v], seg[2*v+1]);
    }
}
/*int get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return;
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        push(v);
        int tm = (tl+tr)/2;
        return(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
    }
}*/
int n, m, k;
int a[59][100009];
int dp[100009];
int ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    for(int layer = 0; layer < n; ++layer){
        int cur = 0;
        for(int i = 0; i < k; ++i){
            cur += a[layer][i];
            if(layer < n-1)
                cur += a[layer+1][i];
            upd(1, 0, m-1, max(0, i-k+1), i, -a[layer][i]);
        }
        dp[0] = cur + max(0, seg[1]);
        for(int i = k; i < m; ++i){
            cur += a[layer][i];
            cur -= a[layer][i-k];
            if(layer < n-1){
                cur += a[layer+1][i];
                cur -= a[layer+1][i-k];
            }
            upd(1, 0, m-1, max(0, i-k+1), i, -a[layer][i]);
            upd(1, 0, m-1, max(0, i-k-k+1), i-k, a[layer][i-k]);
            dp[i-k+1] = cur + max(0, seg[1]);
        }
        for(int i = 0; i <= 4*m; ++i)
            seg[i] = lazy[i] = 0;
        for(int i = 0; i < m; ++i){
            upd(1, 0, m-1, i, i, dp[i]);
            //cout << dp[i] << ' ';
            ans = max(ans, dp[i]);
            dp[i] = 0;
        }
        //cout << seg[1] << '\n';
    }    
    cout << ans << "\n";
}