#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int t, n;
int getval(int x, int y){
    cout << y-x+1 << " " << 1 << " ";
    for(int i = x; i <= y; ++i)
        cout << i << " ";
    cout << 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}
int getans(int x){
    cout << 1 << " " << n-1 << " ";
    cout << x << " ";
    for(int i = 1; i <= n; ++i)
        if(i != x)
            cout << i << " ";
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> t;
    while(t--){
        cin >> n;
        int l = 2; int r = n;
        int look = getans(1);
        while(l < r){
            if( getval(l, (l+r)/2) == look ) r = (l+r)/2;
            else l = (l+r)/2+1;
        }
        int ans = getans(l);
        cout << "-1 " <<  ans << endl;
    }
}