#include <bits/stdc++.h>
using namespace std;

long long m, n, k, l;
pair<long long, bool> st[100009];

int cmpr(pair<long long, bool> a,pair<long long, bool> b){
  return a.first < b. first;
}

int main(){
  cin >> n >> k >> l;
  m = n*k;
  for(long long i = 0; i < m; ++i)
    cin >> st[i].first;
  sort(st, st + m, cmpr);

  long long upper = -1;
  for(int i = 0; i < m; ++i){
    if(st[i].first > st[0].first + l){
      upper = i-1;
      break;
    }
  }
  if(upper == -1)
    upper = m-1;

  long long count = 0;
  long long vol = 0;

  for(long long i = 0; i <= upper; i += k){
      ++count;
      vol += st[i].first;
      st[i].second = 1;
      if(count == n)
        goto END;
    }

  for(long long i = upper; i >= 0; --i){
    if(st[i].second == 1)
      continue;
    ++count;
    vol += st[i].first;
      if(count == n)
      goto END;
  }

  END:
  if(count == n)
    cout << vol;
  else
    cout << 0;
  
}