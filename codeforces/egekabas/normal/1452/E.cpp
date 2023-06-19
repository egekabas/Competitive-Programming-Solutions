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
int n, m, k;
pii seg[2009];
int inter(int idx, pii a){
    int l = max(idx, a.ff);
    int r = min(idx+k-1, a.ss);
    return max(0, r-l+1);
}
int bit[2009];
void upd(int idx, int val){
    if(idx >= n || idx < 0) return;
    for(++idx; idx <= n; idx += idx&(-idx))
        bit[idx] += val;
}
int get(int idx){
    if(idx >= n || idx < 0) return 0;
    int ret = 0;
    for(++idx; idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}
int mainval;
int getval(pii a){
    return a.ss+1-inter(mainval, a);
}
int sf(pii a, pii b){
    return getval(a) < getval(b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        cin >> seg[i].ff >> seg[i].ss;
        --seg[i].ff;
        --seg[i].ss;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        mainval = i;
        sort(seg, seg+m, sf);
        int curans = 0;
        for(int j = 0; j < m; ++j)
            curans += inter(i, seg[j]);
        for(int j = 0; j <= n; ++j)
            bit[j] = 0;
        int idx = m;
        for(int j = n-1; j >= i; --j){
            curans -= get(j+k);
            curans += get(j);
            while(idx > 0 && inter(j, seg[idx-1]) >= inter(i, seg[idx-1])){
                --idx;
                curans -= inter(i, seg[idx]);
                curans += inter(j, seg[idx]);
                upd(seg[idx].ff, 1);
                upd(seg[idx].ss+1, -1);
            }
            //cout << i+1 << ' ' << j+1 << ' ' << curans << '\n';
            ans = max(ans, curans);
        }
    }
    cout << ans << '\n';
}