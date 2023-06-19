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
int a[200009];
int b[200009];
pii qu[200009];
int seg[800009][2];
void push(int v, int sz){
    if(seg[v][0] == sz){
        seg[2*v][0] = (sz+1)/2;
        seg[2*v][1] = 0;

        seg[2*v+1][0] = sz/2;
        seg[2*v+1][1] = 0;
    }
    if(seg[v][1] == sz){
        seg[2*v][1] = (sz+1)/2;
        seg[2*v][0] = 0;

        seg[2*v+1][1] = sz/2;
        seg[2*v+1][0] = 0;
    }
}

void build(int v, int tl, int tr){
    if(tl == tr){
        seg[v][0] = seg[v][1] = 0;
        seg[v][a[tl]] = 1;
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);

    seg[v][0] = seg[2*v][0] + seg[2*v+1][0];
    seg[v][1] = seg[2*v][1] + seg[2*v+1][1];
}
pii get(int v, int tl, int tr, int l, int r){
    if(tr < l || r < tl)
        return {0, 0};
    if(l <= tl && tr <= r)
        return {seg[v][0], seg[v][1]};
    push(v, tr-tl+1);
    pii a = get(2*v, tl, (tl+tr)/2, l, r);
    pii b = get(2*v+1, (tl+tr)/2+1, tr, l, r);
    return {a.ff+b.ff, a.ss+b.ss};
}
void upd(int v, int tl, int tr, int l, int r, int val){
    if(tr < l || r < tl)
        return;
    if(l <= tl && tr <= r){
        seg[v][val^1] = 0;
        seg[v][val] = tr-tl+1;
        return;
    }
    push(v, tr-tl+1);
    upd(2*v, tl, (tl+tr)/2, l, r, val);
    upd(2*v+1, (tl+tr)/2+1, tr, l, r, val);
    seg[v][0] = seg[2*v][0]+seg[2*v+1][0];
    seg[v][1] = seg[2*v][1]+seg[2*v+1][1];
}
void solve(){
    cin >> n >> q;
    string s, f;
    cin >> s >> f;
    for(int i = 0; i < n; ++i){
        a[i] = f[i]-'0';
        b[i] = s[i]-'0';
    }
    for(int i = 0; i < q; ++i){
        cin >> qu[i].ff >> qu[i].ss;
        --qu[i].ff;
        --qu[i].ss;
    }
    reverse(qu, qu+q);
    build(1, 0, n-1);
    for(int i = 0; i < q; ++i){
        pii val = get(1, 0, n-1, qu[i].ff, qu[i].ss);
        if(val.ff == val.ss){
            cout << "NO\n";
            return;
        }
        if(val.ff > val.ss)
            upd(1, 0, n-1, qu[i].ff, qu[i].ss, 0);
        else
            upd(1, 0, n-1, qu[i].ff, qu[i].ss, 1);
    }
    for(int i = 0; i < n; ++i){
        pii val = get(1, 0, n-1, i, i);
        int cur;
        if(val.ff) cur = 0;
        else cur = 1;
        if(cur != b[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();
}