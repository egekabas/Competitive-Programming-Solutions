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
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    
    
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll i = 0, j = 0;
        ll ans = 0;
        while(i < s.size()){
            if(s[i] == '1'){
                ++i;
                continue;
            }
            for(j = i+1; j < s.size() && s[j] != '1'; ++j)
                ;
            if(i != 0 && j != s.size())
                ans += j-i;
            i = j+1;
        }
        cout << ans << "\n";
    }
}