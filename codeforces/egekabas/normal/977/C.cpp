#include <bits/stdc++.h>
using namespace std;
long long n,k,x;
int main(){
    cin >> n >> k;
    long long ar[n+1];
    for(long long i = 0; i < n; ++i)
        cin >> ar[i];
    sort(ar, ar+n);
    if(k == 0){
        if(ar[0] >= 2)
            cout << 1;
        else
            cout << -1;
    }
    else if(ar[k] == ar[k-1])
        cout << -1;
    else if(ar[k-1] >= 1 && ar[k-1] <= 1000000000)
        cout << ar[k-1];
    else if(ar[k]-1 >= 1 && ar[k]-1 <= 1000000000)
        cout << ar[k]-1;
    else
        cout << -1;

}