#include "highway.h"
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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
vector<int> w;
vector<pii> g[100000];
int vis[100000];
vector<int> vec[2];
vector<int> u, v;
ll begval;
int col[100000];
int get(vector<int> &vec){
  int l = 0, r = vec.size()-1;
  while(l < r){
      int m = (l+r)/2;
      for(int i = m+1; i <= r; ++i)
          col[vec[i]] = 1;
      for(int i = 0; i < u.size(); ++i)
          if(col[u[i]] != col[v[i]])
              w[i] = 1;
      if(ask(w) == begval)
          r = m;
      else
          l = m+1;
      for(int i = 0; i < u.size(); ++i)
          w[i] = 0;
      for(int i = m+1; i <= r; ++i)
          col[vec[i]] = 0;
  }
  return vec[l];
}
void find_pair(int N, std::vector<int> U, std::vector<int> V, int A, int B) {
  u = U;
  v = V;
  w.resize(U.size());
  for(int i = 0; i < U.size(); ++i){
      g[U[i]].pb({V[i], i});
      g[V[i]].pb({U[i], i});
  }
  begval = ask(w);
  int l = 0, r = U.size()-1;
  while(l < r){
      int m = (l+r)/2;
      for(int i = l; i <= m; ++i)
          w[i] = 1;
      if(ask(w) != begval)
          r = m;
      else
          l = m+1;
      for(int i = l; i <= m; ++i)
          w[i] = 0;
  }
  int e = l;
  queue<pii> q;
  q.push({0, U[e]});
  q.push({1, V[e]});
  vis[U[e]] = vis[V[e]] = 1;
  while(q.size()){
      int type = q.front().ff;
      int v = q.front().ss;
      q.pop();
      vec[type].pb(v);
      for(auto u : g[v])
          if(vis[u.ff] == 0){
              vis[u.ff] = 1;
              q.push({type, u.ff});
          }
  }
  answer(get(vec[0]), get(vec[1]));
}
