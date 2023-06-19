#include <bits/stdc++.h>
int main(){
  long long big[2],k,i,n,a,b;
  scanf("%lld %lld %lld",&n,&a,&b);
  long long arr[n+10];
  long long brr[n+10];
  long long fark[n+10];
  for(i=0;i<n;++i)
    scanf("%lld",&arr[i]);
  for(i=0;i<n;++i)
    scanf("%lld",&brr[i]);
  for(i=0;i<n;++i){
    if(brr[i]>=arr[i])
      fark[i]=brr[i]-arr[i];
    else
      fark[i]=arr[i]-brr[i];
  }
  long long c=a+b;
  
  for(i=0;i<c;++i){
    big[0]=-100;
    big[1]=0;
    for(k=0;k<n;++k)
      if(fark[k]>=big[0]){
        big[0]=fark[k];
        big[1]=k;
      }
    if(fark[big[1]]==0)
      ++fark[big[1]];
    else
      --fark[big[1]];
  }
  long long answer=0;
  for(i=0;i<n;++i)
    answer += fark[i]*fark[i];
  printf("%lld",answer);
}