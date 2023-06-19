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
int n, m, rev;
int cur[1009];
void solve(){
    cin >> n >> m;
    
    pii use = {-1, -1};
    for(int i = 0; i <= n; ++i){
        int curans = i;
        int needother = max(0, (n+2)/2-(n-i));
        int extra = m-(m+2)/2;
        if(needother == 0)
            curans += m;
        else{
            curans += min(m, i*extra/needother);
        }
        use = max(use, {curans, i});    
        //cout << i << ' ' <<  << '\n';
    }
    for(int j = 0; j < m; ++j)
        cur[j] = 0;
    cout << use.ff << '\n';
    int left = use.ss;
    int need = max(0, (n+2)/2-(n-left));
    int col = m;
    if(need)
        col = min(m, left*(m-(m+2)/2)/need);
    for(int i = 0; i < n; ++i){
        if(left){
            --left;
            int extra = m-(m+2)/2;
            set<pii> s;
            for(int j = 0; j < col; ++j){
                s.insert({cur[j], j});
            }
            set<int> use;
            while(extra--){
                if(s.size()){
                    use.insert(s.begin()->ss);
                    s.erase(s.begin());
                }
            }
            for(int j = 0; j < m; ++j){
                if(use.size() && j == *use.begin()){
                    ++cur[j];
                    use.erase(use.begin());
                    cout << '-';
                }
                else
                    cout << '+';
            }
        }
        else
            for(int j = 0; j < m; ++j)
                cout << '-';
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    int t;
    cin >> t;
    while(t--)
        solve();
    
}
