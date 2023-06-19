#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long ar[1000];
unsigned long long div3(unsigned long long a){
    unsigned long long i = 0;
    while(1){
        if(a%3 == 0){
            ++i;
            a = a/3;
        }
        else
            return i;
    }
}
unsigned long long div2(unsigned long long a){
    unsigned long long i = 0;
    while(1){
        if(a%2 == 0){
            ++i;
            a = a/2;
        }
        else
            return i;
    }
}

unsigned long long three(unsigned long long a, unsigned long long b){
    unsigned long long x,y;
    x = div3(a);
    y = div3(b);
    return (x > y);
}
unsigned long long two(unsigned long long a, unsigned long long b){
    unsigned long long x,y;
    x = div2(a);
    y = div2(b);
    return (x < y);
}

int main(){
    cin >> n;
    for(unsigned long long i = 0; i < n; ++i)
        cin >> ar[i];
    sort(ar, ar + n, three);
    //for(unsigned long long i = 0; i < n; ++i)
    //    cout << ar[i] << " ";
    //cout << endl;
    unsigned long long begin = 0;
    unsigned long long hold = div2(ar[0]);
    for(unsigned long long i = 0; i < n; ++i){
        if(hold != div3(ar[i])){
            //cout << i << endl;
            sort(ar + begin, ar + i, two);
            begin = i;
            hold = div3(ar[i]);
        }
    }
    sort(ar + begin, ar + n, two);
    for(unsigned long long i = 0; i < n; ++i)
        cout << ar[i] << " ";
}