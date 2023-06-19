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
vector<int> sum[100009];
int get(int l, int r, int col){
    int t1 = lower_bound(sum[col].begin(),sum[col].end(), l)-sum[col].begin();
    int t2 = upper_bound(sum[col].begin(),sum[col].end(), r)-sum[col].begin();
    return t2-t1;
}
int a[300009];
int seg[300009*4];
int n, c, m;
void build(int v, int tl, int tr){
    if(tl == tr){
        seg[v] = a[tl];
    }
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        int p1 = seg[2*v];
        int p2 = seg[2*v+1];
        if(p1 != -1 && get(tl, tr, p1) > (tr-tl+1)/2)
            seg[v] = p1;
        else if(p2 != -1 && get(tl, tr, p2) > (tr-tl+1)/2)
            seg[v] = p2;
        else
            seg[v] = -1;
        //cout << seg[v] << endl;
    }
}
int que(int v, int tl, int tr, int l, int r){
    if(l <= tl && r >= tr)
        return seg[v];
    if(l > tr || r < tl)
        return -1;
    int tm = (tl+tr)/2;
    int p1 = que(2*v, tl, tm, l, r);
    int p2 = que(2*v+1, tm+1, tr, l, r);
    l = max(l, tl);
    r = min(r, tr);
    if(p1 != -1 && get(l, r, p1) > (r-l+1)/2)
        return p1;
    else if(p2 != -1 && get(l, r, p2) > (r-l+1)/2)
        return p2;
    else return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum[a[i]].pb(i);
    }
    for(int i = 1; i <= c; ++i){
        sort(sum[i].begin(), sum[i].end());
    }
    build(1, 0, n-1);
    cin >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        --x; --y;
        int tmp = que(1, 0, n-1, x, y);
        if(tmp == -1) cout << "no\n";
        else cout << "yes " << tmp << "\n";
    }
