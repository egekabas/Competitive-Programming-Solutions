#include <stdio.h>
int n;
int main(){
    scanf("%d",&n);
    if(n%2==0)
        printf("white\n1 2");
    if(n%2==1)
        printf("black");
}