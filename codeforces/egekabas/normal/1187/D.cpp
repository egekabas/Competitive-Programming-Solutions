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

int t[1200009];
int a[300009];
queue<int> q[300009];
int n;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } 
    else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
int get(int v, int tl, int tr, int l, int r) {
    if (l > r || tl > r || tr < l) 
        return 1e9;
    if (l <= tl && r >= tr) 
        return t[v]; 
    int tm = (tl + tr) / 2;
    return min(get(v*2, tl, tm, l, r)
           ,get(v*2+1, tm+1, tr, l, r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) 
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i <= n; ++i)
            while(q[i].size() > 0)
                q[i].pop();
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            q[a[i]].push(i);
        }
        build(1, 0, n-1);
        int ok = 1; int b;
        for(int i = 0; i < n; ++i){
            cin >> b;
            if(q[b].size() == 0){
                ok = 0;
                continue;
            }
            int idx = q[b].front();
            q[b].pop();
            int tmp = get(1, 0, n-1, 0, idx);
            //cout << b << " " << idx << " " << tmp << endl;
            if(tmp != b){
                ok = 0;
            }
            else{
                update(1, 0, n-1, idx, 1e9);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}