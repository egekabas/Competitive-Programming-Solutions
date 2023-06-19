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
const ll mod = 1e9+7;
ll pw(ll x, ll y = mod-2){
    ll ret = 1;
    while(y > 0){
        if(y%2)
            ret = ret*x%mod;
        x = x*x%mod;
        y /= 2;
    }
    return ret;
}
vector<int> seg[400009];
void build(int v, int tl, int tr, vector<vector<int>> &ar){
    if(tl == tr){
        seg[v] = ar[tl];
        return;
    }
    build(2*v, tl, (tl+tr)/2, ar);
    build(2*v+1, (tl+tr)/2+1, tr, ar);
    seg[v].resize(seg[2*v].size());
    for(int i = 0; i < seg[v].size(); ++i)
        seg[v][i] = max(seg[2*v][i], seg[2*v+1][i]);
}
vector<int> ansvec;
void get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return;
    if(l <= tl && tr <= r){
        for(int i = 0; i < seg[v].size(); ++i)
            ansvec[i] = max(ansvec[i], seg[v][i]);
        return;
    }
    else{
        get(2*v, tl, (tl+tr)/2, l, r);
        get(2*v+1, (tl+tr)/2+1, tr, l, r);
    }
}
struct node{
    int val = 1;
    node *l = nullptr, *r = nullptr;
    node(){}
    node(int v){
        val = v;
    }
    node(node *lef, node *rig){
        l = lef;
        r = rig;
        val = (ll)l->val*r->val%mod;
    }
};
node *build(int tl, int tr){
    if(tl == tr)
        return new node(1);
    return new node(build(tl, (tl+tr)/2), build((tl+tr)/2+1, tr));
}
node *upd(node *cur, int tl, int tr, int idx, ll val){
    if(tl == idx && tr == idx)
        return new node(val);
    if(idx <= (tl+tr)/2)
        return new node(upd(cur->l, tl, (tl+tr)/2, idx, val), cur->r);
    else
        return new node(cur->l, upd(cur->r, (tl+tr)/2+1, tr, idx, val));
}
ll get(node *cur, int tl, int tr, int l, int r){
    if(r < tl || tr < l)
        return 1;
    if(l <= tl && tr <= r)
        return cur->val;
    else{
        return get(cur->l, tl, (tl+tr)/2, l, r)*get(cur->r, (tl+tr)/2+1, tr, l, r)%mod;
    }
}
int sq = 500;
int n;
int a[100009];
int big[100009];
int mpp[100009][500];
vector<int> pr;
vector<vector<int>> nar;
node* pers[100009];
int last[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        big[i] = 1;
        int tmp = a[i];
        for(int j = 2; j*j <= tmp; ++j){
            if(tmp%j == 0)
                pr.pb(j);
            while(tmp%j == 0){
                mpp[i][j]++;
                tmp /= j;
            }
        }
        if(tmp == 1) continue;
        if(tmp >= sq)
            big[i] = tmp;
        else{
            mpp[i][tmp]++;
            pr.pb(tmp);
        }
    }
    sort(all(pr));
    pr.resize(unique(all(pr))-pr.begin());
    
    nar = vector<vector<int>>(n, vector<int>(pr.size()));
    for(int i = 0; i <  pr.size(); ++i){
        for(int j = 0; j < n; ++j)
            nar[j][i] = mpp[j][pr[i]];
    }
    build(1, 0, n-1, nar);
    pers[n] = build(0, n-1);

    for(int i = n-1; i >= 0; --i){
        pers[i] = pers[i+1];
        if(big[i] == 1) continue;
        if(last[big[i]] != 0)
            pers[i] = upd(pers[i], 0, n-1, last[big[i]], 1);
        last[big[i]] = i;
        pers[i] = upd(pers[i], 0, n-1, i, big[i]);
    }
    ll ans = 0;
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l = (l+ans)%n;
        r = (r+ans)%n;
        if(l > r)
            swap(l, r);
        ans = 1;
        ansvec = vector<int>(pr.size());
        get(1, 0, n-1, l, r);
        for(int i = 0; i < pr.size(); ++i){
            ans = ans*pw(pr[i], ansvec[i])%mod;
        }
        ans = ans*get(pers[l], 0, n-1, l, r)%mod;
        cout << ans << '\n';
    }
}