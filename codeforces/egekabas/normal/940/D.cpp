#include <stdio.h>
int main(){
    int n;
    scanf("%d\n",&n );
    int a[n+1],b[n+1];
    int i;
    char c[n+1];
    for(i=0;i<n;++i)
        scanf("%d",&a[i] );

    scanf("%s",c );
    for(i=0;i<n;++i){
        if(c[i]=='1')
            b[i]=1;
        else
            b[i]=0;
    }
    int l=-1000000000,r=1000000000,big,k;
    for(i=4;i<n;++i){
        if(b[i]==1){
            if(b[i-1]==1)
                continue;
            else{
                big=-1000000000;
                for(k=i-4;k<=i;++k)
                    if(a[k]>big)
                        big=a[k];
                if(big+1>l)
                    l=big+1;
            }
        }
        if(b[i]==0){
            if(b[i-1]==0)
                continue;
            else{
                big=1000000000;
                for(k=i-4;k<=i;++k){
                    //printf("%d\n",a[k] );
                    if(a[k]<big)
                        big=a[k];
                }
                if(big-1<r)
                    r=big-1;
            }
        }
    }
    if(l>r)
        r=l;
    printf("%d %d",l,r );
}