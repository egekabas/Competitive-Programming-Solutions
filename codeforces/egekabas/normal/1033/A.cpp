#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;

int n, a1, a2, b1, b2, c1, c2;

int main(){
    cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    int tmp1, tmp2;
    if(b1 < a1)
        tmp1 = 0;
    else
        tmp1 = 1;
    if(c1 < a1)
        tmp2 = 0;
    else
        tmp2 = 1;

    int tmp3, tmp4;
    if(b2 < a2)
        tmp3 = 0;
    else
        tmp3 = 1;
    if(c2 < a2)
        tmp4 = 0;
    else
        tmp4 = 1;
    if(tmp1 == tmp2 && tmp3 == tmp4 )
        cout << "YES\n";
    else
        cout << "NO\n";
}