#include <stdio.h>
int arr[100000];
int main(void) {
  int s,i,n,p;
  scanf("%d %d",&n,&p);
  for(i=0;i<n;++i){
    scanf("%d",&s);
    arr[i]=s%p;
  }
  int k=0,temp=0,sum=0,opt=0;
  for(i=0;i<n;++i){
      sum += arr[i];
  }
  for(i=0;i<n-1;++i){
      sum -= arr[i];
      temp += arr[i];
      k = sum%p + temp%p;
      if(k>=opt)
        opt = k;
  }
  printf("%d",opt);
}