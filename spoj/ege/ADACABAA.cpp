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
map<int, int> fen[200009];
void upd(int x, int y, int val){
    int tmpy;
    while(x <= n){
        tmpy = y;
        while(tmpy <= n){
            if(fen[x][tmpy] != 0)
                fen[x][tmpy] = min(fen[x][tmpy], val);
            else
                fen[x][tmpy] = val;
            tmpy += tmpy&(-tmpy);
        }
        x += x&(-x);
    }
}
int get(int x, int y){
    int ret = 1e9;
    int tmpy;
    while(x > 0){
        tmpy = y;
        while(tmpy > 0){
            if(fen[x][tmpy] != 0)
                ret = min(ret, fen[x][tmpy]);
            tmpy -= tmpy&(-tmpy);
        }
        x -= x&(-x);
    }
    return ret;
}
struct vege{
    int a, b, c, d;
};
int func(vege a, vege b){
    if(a.a != b.a) return a.a < b.a;
    if(a.b != b.b) return a.b < b.b;
    if(a.c != b.c) return a.c < b.c;
    return a.d < b.d;
}
vector<vege> v;
int main() {
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n;
    int ans = n;
    int t1, t2, t3, t4;
    for(int i = 0; i < n; ++i){
        cin >> t1 >> t2 >> t3 >> t4;
        v.pb({t1, t2, t3, t4});
    }
    sort(v.begin(), v.end(), func);
    for(auto u: v){
        if(get(u.b, u.c) < u.d){
            --ans;
            continue;
        }
        upd(u.b, u.c, u.d);
    }
    cout << ans << endl;
