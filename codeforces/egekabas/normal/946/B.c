#include <stdio.h>

typedef long long ll;

int main(void) {
  
  ll a,b;
  
  scanf("%I64d %I64d",&a,&b);
  
  while(a!=0 && b!=0){
    if(a>=2*b){
      a=a%(2*b);
      continue;
    }
    if(b>=2*a){
      b = b%(2*a);
      continue;
    }
    break;
  }
  printf("%I64d %I64d",a,b);
  return 0;
}