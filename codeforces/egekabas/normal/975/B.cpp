#include <bits/stdc++.h>
using namespace std;
long long ar[14];
long long maximum(long long a, long long b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    long long i,k;
    for(i = 0; i < 14; ++i)
        cin >> ar[i];
    long long tmp = 0,count = 0;
    long long maxi = 0;
    for(i = 0; i < 14; ++i){
        if(ar[i] <= 0)
            continue;
        count = 0;
        for(k = 1; k <= 14 ; ++k){
            tmp = ar[(i+k) % 14];
            if(k == 14)
                tmp=0;
            tmp += ar[i]/14;
            if(ar[i] % 14 >= k)
                ++tmp;
            if(tmp % 2 == 0)
                count += tmp;
            //cout << count << endl;
        }
        maxi = maximum(maxi, count);
    }
    cout << maxi;
}