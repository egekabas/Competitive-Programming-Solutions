#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<long long, long long>  pii;
typedef pair<ld, ld>  pld;
long long t;
long long val;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> t;
    while(t--){
        long long result = 0;
        cin >> val;
        long long tmp;
        if(val == 0)
            ++result;
        while(val != 0){
            tmp = val % 2;
            val = val/2;
            if(tmp == 1){
                (result == 0) ? result+=2 : result *= 2;
            }
        }
        cout << result << endl;
    }
}