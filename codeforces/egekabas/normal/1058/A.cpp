#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;

int n;

int main(){
    int ans = 0;
    int tmp;
    cin >> n;
    while(n--){
        cin >> tmp;
        ans = ans | tmp;
    }
    if(ans == 1)
        cout << "HARD\n";
    else
        cout << "EASY\n";

}