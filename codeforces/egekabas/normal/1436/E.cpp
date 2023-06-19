#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n;
int a[100009];
int seg[400009];
int ans[100009];
int last[100009];
void upd(int v, int tl, int tr, int idx, int val){
    if(tl == tr){
        seg[v] = val;
        return;
    }
    if(idx <= (tl+tr)/2)
        upd(2*v, tl, (tl+tr)/2, idx, val);
    else
        upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
    seg[v] = min(seg[2*v], seg[2*v+1]);    
}
int get(int v, int tl, int tr, int l, int r){
    if(tr < l || r < tl) return 1e9;
    if(l <= tl && tr <= r) return seg[v];
    return min(get(2*v, tl, (tl+tr)/2, l, r), get(2*v+1, (tl+tr)/2+1, tr, l, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];    
    }
    for(int i = 1; i <= n; ++i){
        if(get(1, 1, n, 1, a[i]-1) > last[a[i]]){
            ans[a[i]] = 1;
        }
        last[a[i]] = i;
        upd(1, 1, n, a[i], i);
    }
    for(int i = 2; i <= n+1; ++i)
        if(get(1, 1, n, 1, i-1) > last[i])
            ans[i] = 1;
    ans[1] = 0;
    for(int i = 1; i <= n; ++i)
        ans[1] |= (a[i] != 1);
    for(int i = 1; i <= n+2; ++i)
        if(ans[i] == 0){
            cout << i << '\n';
            return 0;
        }
}