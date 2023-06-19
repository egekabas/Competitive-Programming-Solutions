#include <bits/stdc++.h>
using namespace std;
long long n,q;
long long nar[200009];
long long qar[200009];
long long sumn[200009];
int main(){
    cin >> n >> q;
    long long i;
    for(i = 0; i < n; ++i)
        cin >> nar[i];
    for(i = 0; i < q; ++i)
        cin >> qar[i];
    sumn[0] = nar[0];
    for(i = 1; i < n; ++i)
        sumn[i] = sumn[i-1] + nar[i];
    long long count = 0;
    long long  *position;
    for(i = 0; i < q ; ++i){
        count += qar[i];
        position = upper_bound(sumn, sumn + n, count);
        if(*position == count)
            ++position;
        if(position == sumn + n){;
            count = 0;
            position = sumn;
        }
        cout << n - (position - sumn) << endl;
    }
}