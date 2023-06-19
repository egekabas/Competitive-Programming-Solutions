#include <bits/stdc++.h>
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        string s1, s2;
        cin >> n;
        cin >> s1 >> s2;
        vector<int> ans;
        int rev = 0;
        for(int i = 0; i < n; ++i){
            char c;
            if(rev){
                if(s1[n-(i+1)/2] == '1')
                    c = '0';
                else
                    c = '1';
            }
            else
                c = s1[i/2];
            if(c == s2[n-1-i]){
                ans.pb(1);
            }
            ans.pb(n-i);
            rev ^= 1;
        }
        cout << ans.size();
        for(auto u : ans)
            cout << ' ' << u;
        cout << '\n';
    }
}