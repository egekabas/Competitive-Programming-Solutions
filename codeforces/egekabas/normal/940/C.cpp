#include <bits/stdc++.h>
#define max 1000000
using namespace std;
char in[max];
char out[max];
int number[max];

int main(){
    int a,i,n,k,bigger=0;
    scanf("%d %d",&n,&k);
    scanf("%s",in);
    for(i=0;i<n;++i)
        number[i]=in[i];
    sort(number,number+n);
    if(k>n){
        for(i=0;i<k;++i)
            if(i<=n-1)
                out[i]=in[i];
            else
                out[i]=number[0];
        printf("%s\n",out );
        return 0;
    }
    for(i=k-1;i>=0;--i){
        if(bigger==1)
            out[i]=in[i];
        else if(in[i]==number[n-1])
            out[i]=number[0];
        else{
            for(a=0;a<n;++a)
                if(number[a]>in[i])
                    break;
            out[i]=number[a];
            ++bigger;
        }
    }
    out[k]='\0';
    printf("%s\n",out);
}