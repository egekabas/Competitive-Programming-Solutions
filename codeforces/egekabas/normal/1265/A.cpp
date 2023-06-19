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
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '?' && i > 0 && s[i] == s[i-1]){
                cout << "-1\n";
                goto END;
            }
            if(s[i] != '?' && i < s.size()-1 && s[i+1] == s[i]){
                cout << "-1\n";
                goto END;
            }
            if(s[i] != '?')
                continue;
            if(i == 0){
                if(s[i+1] != 'a')
                    s[i] = 'a';
                if(s[i+1] != 'c')
                    s[i] = 'c';
                if(s[i+1] != 'b')
                s[i] = 'b';
            }
            if(i == s.size()-1){
                if(s[i-1] != 'a')
                    s[i] = 'a';
                if(s[i-1] != 'c')
                    s[i] = 'c';
                if(s[i-1] != 'b')
                    s[i] = 'b';
                
            }
            if(s[i-1] != 'a' && s[i+1] != 'a')
                s[i] = 'a';
            if(s[i-1] != 'c' && s[i+1] != 'c')
                s[i] = 'c';
            if(s[i-1] != 'b' && s[i+1] != 'b')
                s[i] = 'b';
            
        }
        cout << s << "\n";
        END:;
    }
}