#include <stdio.h>
#define MAX 1000009
int main(){
    int total=0;
    char string[MAX];
    scanf("%s",string);
    int i,count=0;
    for(i=0;string[i]!='\0';++i){
        if(string[i]=='(')
            ++count;
        else if(string[i]==')')
            if(count>0){
                --count;
                total += 2;
            }
    }
    printf("%d\n",total );
}