#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
struct node{
    int idx, bef, aft, tot;
};

node merge(node l, node r){
    node ret = {0, 0, 0, 0};
    ret.tot = l.tot + r.tot;
    if(l.idx != 1e9){
        ret.idx = l.idx;
        ret.bef = l.bef;
        ret.aft = l.aft+r.tot;
    }
    else{
        ret.idx = r.idx;
        ret.bef = r.bef+l.tot;
        ret.aft = r.aft;    
    }
    return ret;
}
node seg[8000009];
int start = 1000000;
int N = 2000000;
int n, m;

void build(int v, int tl, int tr){
    if(tl > tr)
        return;
    if(tl == tr){
        seg[v] = {tl-start, 0, 0, 0};
    }
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
void upd(int v, int tl, int tr, int idx){
    if(idx < tl || idx > tr)
        return;
    if(tl == idx && tr == idx){
        seg[v] = {(int)1e9, 0, 0, 1};
    }
    else{
        int tm = (tl+tr)/2;
        upd(2*v, tl, tm, idx);
        upd(2*v+1, tm+1, tr, idx);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
int get(int v, int tl, int tr, int x, int bef, int aft){
    if(tl == tr){
        //cout << seg[v].idx << '\n';
        return tl;
    }
    else{
        int tm = (tl+tr)/2;
        if(seg[2*v+1].idx+aft+seg[2*v+1].aft <= x)
            return get(2*v+1, tm+1, tr, x, bef+seg[2*v].tot, aft);
        return get(2*v, tl, tm, x, bef, aft + seg[2*v+1].tot);
    }
} 
int a[2000009];
set<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        s.insert(i);
    build(1, 0, N);
    int bef = start-1;
    while(m--){
        int x, y;
        cin >> x >> y;
        --y;
        int id = get(1, 0, N, y, 0, 0);
        if(a[id] == 0){
            if(s.erase(x) == 0){
                cout << "-1\n";
                return 0;
            }
            a[id] = x;
        }
        if(a[id] != x){
            cout << "-1\n";
            return 0;
        }
        upd(1, 0, N, id);
        a[bef] = x;
        --bef;
    }

    for(int i = start; i < start+n; ++i){
        if(a[i] == 0){
            a[i] = *s.begin();
            s.erase(s.begin());
        }
        cout << a[i] << ' ';
    }

}