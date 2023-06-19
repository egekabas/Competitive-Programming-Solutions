#include <stdio.h>
int main(){
	char string [300];
	scanf("%s",string);
	char result[300];
	int i,y=1;
	int last=0;
	for(i=0;string[i]!='\0';++i){
	  if(string[i]!='@')
	    ++y;
	  else if(y<2){
	    printf("No solution");
	    return 0;
	  }
	  else
	    y=0;
	}
	for(i=0;string[i]!='\0';++i){
	  if(string[i]=='@')
	    last=i;
	}
	if(i<3||string[i-1] == '@'||last==0){
	    printf("No solution");
	    return 0;
	}
	
	int k=0; 
	for(i=0;string[i]!='\0';++i){
	  putchar(string[i]);
	  if(string[i-1]=='@' && i-1 != last){
	    putchar(',');
	  }
	}
}