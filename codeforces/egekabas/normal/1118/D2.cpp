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
ll n, m;
ll a[200009];
ll cmp(ll a, ll b){
    return a > b;
}
ll calc(ll days){
    ll ret = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] - i/days <= 0) break;
        else ret += a[i] - i/days;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> m;
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    if(m > sum){
        cout << "-1\n";
        return 0;
    }
    sort(a, a+n, cmp);
    ll l = 1, r = n, mid, piv;
    while(l != r){
        piv = calc(mid = (l+r)/2);
        if(piv == m ){
            cout << mid << endl;
            return 0;
        }
        else if(piv > m){
            r = mid;
        }
        else if(piv < m){
            l = mid+1;
        }
    }
    cout << r << endl;
}