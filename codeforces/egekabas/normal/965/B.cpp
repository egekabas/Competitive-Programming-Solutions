#include <stdio.h>
int val[101][101];
char arr[101][101];
int main(){
    int n,k;
    scanf("%d %d",&n,&k );
    int x,y;
    for(x=0;x<n;++x)
            scanf("%s",arr[x] );
    int count,bo=0;
    for(x=0;x<n;++x)
        for(y=0;y<=n-k;++y){
            for(count=y;count<y+k;++count)
                if(arr[x][count]=='#'){
                    ++bo;
                    break;
                }
            if(bo==1)
                --bo;
            else{
                for(count=y;count<y+k;++count)
                    ++val[x][count];
            }
        }
    for(y=0;y<n;++y)
        for(x=0;x<=n-k;++x){
            for(count=x;count<x+k;++count)
                if(arr[count][y]=='#'){
                    ++bo;
                    break;
                }
            if(bo==1)
                --bo;
            else{
                for(count=x;count<x+k;++count)
                    ++val[count][y];
            }
        }
    int biggest[3];
    biggest[2]=0;
    for(x=0;x<n;++x)
        for(y=0;y<n;++y)
            if(val[x][y]>=biggest[2]){
                biggest[0]=x;
                biggest[1]=y;
                biggest[2]=val[x][y];
            }
    //for(x=0;x<n;++x)
    //    for(y=0;y<n;++y)
    //        printf("%d\n",val[x][y] );
    printf("%d %d",biggest[0]+1,biggest[1]+1 );
}