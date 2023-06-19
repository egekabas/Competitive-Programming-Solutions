#include "wombats.h"
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int r, c;
const int sq = 15;
int h[5000][200];
int v[5000][200];
int dis[5000/sq+5][200][200];
    
void dijkstra1(int beg, int end, int imp, int dis[200]){
    for(int j = 0; j < c; ++j)
        dis[j] = 1e9+7;
    dis[imp] = 0;
    for(int i = end; i >= beg; --i){
        for(int j = 1; j < c; ++j)
            dis[j] = min(dis[j], dis[j-1]+h[i][j-1]);
        for(int j = c-2; j >= 0; --j)
            dis[j] = min(dis[j], dis[j+1]+h[i][j]);
        for(int j = 0; j < c && i != beg; ++j)
            dis[j] = min((int)1e9+7, dis[j] + v[i-1][j]);
    }
}
int cnt;
int segdis[(5000/sq)*4+5][200][200];
int opt[200][200];
void calc(int v, int tl, int tr, int idx){
    if(tl == tr){
        for(int i = 0; i < c; ++i)
            for(int j = 0; j < c; ++j){
                segdis[v][i][j] = dis[tl][j][i];
            }
        return;
    }
    int tm = (tl+tr)/2;
    if(idx <= tm || idx == -1)
        calc(2*v, tl, tm, idx);
    if(idx > tm || idx == -1)
        calc(2*v+1, tm+1, tr, idx);
    for(int i = c-1; i >= 0; --i)
        for(int j = 0; j < c; ++j){
            int beg = 0, en = c-1;
            if(i+1 < c)
                en = opt[i+1][j];
            if(j > 0)
                beg = opt[i][j-1];
            
            pii mini = {1e9+7, 1e9+7};
            for(int k = beg; k <= en; ++k)
                mini = min(mini, {segdis[2*v][i][k]+segdis[2*v+1][k][j], k});
            segdis[v][i][j] = mini.ff;
            opt[i][j] = mini.ss;
        }    
}
    
void init(int R, int C, int H[5000][200], int V[5000][200]) {
    r = R;
    c = C;
    for(int i = 0; i < r; i += sq)
        cnt = max(cnt, i/sq);
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j){
            h[i][j] = H[i][j];
            v[i][j] = V[i][j];
        }
    for(int i = 0; i < r; i += sq)
        for(int j = 0; j < c; ++j)
            dijkstra1(i, min(i+sq, r-1), j, dis[i/sq][j]);
    calc(1, 0, cnt, -1);
}
vector<int> change;
void changeH(int P, int Q, int W) {
    h[P][Q] = W;
    int gr = P/sq;
    change.pb(gr);
    if(gr > 0 && P%sq == 0){
        change.pb(gr-1);
    }
}
    
void changeV(int P, int Q, int W) {
    v[P][Q] = W;
    int gr = P/sq;
    change.pb(gr);
}
int curd[200];
int newd[200];
int done[sq+5];
int changed[200];
int escape(int V1, int V2) {
    for(auto u : change){
        if(done[u]) continue;
        for(int j = 0; j < c; ++j)
            dijkstra1(u*sq, min(r-1, (u+1)*sq), j, dis[u][j]);
        calc(1, 0, cnt, u);
    }
    
    for(auto u : change)
        done[u] = 0;
    change.clear();
    return segdis[1][V1][V2];
}
