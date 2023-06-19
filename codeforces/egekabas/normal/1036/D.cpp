#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[300009];
long long b[300009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(long long i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for(long long i = 0; i < m; ++i)
        cin >> b[i];
    long long suma = a[0];
    long long sumb = b[0];
    long long x = 0;
    long long y = 0;
    long long tmp1 = 0;
    while(1){
        if(x >= n || y >= m){
            if(suma == 0 && sumb == 0)
                break;
            else{
                cout << "-1\n" ;
                return 0;
            }
        }
        if(suma > sumb){
            ++y;
            sumb += b[y];
        }
        else if(suma < sumb){
            ++tmp1;
            ++x;
            suma += a[x];
        }
        else if(suma == sumb){
            ++x;++y;
            suma=a[x];sumb=b[y];
        }
    }
    cout << n-tmp1;
}