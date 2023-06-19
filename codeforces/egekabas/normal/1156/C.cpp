#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, z;
int a[200009];
int calc(int mid){
    int count = 0;
    int l, r;
    for(l = 0, r = mid;l < mid; ++l){
        while(a[r]-a[l] < z && r < n) ++r;
        if(r == n) break;
        ++count;
        ++r;
    }
    return count;
}
int main() {


#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> z;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int l = 0, r = n-1;
    while(l < r){
        if(r-l < 3){
            int idx = -1; int maxi = -1;
            for(int i = l; i <= r; ++i){
                if(calc(i) >= maxi){
                    maxi = calc(i);
                    idx = i;
                }
            }
            r = l = idx;
            break;
        }
        int m1 = l + (r-l)/3;
        int v1 = calc(m1);

        int m2 = r - (r-l)/3;
        int v2 = calc(m2);

        if(v1 > v2)
            r = m2;
        else
            l = m1;
    }
    cout << calc(l) << endl;
}