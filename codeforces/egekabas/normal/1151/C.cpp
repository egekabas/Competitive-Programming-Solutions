#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;

ull l, r;
ull mod = 1000000007;

ull calc(ull x){
    ull two = 1;
    ull sum = 0;
    ull hold[2] = {0, 0};
    ull which = 0;
    while(sum < x){
        hold[which] += min(two, x-sum);
        which ^= 1;
        sum += min(two, x-sum);
        two *= 2;
    }
    hold[0] %= mod; hold[1] %= mod;
    return ((hold[0]*hold[0]) + (hold[1]*(hold[1]+1)))%mod;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> l >> r;
    ull val = (calc(r)-calc(l-1)+mod)%mod;
    cout << val << endl;
}