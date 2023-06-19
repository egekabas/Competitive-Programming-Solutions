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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(i+4 < n && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'
            && s[i+3] == 'n' && s[i+4] == 'e'){
                ans.pb(i+2);
                i = i+4;
            }
            else if(i+2 < n && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'){
                ans.pb(i+1);
                i += 2;
            }
            else if(i+2 < n && s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e'){
                ans.pb(i+1);
                i += 2;
            }
        }
        cout << ans.size() << "\n";
        for(auto u : ans)
            cout << u+1 << " ";
        cout << "\n";
    }
}