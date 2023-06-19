#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

int n, h;
pii a[200009];
int simp[200009];

int main(){
    cin >> n >> h;
    int tmp = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i].ff >> a[i].ss;
        simp[i] = a[i].ff - tmp;
        tmp += a[i].ss-a[i].ff;
    }
    int maxi = 0;
    for(int i = 0; i < n; ++i){
        int mes = upper_bound(simp, simp + n, simp[i]+h)-simp;
        --mes;
        if(simp[mes] - simp[i] == h)
            --mes;
        //cout << a[i].ff << " " << a[mes].ss  << " " << h-(simp[mes]-simp[i]) << endl;
        maxi =  max(maxi, a[mes].ss - a[i].ff + h-(simp[mes]-simp[i]));
    }
    cout << maxi;

}