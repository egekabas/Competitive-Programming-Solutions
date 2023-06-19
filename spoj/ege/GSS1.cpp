#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
long long a[50009];
long long n, m;
pair<pair<long long ,long long >,pair<long long , long long >> t[200009];
void build(long long a[], long long v, long long tl, long long tr) {
    if (tl == tr) {
        t[v].ff.ff = a[tl];
        t[v].ss.ss = t[v].ss.ff = a[tl];
        t[v].ff.ss = a[tl];
    }
    else {
        long long tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].ff.ff = t[v*2].ff.ff + t[v*2+1].ff.ff;
        t[v].ss.ff = max(t[v*2].ss.ff, t[v*2].ff.ff + t[v*2+1].ss.ff);
        t[v].ss.ss = max(t[v*2+1].ss.ss,t[v*2+1].ff.ff + t[v*2].ss.ss);
        t[v].ff.ss = max(t[v].ss.ss, max(t[v].ss.ff, max(t[v].ff.ff, max(t[v*2].ss.ss + t[2*v+1].ss.ff, max(t[2*v].ff.ss, t[2*v+1].ff.ss)))));
    }
}
pair<pair<long long , long long >,pair<long long , long long >> sum(long long v, long long tl, long long tr, long long l, long long r) {
    if (l > r)
        return make_pair(make_pair(-1000000,-1000000), make_pair(-1000000,-1000000));
    if (l == tl && r == tr) {
        return t[v];
    }
    long long tm = (tl + tr) / 2;
    pair<pair<long long ,long long >, pair<long long , long long >> a = sum(v*2, tl, tm, l, min(r, tm));
    pair<pair<long long ,long long >, pair<long long , long long >> b = sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    pair<pair<long long ,long long >, pair<long long , long long >> c;
    c.ff.ff = a.ff.ff + b.ff.ff;
    c.ss.ff = max(a.ss.ff, a.ff.ff + b.ss.ff);
    c.ss.ss = max(b.ss.ss, b.ff.ff + a.ss.ss);
    c.ff.ss = max(c.ss.ss, max(c.ss.ff, max(c.ff.ff, max(a.ss.ss + b.ss.ff, max(a.ff.ss, b.ff.ss)))));
    return c;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(long long i = 0; i < n; ++i){
        cin >> a[i];
    }
    build(a, 1, 0, n-1);
    cin >> m;
    long long l, r;
    for(long long i = 0; i < m; ++i ){
        cin >> l >> r;
        long long ans = sum(1, 0, n-1, l-1, r-1).ff.ss;
        cout << ans << endl;
    }
}
