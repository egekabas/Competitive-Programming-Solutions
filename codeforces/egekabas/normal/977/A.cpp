#include <bits/stdc++.h>
using namespace std;
long long n,k;
void subs(long long *a){
    if(*a % 10 != 0)
        --(*a);
    else
        (*a) = (*a)/10;
}
int main(){
    cin >> n >> k;
    for(long long i = 0; i < k; ++i)
        subs(&n);
    cout << n;
}