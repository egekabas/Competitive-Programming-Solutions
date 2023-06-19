#include <bits/stdc++.h>
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
int seg[8000009];
int lazy[8000009];
void push(int v){
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    seg[2*v] += lazy[v];
    seg[2*v+1] += lazy[v];
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val){
    if(r < tl || tr < l) return;
    if(l <= tl && tr <= r){
        seg[v] += val;
        lazy[v] += val;
    }
    else{
        push(v);
        upd(2*v, tl, (tl+tr)/2, l, r, val);
        upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
        seg[v] = max(seg[2*v], seg[2*v+1]);
    }
}
map<int, int> mpp;
 
set<int, greater<int>> s[2000009];
int n, N;
int q;
vector<int> a, x, v;
 
void erase(int idx){
    if(*s[a[idx]].begin() == idx+1){
        upd(1, 0, N, a[idx], a[idx], -(idx+1));
        s[a[idx]].erase(idx+1);
        if(s[a[idx]].size())
            upd(1, 0, N, a[idx], a[idx], *s[a[idx]].begin());
    }
    else
        s[a[idx]].erase(idx+1);
    upd(1, 0, N, a[idx], N, 1);
}
void add(int idx){
    if(s[a[idx]].empty()){
        upd(1, 0, N, a[idx], a[idx], (idx+1));        
    }
    else if(idx+1 > *s[a[idx]].begin()){
        upd(1, 0, N, a[idx], a[idx], -*s[a[idx]].begin());
        upd(1, 0, N, a[idx], a[idx], (idx+1));    
    }
    s[a[idx]].insert(idx+1);
    upd(1, 0, N, a[idx], N, -1);
}
vector<int> countScans(vector<int> a1, vector<int> a2, vector<int> a3){
    a = a1;
    x = a2;
    v = a3;
    n = a.size();
    q = v.size();
    vector<int> tmp;
    for(auto u : a)
        tmp.pb(u);
    for(auto u : v)
        tmp.pb(u);
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
    N = tmp.size();
    for(int i = 0; i < tmp.size(); ++i)
        mpp[tmp[i]] = i;
    for(int i = 0; i < n; ++i)
        a[i] = mpp[a[i]];
    for(int i = 0; i < q; ++i)
        v[i] = mpp[v[i]];
    
    for(int i = 0; i < n; ++i)
        add(i);
    vector<int> ans(q);
    for(int i = 0; i < q; ++i){
        erase(x[i]);
        a[x[i]] = v[i];
        add(x[i]);
        ans[i] = max(seg[1], 0);
    }
    return ans;
}
/*int main(){
 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), x(q), v(q);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < q; ++i)
        cin >> x[i] >> v[i];
    vector<int> ans = countScans(a, x, v);
    for(auto u : ans)
        cout << u << '\n';
}*/
