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
int n, q;
bitset<10006> val;
bitset<10006> ans;
vector<bitset<10006>> roll;
void addnew(int x){
    roll.pb(val);
    val = (val|(val<<x));
}
void goback(){
    val = roll.back();
    roll.pop_back();
}
vector<int> seg[40009];
void add(int v, int tl, int tr, int l, int r, int val){
    if(tr < l || r < tl) return;
    if(l <= tl && tr <= r){
        seg[v].pb(val);
        return;
    }
    else{
        add(2*v, tl, (tl+tr)/2, l, r, val);
        add(2*v+1, (tl+tr)/2+1, tr, l, r, val);
    }
}
void dfs(int v, int tl, int tr){
    for(auto u : seg[v])
        addnew(u);
    if(tl == tr)
        ans = ans|val;
    else{
        dfs(2*v, tl, (tl+tr)/2);
        dfs(2*v+1, (tl+tr)/2+1, tr);
    }
    for(auto u : seg[v])
        goback();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        add(1, 1, n, l, r, x);
    }
    val[0] = 1;
    dfs(1, 1, n);
    vector<int> v;
    for(int i = 1; i <= n; ++i)
        if(ans[i]) v.pb(i);
    cout << v.size() << '\n';
    for(auto u : v)
        cout << u << ' ';
}