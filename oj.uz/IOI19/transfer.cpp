#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
  
std::vector<int> get_attachment(std::vector<int> source) {
  int n = source.size(), k;
  if(n == 63)
    k = 7;
  else
    k = 9;
  
  vector<int> ret(k);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < (k-1); ++j)
      if((1<<j)&(i+1))
        ret[j] ^= source[i];
    ret[k-1] ^= source[i];
  }
  return ret;
}
  
std::vector<int> retrieve(std::vector<int> data) {
  int n, k;
  if(data.size() == 70){
    n = 63, k = 7;
  }
  else{
    n = 255, k = 9;
  }
  vector<int> ori(data.begin(), data.begin()+n);
  int tot = data.back();
  
  vector<vector<int>> vals(2, vector<int>(k-1));
  vals[1] = vector<int>(data.begin()+n, data.end()-1);
  for(int i = 0; i < k-1; ++i)
    vals[0][i] = vals[1][i]^tot;
  
  vector<vector<int>> cur(2, vector<int>(k-1));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < (k-1); ++j)
      cur[((1<<j)&(i+1)) > 0][j] ^= ori[i];
  
  
  int cnt = 0;
  for(int i = 0; i < (k-1); ++i){
    if(cur[0][i] != vals[0][i] && cur[1][i] != vals[1][i]){
      return ori;
    }
    if(cur[0][i] != vals[0][i] || cur[1][i] != vals[1][i])
      ++cnt;
  }
  if(cnt == 0)
    return ori;
  if(cnt != k-1)
    return ori;
  
  int falidx = -1;
  for(int i = 0; i < (k-1); ++i)
    if(cur[1][i] != vals[1][i])
      falidx += (1<<i);
  if(falidx >= 0)
    ori[falidx] ^= 1;
  return ori;
}
