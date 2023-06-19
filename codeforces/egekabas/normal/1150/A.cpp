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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    int n, m, r;
    cin >> n >> m >> r;
    int buy = (int)1e9;
    int sel = (int)-1e9;
    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        buy = min(tmp, buy);
    }
    for(int i = 0; i < m; ++i){
        cin >> tmp;
        sel = max(tmp, sel);
    }
    if(sel <= buy){
        cout << r << endl;
        return 0;
    }
    cout << r+(r/buy)*(sel-buy) << endl;
}