#include <stdio.h>
int main(){
    long long n,k,A,B;
    scanf("%lld %lld %lld %lld",&n,&k,&A,&B);
    long long moves = 0;
    if(k==1){
        printf("%lld\n",(n-1)*A);
        return 0;
    }
    while(n!=1){
        if(n%k == 0){
            moves += ((n-n/k)*A > B) ? B : (n-n/k)*A ;
            n /= k;
        }
        else{
            moves += (n%k)*A;
            n=n-n%k;
            if(n==0){
                n=1;
                moves -= A;
            }
        }
    }
    printf("%lld",moves);
}
// 19 3 4 2