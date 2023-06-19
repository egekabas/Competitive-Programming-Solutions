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
int n, m;
vector<int> a;
set<pii> s;
int pos(int k){
    int mini = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < mini && mini-a[i] > k)
            return 0;
        else if(a[i] > mini && m-a[i]+mini > k)
            mini = a[i];
    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        a.pb(tmp);
    }
    int l = 0;
    int r = 300009;
    while(l < r){
        int m = (l+r)/2;
        int che = pos(m);
        if(che == 1) r = m;
        else l = m+1;
    }
    cout << l << endl;
}