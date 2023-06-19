#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
int k, n, m, o;
vector<pii> g[50009];
vector<int> dis[50009][17];
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> k >> n >> m >> o;
 
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
    }
    for(int i = n-1; i >= 0; --i){
        dis[i][0] = vector<int>(k, 1e9);
        for(auto u : g[i]){
            dis[i][0][u.ff%k] = u.ss;
            //cout << i << ' ' << u.ff%k << '\n';
        }
        for(int j = 1; j < 17; ++j){
            dis[i][j] = vector<int>(k, 1e9);
            for(int mn = 0; mn < k; ++mn)
                for(int en = 0; en < k; ++en){
                    int mval = (i/k+(1<<(j-1)))*k+mn;
 
                    if(mval <= n-1)
                        dis[i][j][en] = min(dis[i][j][en], dis[i][j-1][mn]+dis[mval][j-1][en]);
                }
        }
    }
    while(o--){
        int x, y;
        cin >> x >> y;
        vector<int> d(k, 1e9);
        d[x%k] = 0;
        int beg = x/k;
        int end = y/k;
        for(int i = 16; i >= 0; --i){
            if(beg + (1<<i) > end) continue;
            vector<int> nd(k, 1e9);
            for(int mn = 0; mn < k; ++mn){
                int mval = beg*k+mn;
                for(int en = 0; en < k; ++en)
                    nd[en] = min(nd[en], d[mn]+dis[mval][i][en]);
                
            }
            beg += (1<<i);
            d = nd;
        }
        if(d[y%k] == 1e9)
            cout << "-1\n";
        else
            cout << d[y%k] << '\n';
    }
}
