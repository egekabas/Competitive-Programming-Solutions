#include "stdio.h"

int main(void) {
  int i,n;
  char move;
  int location[2];
  location[0]=0;
  location[1]=0;
  scanf("%d",&n);
  int kingdom,coins=0;
  kingdom = -1;
  char array[n];
  scanf("%s",array);
  for(i=0;i<n;++i){
    move = array[i];
    if(move=='U')
      ++ location[1];
    else
      ++ location[0];
    if(location[0]>location[1]){
      if(kingdom==1)
        ++coins;
      kingdom=2;
    }
    if(location[1]>location[0]){
      if(kingdom==2)
        ++coins;
      kingdom=1;
    }
  }
  printf("\n%d",coins);
}