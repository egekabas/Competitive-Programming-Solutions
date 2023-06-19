#include "stdio.h"
int main(void) {
  char str[100000];
  scanf("%s",str);
  int i,a=0;
  for(i=0;str[i]!='\0';++i){
    if(str[i]<= 'a' + a){
      str[i]='a'+a;
      ++a;
    }
    if(a==26){
      printf("%s",str);
      return(0);
    }  
    }
printf("-1");
}