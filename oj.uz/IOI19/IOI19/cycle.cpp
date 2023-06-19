#include "cycle.h"
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
void escape(int n){
 
  bool curval = jump(0);
  if(curval == false)
    jump(n/2);
  int idx = 0;
  int l = 1, r = n-1;
  while(l < r){
    int mid = (l+r+1)/2;
    int jumpval = mid-idx;
    if(jumpval < 0)
      jumpval += n;
    curval = jump(jumpval);
    idx = mid;
    if(curval){
      if(mid < n-n/2)
        l = mid+1;
      else if(mid > n/2)
        r = mid-1;
      else{
        idx = (idx+1)%n;
        curval = jump(1);
        if(curval){
          l = mid-1;
          break;
        }
        else{
          l = n-1;
          break;
        }
      }
    }
    else
      l = mid;
  }
  l = (l+n/2+1)%n;
  int jumpval = l-idx;
  if(jumpval < 0)
    jumpval += n;
  jump(jumpval);
 
}	
