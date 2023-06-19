#include "stdio.h"

int main(void) {
  long long K,N,i;
  scanf("%lld",&N);
  scanf("%lld",&K);
  long long boxes[K];
  for(i=0;i<K;++i)
    scanf("%lld",&boxes[i]);
  long long theone = N ;
  long long result = 0 ;
  for(i=0;i<K;++i){
    if(N%boxes[i]<theone){
      theone=N%boxes[i];
      result=i;
    }
  }
  long long a=result+1;
  long long b=N/boxes[result];
  printf("%lld ",a);
  printf("%lld ",b);
}