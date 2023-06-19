#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
char a[10000009];
pair<int, pair<int,int>> t[10000009];
void build(char a[], int v, int tl, int tr) {
    if (tl == tr) {
        if(a[tl] == '(' )
            ++t[v].ss.ff;
        else
            ++t[v].ss.ss;
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].ff = t[2*v].ff + t[2*v+1].ff;
        t[v].ff += min(t[2*v].ss.ff, t[2*v+1].ss.ss);
        t[v].ss.ff = t[2*v].ss.ff - min(t[2*v].ss.ff, t[2*v+1].ss.ss) + t[2*v+1].ss.ff;
        t[v].ss.ss = t[2*v+1].ss.ss - min(t[2*v].ss.ff, t[2*v+1].ss.ss) + t[2*v].ss.ss ;
    }
}

pair<int,pair<int,int>> sum(int v, int tl, int tr, int l, int r) {
    if(l > r || tl > tr)
        return make_pair(0, make_pair(0,0));
    if (l == tl && r == tr) {
        return make_pair(t[v].ff, make_pair(t[v].ss.ff, t[v].ss.ss));
    }
    //cout << l <<" " <<r  << " " << tl << " " << tr << endl;
    int tm = (tl + tr) / 2;
    pair<int,pair<int,int>> x, left, right;
    left =  sum(v*2, tl, tm, l, min(r, tm));
    right = sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    x.ff = left.ff + right.ff;
    x.ff += min(left.ss.ff, right.ss.ss);
    x.ss.ff = left.ss.ff - min(left.ss.ff, right.ss.ss) + right.ss.ff;
    x.ss.ss = right.ss.ss - min(left.ss.ff, right.ss.ss) + left.ss.ss;
    return x;
}


int main(){
    cin >> a;
    int tmp = 0;
    for(int i = 0; a[tmp] != '\0'; ++tmp)
        ;
    --tmp;
    build(a, 1, 0, tmp);
    int q;
    cin >> q;
    int l, r;
    for(int i = 0; i < q; ++i){
        cin >> l >> r;
        if(l == r)
            cout << 0 << endl;
        else
            cout << 2*(sum(1, 1, tmp+1, l, r).ff) << endl;
    }

}