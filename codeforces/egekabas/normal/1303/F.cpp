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
int col[309*309];
int prt[309*309];
int findprt(int x){
    if(prt[x] == x) return x;
    return (prt[x] = findprt(prt[x]));
}
int merge(int x, int y){
    x = findprt(x);
    y = findprt(y);
    if(x == y) return 0;
    prt[x] = y;
    return 1;
}
vector<pii> add[2000009];
vector<pii> del[2000009];
int n, m, q;
int addnew(int x, int newcol){
    prt[x] = x;
    col[x] = newcol;
    int ret = 1;

    if(x%m != 0 && col[x-1] == newcol)
        ret -= merge(x, x-1);
    if(x%m != m-1 && col[x+1] == newcol)
        ret -= merge(x, x+1);
    if(x + m < m*n && col[x+m] == newcol)
        ret -= merge(x, x+m);
    if(x - m >= 0 && col[x-m] == newcol)
        ret -= merge(x, x-m);
    
    return ret;
}
int ans[2000009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m >> q;
    for(ll i = 0; i < n*m; ++i){
        add[0].pb({0, i});
        col[i] = 0;
    }
    int lastc = 0;
    int bef = 0;
    int cur = 1;
    for(ll i = 1; i <= q; ++i){
        int x, y, newcol;
        cin >> x >> y >> newcol;
        if(newcol == bef)newcol = cur-1;
        else{
            bef = newcol;
            newcol = cur++;
        }
        --x, --y;
        if(newcol == col[m*x+y]) continue;
        add[newcol].pb({i, m*x+y});
        del[col[m*x+y]].pb({i, m*x+y});
        col[m*x+y] = newcol;
        lastc = newcol;
    }
    for(ll i = 0; i < n*m; ++i)
        col[i] = -1;
    for(int i = 0; i <= lastc; ++i){
        map<int, int> mpp;
        reverse(del[i].begin(), del[i].end());
        for(auto u : add[i]){
            ll tmp = addnew(u.ss, i);
            ans[u.ff] += tmp;
            //cout << i << ' ' << u.ff << ' ' << u.ss << ' ' << tmp << '\n';
        }
        for(auto u : add[i]){
            prt[u.ss] = u.ss;
            col[u.ss] = -1;
        }
        for(auto u : del[i])
            mpp[u.ss] = 1;
        for(auto u : add[i])
            if(!mpp[u.ss]){
                addnew(u.ss, i);
                //cout << u.ss << '\n';
            }
        for(auto u : del[i]){
            ll tmp = addnew(u.ss, i);
            ans[u.ff] -= tmp;
            //cout << i << ' ' << u.ff << ' ' << u.ss << " del " << -tmp << '\n';
        }

    }
    for(ll i = 1; i <= q; ++i){
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }
}