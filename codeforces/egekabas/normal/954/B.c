#include "stdio.h"

char array[105];

int main(void) {
  
  int a, n, i, maxsize=1;
  
  scanf("%d",&n);
  scanf("%s",array);
  
  for(i=0;i<n;++i){
    for(a=0 ; array[a]==array[a+i] && a<i ;++a)
      ;
    if(a==i && i>maxsize)
		  maxsize=i;
  }
  printf("%d",n-maxsize + 1);
}