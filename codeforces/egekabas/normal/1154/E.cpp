#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
pii t[1000000];
int marked[1000000];
int go[1000000];
int a[1000000];
int col[1000000];
void push(int v) {
    if (marked[v]) {
        t[v*2].ff = t[v*2+1].ff = t[v].ff;
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {a[tl], tl};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        if(t[v*2].ff > t[v*2+1].ff)
            t[v] = t[v*2];
        else{
            t[v] = t[v*2+1];
        }
    }
}
void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].ff = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        if(t[v*2].ff > t[v*2+1].ff)
            t[v] = t[v*2];
        else{
            t[v] = t[v*2+1];
        }
    }
}
pii mini(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {-1e6,-1e6};
    if (l == tl && r == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    pii tmp1 = mini(v*2, tl, tm, l, min(r, tm));
    pii tmp2 = mini(v*2+1, tm+1, tr, max(l, tm+1), r);
    if(tmp1.ff > tmp2.ff) return tmp1;
    else return tmp2;
}
int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i <= n+10; ++i){
        go[i] = -1e6;    
    }
    build(a, 1, 0, n);

    int team = 0;
    while(1){
        pii tmpp = mini(1, 0, n, 0, n-1);
        //cout << tmpp.ff << " " << tmpp.ss << "\n";
        if(tmpp.ff == -(int)1e6) break;
        int tmp = k;
        int i = tmpp.ss;
        col[i] = team+1;
        while(tmp > 0){
            --i;
            if(i < 0) break;
            while(i >= 0 && go[i] != -1e6){
                i = go[i];
            }
            if(i < 0) break;
            --tmp;
            col[i] = team+1;    
        }
        int lower = max(0, i);
        tmp = k;
        i = tmpp.ss;
        while(tmp > 0){
            ++i;
            if(i >= n) break;
            while(i >= 0 && go[i] != -1e6){
                i = go[i];
                //cout << i << endl;
            }
            if(i >= n) break;
            --tmp;
            col[i] = team+1;    
        }
        int upper = min(n-1, i);
        go[lower] = upper+1;
        go[upper] = lower-1;
        update(1, 0, n, lower, upper, -1e6);   
        team ^= 1;
    }
    for(int i = 0; i < n; ++i)
        cout << col[i];
    cout << endl;
}