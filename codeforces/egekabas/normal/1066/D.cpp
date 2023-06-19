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

int a[200009];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int tmp = 0;
    int i;
    for(i = n-1; i >= 0; --i){
        tmp += a[i];
        if(tmp > k){
            --m;
            tmp = a[i];
            if(m == 0){
                break;
            }
        }
    }
    cout << (n-i-1) << endl;
}