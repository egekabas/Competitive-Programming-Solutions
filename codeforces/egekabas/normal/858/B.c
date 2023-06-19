#include <stdio.h>
int main(){
	int n,m,number=0;
	scanf("%d %d",&n,&m);
	int a,i,k,result=0;
	int array[m][2];
	for(i=0;i<m;++i){
	  scanf("%d",&array[i][0]);
	  scanf("%d",&array[i][1]);
	}
	for(i=1;i<101;++i){
	  for(a=0;a<m;++a)
	    if((array[a][0]-1)/i+1 != array[a][1])
	      goto NEXT;
	if(result!=(n-1)/i+1){
		result=(n-1)/i+1;
		++number;
	}
    if(number==2)
      break;
	 NEXT:continue;
	}
	if(number==1) printf("%d",result);
	else printf("-1");
}