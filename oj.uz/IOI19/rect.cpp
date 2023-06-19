#include "rect.h"
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
int bit[2509][2509];
int n, m;
void upd(int x, int y, int val){
  for(int i1 = x+1; i1 > 0; i1 -= i1&(-i1))
    for(int i2 = y+1; i2 <= m+2; i2 += i2&(-i2))
      bit[i1][i2] += val;
}
int get(int x, int y){
  int ret = 0;
  for(int i1 = x+1; i1 <= n+2; i1 += i1&(-i1))
    for(int i2 = y+1; i2 > 0; i2 -= i2&(-i2))
      ret += bit[i1][i2];
  return ret;
}
  
long long count_rectangles(std::vector<std::vector<int> > a) {
  n = a.size(), m = a[0].size();
  
  vector<vector<vector<int>>> pos(m, vector<vector<int>>(m));
  for(int i = 0; i < n; ++i){
    vector<int> cur;
    for(int j = m-1; j >= 0; --j){
      while(cur.size() && a[i][cur.back()] < a[i][j]){
        pos[j][cur.back()].pb(i);
        cur.pop_back();
      }
      if(cur.size())
        pos[j][cur.back()].pb(i);
      while(cur.size() && a[i][cur.back()] <= a[i][j])
        cur.pop_back();
      
      cur.pb(j);
    }
  }
  vector<vector<pair<pii, int>>> maxval(m);
  
  for(int x = 0; x < m; ++x)
    for(int y = x+2; y < m; ++y)
      for(int i = 0; i < pos[x][y].size();){
        int j;
        for(j = i+1; j < pos[x][y].size(); ++j)
          if(pos[x][y][j] != pos[x][y][j-1]+1)
            break;
        int l = pos[x][y][i];
        int r = pos[x][y][j-1];
        //cout << x << ' ' << y << ' ' << l << ' ' << r << '\n';
        maxval[x].pb({{l, r}, y});
        i = j;
      }
    
  pos = vector<vector<vector<int>>>(n, vector<vector<int>>(n));
  
  for(int i = 0; i < m; ++i){
    vector<int> cur;
    for(int j = n-1; j >= 0; --j){
      while(cur.size() && a[cur.back()][i] < a[j][i]){
        pos[j][cur.back()].pb(i);
        cur.pop_back();
      }
      if(cur.size())
        pos[j][cur.back()].pb(i);
      while(cur.size() && a[cur.back()][i] <= a[j][i])
        cur.pop_back();
      
      cur.pb(j);
    }
  }
  vector<vector<pair<pii, int>>> fin(m);
  
  for(int x = 0; x < n; ++x)
    for(int y = x+2; y < n; ++y)
      for(int i = 0; i < pos[x][y].size();){
        int j;
        for(j = i+1; j < pos[x][y].size(); ++j)
          if(pos[x][y][j] != pos[x][y][j-1]+1)
            break;
        int l = pos[x][y][i];
        int r = pos[x][y][j-1];
        for(int k = l; k <= r; ++k)
          fin[k].pb({{x, y}, r});
  
        i = j;
      }
  ll ans = 0;
  for(int i = 1; i < m; ++i){
    sort(all(fin[i]));
    sort(all(maxval[i-1]));
    int curidx = 0;
    for(auto u : fin[i]){
      while(curidx < (int)maxval[i-1].size() && maxval[i-1][curidx].ff.ff <= u.ff.ff+1){
        upd(maxval[i-1][curidx].ff.ss, maxval[i-1][curidx].ss, 1);
        ++curidx;
      }
      int val = get(u.ff.ss-1, u.ss+1);
      //cout << i << ' ' << u.ss << ' ' << u.ff.ff << ' ' << u.ff.ss << ' ' << val << '\n';
      ans += val;
    }
    for(int j = 0; j < curidx; ++j)
      upd(maxval[i-1][j].ff.ss, maxval[i-1][j].ss, -1);
  }
  return ans;
}
