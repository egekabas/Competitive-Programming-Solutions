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
int n, m, k;
int prt[1009];
int sz[1009];
int sp[1009];
int ed[1009];
int ans = 0;
void create(int x, int special){
    prt[x] = x;
    sz[x] = 1;
    sp[x] = special;
    ed[x] = 0;
}
int find(int x){
    if(prt[x] == x) return x;
    return prt[x] = find(prt[x]);
}
void merge(int x, int y){
    x = find(x); y = find(y);
    if(x == y){
        ed[x]++;
        return;
    }
    if(sz[y] > sz[x]) swap(x, y);
    prt[y] = x;
    ed[x] += ed[y]+1;
    sz[x] += sz[y];
    sp[x] ^= sp[y];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m >> k;
    int tmp;
    for(int i = 0; i < k; ++i){
        cin >> tmp;
        create(tmp, 1);
    }
    for(int i = 1; i <= n; ++i)
        if(prt[i] == 0)
            create(i, 0);
    int tmp1, tmp2;
    for(int i = 0; i < m; ++i){
        cin >> tmp1 >> tmp2;
        merge(tmp1, tmp2);
    }

    int max_size = -1; int spname = -1;
    for(int i = 1; i <= n; ++i){
        tmp = find(i);
        ans += sz[tmp]*(sz[tmp]-1)/2-ed[tmp];
        ed[tmp] = sz[tmp]*(sz[tmp]-1)/2;
        if(sz[tmp] > max_size && sp[tmp] == 1){
            max_size = sz[tmp];
            spname = tmp;
        }
    }
    for(int i = 1; i <= n; ++i){
        tmp = find(i);
        if(sp[tmp] == 1) continue;
        ans += sz[tmp]*sz[spname];
        merge(tmp, spname);
        spname = find(spname);
    }
    cout << ans << endl;

}