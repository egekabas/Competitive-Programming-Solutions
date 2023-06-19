#include <stdio.h>
#define MAX 30
int lenght(int array[]){
    int i;
    for(i=0;array[i]!=-1;++i)
        ;
    return i;
}
int main(){
    int array[MAX];
    int a,i,n;
    scanf("%d",&n );
    for(i=0;i<n;++i){
        scanf("%d",&array[i] );
    }
    array[n]=-1;
    int months[37]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,-1};
    int k=0,used=0;
    for(i=0;months[i+n-1]!=-1;++i){
        k=0;
        for(a=0;array[a]!=-1;++a){
            if(array[a]==29 && months[a+i]==28 && used==0){
                ++used;
                ++k;
            }
            else if(array[a]==months[a+i])
                ++k;
            else
                break;
        }
        if(k==lenght(array)){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
}