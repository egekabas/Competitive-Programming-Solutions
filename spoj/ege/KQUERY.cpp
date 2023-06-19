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
int a[100009];
vector<int> seg[400009];

void build(int v, int tl, int tr){
    if(tl == tr){
        seg[v] = {a[tl]};
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);
    
    seg[v].resize(seg[2*v].size()+seg[2*v+1].size());
    merge(all(seg[2*v]), all(seg[2*v+1]), seg[v].begin());    
}
int get(int v, int tl, int tr, int l, int r, int val){
    if(r < tl || tr < l)
        return 0;
    else if(l <= tl && tr <= r){
        return seg[v].end()-upper_bound(all(seg[v]), val);
    }
    else{
        return get(2*v, tl, (tl+tr)/2, l, r, val)+
        get(2*v+1, (tl+tr)/2+1, tr, l, r, val);
    }
}
int n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n-1);

    cin >> q;
    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        cout << get(1, 0, n-1, x, y, z) << '\n';
    }
