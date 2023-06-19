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
int q, n;
pii a[200009];
set<int> s;
vector<pii> v;
int func1(pii x, pii y){
    return x.ss > y.ss;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> q;
    while(q--){
        cin >> n;
        s.clear(); v.clear();
        for(int i = 0; i <= n; ++i)
            a[i] = {0, 0};
        int t1, t2;
        for(int i = 0; i < n; ++i){
            cin >> t1 >> t2;
            ++a[t1].ff;
            if(t2 == 1)
                ++a[t1].ss;    
        }
        for(int i = 1; i <= n; ++i){
            if(a[i].ff != 0)
                v.pb(a[i]);
            s.insert(i);
        }
        sort(v.begin(), v.end(), func1);
        int ans1 = 0, ans2 = 0;
        for(auto u : v){
            //cout << u.ff << " " << u.ss << endl;
            auto itr = s.upper_bound(u.ff);
            if(itr == s.begin()) continue;
            --itr;
            ans1 += min(*itr, u.ff);
            ans2 += min(*itr, u.ss);
            s.erase(itr);
        }
        cout << ans1 << " " << ans2 << endl << endl;
    }
}