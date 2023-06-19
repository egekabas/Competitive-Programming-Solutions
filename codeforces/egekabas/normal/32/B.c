#include <stdio.h>
int main(){
	char string[220];
	scanf("%s",string);
	int i;
	for(i=0;string[i]!='\0';++i){
		if(string[i]=='.')
			printf("0");
		if(string[i]=='-')
			if(string[i+1]=='.'){
				printf("1");
				++i;
			}
			else{
				printf("2");
				++i;
			}
	}
}