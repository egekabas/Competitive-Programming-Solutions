#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    cout << "YES\n";
    for(long long i = l; i < r; i = i+2){
        cout << i << " " << i+1 << endl;
    }
}