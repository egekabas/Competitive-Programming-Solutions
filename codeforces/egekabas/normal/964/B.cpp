#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
int answer,n,A,B,C,T;
int arr[MAX];
int main(){
  scanf("%d %d %d %d %d",&n,&A,&B,&C,&T);
  int k,i,t;
  for(i=0;i<n;++i){
    scanf("%d",&arr[i]);
  }
  for(i=0;i<n;++i){
    k=0;
    for(t=arr[i];t<=T;++t)
      if(C*(t-arr[i]) + A-B*(t-arr[i]) >= k)
        k=C*(t-arr[i]) + A-B*(t-arr[i]);
    answer += k;
  }
  printf("%d",answer);
}