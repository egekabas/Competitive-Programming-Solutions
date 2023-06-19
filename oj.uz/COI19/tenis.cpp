#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pll;
typedef pair<ld, ld>  pld;
struct player{
    int a, b, c;
};
struct node{
    int maxi;
    int go;
};
int n, q;
player ar[100009];
node seg[400009];
int a[100009], b[100009], c[100009];
int getmaxi(player x){
    return max(max(x.a, x.b), (int)x.c);
}
int getmini(player x){
    return min(min(x.a, x.b), (int)x.c);
}
node merge(node a, node b){
    if(b.maxi >= a.go)
        return {b.maxi, max(a.go, b.go)};
    else
        return {a.maxi, max(a.go, b.go)};
    
}
void update(int v, int tl, int tr, int idx){ 
    if(tr < idx || idx < tl)
        return;
    if(tl == idx && tr == idx){
        seg[v].go = max(max(getmaxi(ar[a[tl]]),
        getmaxi(ar[b[tl]])), getmaxi(ar[c[tl]]));
        if(tl >= seg[v].go)
            seg[v].maxi = tl;
        else
            seg[v].maxi = -1;
    }
    else{
        int tm = (tl+tr)/2;
        update(2*v, tl, tm, idx);
        update(2*v+1, tm+1, tr, idx);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
 
node get(int v, int tl, int tr, int l, int r){
    if(r < tl || l > tr)
        return {-1, -1};
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        int tm = (tl+tr)/2;
        return merge(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        ar[a[i]].a = i;
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        ar[b[i]].b = i;
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        ar[c[i]].c = i;
    }
    for(int i = 0; i < n; ++i)
        update(1, 0, n-1, i);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            if(get(1, 0, n-1, 0, getmini(ar[x])-1).maxi != -1)
                cout << "NE\n";
            else
                cout << "DA\n";
        }
        else{
            int x, y, z;
            cin >> x >> y >> z;
            player &p1 = ar[y];
            player &p2 = ar[z];
            if(x == 1){
                swap(p1.a, p2.a);
                swap(a[p1.a], a[p2.a]);
            }
            if(x == 2){
                swap(p1.b, p2.b);
                swap(b[p1.b], b[p2.b]);
            }
            if(x == 3){
                swap(p1.c, p2.c);
                swap(c[p1.c], c[p2.c]);
            }
            update(1, 0, n-1, p1.a);
            update(1, 0, n-1, p1.b);
            update(1, 0, n-1, p1.c);
            
            update(1, 0, n-1, p2.a);
            update(1, 0, n-1, p2.b);
            update(1, 0, n-1, p2.c);
            
        }
    }
}
