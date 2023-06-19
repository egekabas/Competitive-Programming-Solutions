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
string s;
void solve(){
    cin >> s;
    int cnt[3];
    for(cnt[0] = 0; cnt[0] <= 1; ++cnt[0])
        for(cnt[1] = 0; cnt[1] <= 1; ++cnt[1])
            for(cnt[2] = 0; cnt[2] <= 1; ++cnt[2]){
                int curval = 0;
                int ok = 1;
                for(int i = 0; i < s.size(); ++i){
                    if(cnt[s[i]-'A'] == 0)
                        --curval;
                    else
                        ++curval;
                    if(curval < 0) ok = 0;
                }
                if(curval == 0 && ok == 1){
                    cout << "YES\n";
                    return;
                }
            }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}