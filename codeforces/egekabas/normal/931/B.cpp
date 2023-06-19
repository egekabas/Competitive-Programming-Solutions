#include "stdio.h"
#include "math.h"
int findmatch(int a){
  if(a%2==0)
    return a/2;
  else
    return a/2 + 1;
}
int main(void) {
  int n,a,b;
  int rounds=0;
  scanf("%d",&n);
  scanf("%d",&a);
  scanf("%d",&b);
  while(1){
    ++rounds;
    a = findmatch(a);
    b = findmatch(b);
    if(a==b)
      break;
  }
  if(rounds==log2(n))
    printf("Final!");
  else
    printf("%d",rounds);
}