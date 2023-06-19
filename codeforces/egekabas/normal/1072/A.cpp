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

int w, h, k;

int main(){
    cin >> w >> h >> k;
    int ans = 0;
    while(w >= 1 && h >= 1 && k > 0){
        ans += 2*w + 2*h - 4;
        //cout << w << " " << h  << " " << k << endl;
        w = w - 4;
        h = h - 4;
        k = k-1;
    }
    cout << ans << endl;
}