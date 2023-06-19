#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int n, q;
int p[100009];
vector<pii> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    reverse(p, p+n);
    ans.pb({0, 0});
    while(1){
        int cur = ans.back().ff;
        int nxt = 0;
        for(int j = 0; j < n; ++j){
            nxt = max(nxt, cur - cur%p[j]+p[j]-1);
        }
        if(nxt <= cur)
            break;
        ans.pb({nxt, ans.back().ss+1});
        if(nxt > 1e7)
            break;
    }
    while(q--){
        int x;
        cin >> x;
        int id = lower_bound(all(ans), mp(x, -1))-ans.begin();
        if(id == ans.size())
            cout << "oo\n";
        else
            cout << ans[id].ss << '\n';
    }
    
}
