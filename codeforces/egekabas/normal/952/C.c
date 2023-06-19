#include <stdio.h>
int n;
int input[20];
int output[20];
int find(){
  int tallest=0;
  int store=-1;
  int a;
  for(a=0;a<n;++a)
    if(input[a]>=tallest){
      tallest=input[a];
      store=a;
    }
  return store;
}
void move(int a){
  int k;
  for(k=a;k<n-1;++k)
    input[k]=input[k+1];
}
int check(){
  int k;
  for(k=0;k<n-1;++k)
    if(input[k+1]-input[k]>=2 || input[k]-input[k+1]>=2)
      return 1;
  for(k=0;k<n-1;++k)
    if((output[k+1]-output[k]>=2||output[k]-output[k+1]>=2)&&output[k]!=-1&&output[k+1]!=-1)
      return 1;
  return 0;
}
void sort(){
  if (check()==1){
    printf("NO");
    return;
  }
  if (n==0){
    printf("YES");
    return;
  }
  int k = find();
  output[n-1]=input[k];
  move(k);
  --n;
  
  sort();
}
int main(){
	scanf("%d",&n); 
	int i;
	for(i=0;i<n;++i){
	  scanf("%d",&input[i]);
	  output[i]=-1;
	}
	sort();
}