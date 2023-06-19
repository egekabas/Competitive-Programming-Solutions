#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef unsigned long long   ull;
typedef long double ld;
typedef pair<int, int>    pll;
typedef pair<ull, ull>    pull;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;

    while(t--){
        cin >> s1 >> s2;
        for(ll i = 0; i < s2.size(); ++i) {
            vector<ll> cur(s2.size(), -1);
            vector<ll> nxt(s2.size(), -1);
            cur[0] = i;
            for(ll j = 0; j < s1.size(); ++j){
                for(ll k = 0; k <= i; ++k){
                    if(cur[k] == -1)
                        continue;
                    if(k == i && cur[k] == s2.size()){
                        cout << "YES\n";
                        goto END;
                    }
                    nxt[k] = max(nxt[k], cur[k]);
                    if(cur[k] < s2.size() && s1[j] == s2[cur[k]])
                        nxt[k] = max(nxt[k], cur[k]+1);
                    if(k < i && s1[j] == s2[k])
                        nxt[k+1] = max(nxt[k+1], cur[k]);
                }
                cur = nxt;
            }
            if(cur[i] == s2.size()){
                cout << "YES\n";
                goto END;
            }
        }       
        cout << "NO\n";
        END:;
    }
}