#include "stdio.h"
long long power(long long a,long long b){
  if(b==0)
    return 1;
  long long i;
  long long k=a;
  for(i=1;i<b;++i)
    a=a*k;
  return a;
}
int main(void) {
  long long l,r,i;
  scanf("%lld %lld",&l,&r);
  long long count=0;
  long long a,b;
  for(a=0;power(2,a)<=r;++a)
    for(b=0;power(2,a)*power(3,b)<=r;++b){
      if(power(2,a)*power(3,b)<l)
        continue;
      ++count;
    }
  printf("%lld",count);
}