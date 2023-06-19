#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m;
unsigned long long dorm[200009];
int main(){
    cin >> n >> m;
    unsigned long long tmp;
    for(unsigned long long i = 0; i < n; ++i){
        cin >> tmp;
        if(i == 0)
            dorm[i] = tmp;
        else
            dorm[i] = dorm[i-1] + tmp;
    }
    unsigned long long fi, se;
    for(unsigned long long i = 0; i < m; ++i){
        cin >> tmp;
        fi = lower_bound(dorm, dorm + n, tmp) - dorm;
        if(fi == 0) se = tmp;
        else se = tmp - dorm[fi-1];

        cout << fi+1 << " " << se << endl;
    }

}