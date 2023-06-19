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
int n;
pair<pii, pii> a[100009];
int segmini[400009];
int segmaxi[400009];

void build(int v, int tl, int tr){
    if(tl > tr)
        return;
    if(tl == tr){
        segmini[v] = a[tl].ss.ss;
        segmaxi[v] = a[tl].ss.ff;
    }
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        segmini[v] = min(segmini[2*v], segmini[2*v+1]);
        segmaxi[v] = max(segmaxi[2*v], segmaxi[2*v+1]);
    }
}
pii get(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l)
        return {1e9, -1e9};
    if(l <= tl && tr <= r)
        return {segmini[v], segmaxi[v]};
    else{
        int tm = (tl+tr)/2;
        pii a = get(2*v, tl, tm, l, r);
        pii b = get(2*v+1, tm+1, tr, l, r);
        return {min(a.ff, b.ff), max(a.ss, b.ss)};
    }
}

int main() {

    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i].ff.ff >> a[i].ff.ss
        >> a[i].ss.ff >> a[i].ss.ss;

    sort(a, a+n);
    build(1, 0, n-1);
    for(int i = n-1; i >= 0; --i){
        int upper = upper_bound(a, a+n, mp(mp(a[i].ff.ss, (int)1e9), mp((int)1e9, (int)1e9)))-a;
        --upper;
        pii pr = get(1, 0, n-1, i, upper);
        if(pr.ff < a[i].ss.ff || pr.ss > a[i].ss.ss){
           printf("NO\n");
           return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        swap(a[i].ff.ff, a[i].ss.ff);
        swap(a[i].ff.ss, a[i].ss.ss);
    }

    sort(a, a+n);
    build(1, 0, n-1);
    for(int i = n-1; i >= 0; --i){
        int upper = upper_bound(a, a+n, mp(mp(a[i].ff.ss, (int)1e9), mp((int)1e9, (int)1e9)))-a;
        --upper;
        pii pr = get(1, 0, n-1, i, upper);
        if(pr.ff < a[i].ss.ff || pr.ss > a[i].ss.ss){
           printf("NO\n");
           return 0;
        }
    }    
    printf("YES\n");
}