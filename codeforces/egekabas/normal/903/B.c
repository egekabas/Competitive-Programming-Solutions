#include <stdio.h>

int main(void) {
  int h1,a1,c1,h2,a2;
  scanf("%d %d %d %d %d",&h1,&a1,&c1,&h2,&a2);
  int moves=0;
  char array[20000];
  while (1){
    if(h1>a2 || (h1<=a2 && a1 >= h2)){
      array[moves] = 'S';
      h2=h2-a1;
    }
    else{
      array[moves] = 'H';
      h1=h1+c1;
    }
    ++moves;
    if(h2<=0)
      break;
    h1=h1-a2;
  }
  int i;
  printf("%d\n",moves);
  for(i=0;i<moves;++i)
    printf("%s",(array[i]=='S') ? "STRIKE\n" : "HEAL\n");
  
}