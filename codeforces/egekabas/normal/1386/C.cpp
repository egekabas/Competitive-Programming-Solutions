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
int st = 1;
int prt[200009];
int col[200009];
int sz[200009];
int n, m, q;
pii getprt(int x){
    int c = 0;
    while(prt[x] != x){
        c ^= col[x];
        x = prt[x];
    }
    c ^= col[x];
    return {x, c};
}
struct bef{
    int x, cx, szx;
    int y, cy, szy;
    int stback;
};
vector<bef> rollback;
void unite(int x1, int y1){
    pii x = getprt(x1);
    pii y = getprt(y1);
    if(x.ff == y.ff){
        rollback.pb({x.ff, col[x.ff], sz[x.ff], y.ff, col[y.ff], sz[y.ff], st});
        if(x.ss == y.ss)
            st = 0;
        return;
    }
    if(sz[y.ff] > sz[x.ff])
        swap(x, y);
    rollback.pb({x.ff, col[x.ff], sz[x.ff], y.ff, col[y.ff], sz[y.ff], st});
    if((y.ss^col[x.ff]) != (x.ss^1))
        col[y.ff] ^= 1;
    sz[x.ff] += sz[y.ff];
    prt[y.ff] = x.ff;
}
void roll(){
    if(rollback.empty()) return;
    bef sta = rollback.back();
    col[sta.x] = sta.cx;
    sz[sta.x] = sta.szx;
    prt[sta.x] = sta.x;
    col[sta.y] = sta.cy;
    sz[sta.y] = sta.szy;
    prt[sta.y] = sta.y;
    st = sta.stback;
    rollback.pop_back();
}
pii edge[200009];
int ans[200009];
vector<int> erase;
void rec(int l1, int l2, int r1, int r2){
    if(l1 > l2) return;
    int lmid = (l1+l2)/2;
    int cnt1 = 0;
    for(int i = l1; i < lmid; ++i){
        ++cnt1;
        unite(edge[i].ff, edge[i].ss);
    }
    int cnt2 = 0;
    for(int i = r2; i >= r1; --i){
        if(i != m){
            ++cnt2;
            unite(edge[i].ff, edge[i].ss);
        }
        if(!st){
            ans[lmid] = i;
            break;
        }
    }
    if(st)
        ans[lmid] = lmid-1;

    while(cnt2--) roll();

    unite(edge[lmid].ff, edge[lmid].ss);
    rec(lmid+1, l2, ans[lmid], r2);
    roll();

    while(cnt1--)roll();
    cnt1 = 0;
    for(int i = r2; i > ans[lmid]; --i)
        if(i != m){
            ++cnt1;
            unite(edge[i].ff, edge[i].ss);
        }
    rec(l1, lmid-1, r1, ans[lmid]);
    while(cnt1--)roll();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i){
        prt[i] = i;
        sz[i] = 1;
    }
   
    for(int i = 0; i < m; ++i)
        cin >> edge[i].ff >> edge[i].ss;
    rec(0, m-1, 0, m);
    for(auto u : erase)
        ans[u] = -1;
    while(q--){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if(r >= ans[l])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}