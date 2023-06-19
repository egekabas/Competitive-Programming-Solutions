#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nmax 10005
int same(char a[],char b[]){
    int i,k=0;
    for(i=0;a[i]!='\0';++i)
        if(a[i]!=b[i]){
            ++k;
            break;
        }
    if(k==0 && (a[i]=='\0' && b[i]=='\0'))
        return 1;
    else
        return 0;
}

void input(char array[]){
    int i;
    char c;
    for(i=0;1;++i){
        c=getchar();
        if(c==' ' || c=='\n'){
            array[i]='\0';
            break;
        }
        else{
            if(c=='1'||c=='l' || c=='L')
                array[i]='i';
            else if('A'<=c && c<='Z')
                array[i] = c-'A'+'a';
            else if(c=='0')
                array[i] = 'o';
            else
                array[i]=c;
        }
    }
}
int main(){
    char original[nmax];
    input(original);
    int a,n,i,k;
    scanf("%d",&n);
    char array[nmax][nmax];
    for(i=0;i<=n;++i){
        input(array[i]);
        //printf("%s\n",array[i] );
        if(same(array[i],original)==1){
            printf("No");
            return 0;
        }
    }
    printf("Yes" );
}