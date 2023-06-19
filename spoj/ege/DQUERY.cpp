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

int n, a[30009], q, sq;
int ans;
int m[1000009];
int fin[200009];
vector<pair<pii, int>> v;
int l ,r;

bool func(pair<pii, int> a, pair<pii, int> b){
    if(a.ff.ff/sq != b.ff.ff/sq)
        return a.ff.ff/sq < b.ff.ff/sq;
    return a.ff.ss < b.ff.ss;
}

int main() {

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n;
    sq = sqrt(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    cin >> q;
    int q1,q2;
    for(int i = 0; i < q; ++i){
        scanf("%d%d", &q1, &q2);
        --q1; --q2;
        v.pb({{q1, q2}, i});
    }

    l = r = 0; ans = 1; m[a[0]] = 1;
    sort(v.begin(), v.end(), func);

    for(auto u : v){
        int x = u.ff.ff; int y = u.ff.ss;
        while(r < y){
            ++r;
            ++m[a[r]];
            if(m[a[r]] == 1) ++ans;
        }
        while(l < x){
            --m[a[l]];
            if(m[a[l]] == 0) --ans;
            ++l;
        }
        while(l > x){
            --l;
            ++m[a[l]];
            if(m[a[l]] == 1) ++ ans;
        }
        while(r > y){
            --m[a[r]];
            if(m[a[r]] == 0) --ans;
            --r;
        }
        fin[u.ss] = ans; 
    }
    for(int i = 0; i < q; ++i){
        printf("%d\n", fin[i]);
    }
