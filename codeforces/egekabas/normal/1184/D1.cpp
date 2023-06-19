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
int n, k, m, t;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> k >> m >> t;
    int pos = k;
    int len = n;
    int t1, t2;
    while(t--){
        cin >> t1 >> t2;
        if(t1 == 1){
            if(t2 <= pos)
                ++pos;
            ++len;
        }
        else{
            if(t2 < pos){
                len -= t2;
                pos -= t2;
            }
            else{
                len -= (len-t2);
            }
        }
        cout << len << " " << pos << endl;
    }
}