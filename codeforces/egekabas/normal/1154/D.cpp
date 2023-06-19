#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, b, a;
int s[200009];
int main(){
    cin >> n >> b >> a;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    int charge = a;
    int i;
    for(i = 0; i < n; ++i){
        if(b == 0 && a == 0)
            break;
        if(b == 0){
            --a;
        }
        else if(a == 0){
            --b;
            a += s[i];
        }
        else if(s[i] == 1 && a < charge){
            --b;++a;
        }
        else{
            --a;
        }
    }
    cout << i << endl;
}