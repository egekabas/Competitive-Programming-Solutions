#include <bits/stdc++.h>
int main(){
    int i,k,n,s,p;
    scanf("%d %d %d %d",&k,&n,&s,&p );
    i = ((n+s-1)/s*k+p-1)/p;
    printf("%d\n",i );
}