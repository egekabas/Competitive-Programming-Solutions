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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
string s;
map<pair<char, int>, int> mp1;
map<char, int> mp2;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> s;
    for(int i = 0; i < s.size(); i += 3){
        char c = s[i];
        int it = (s[i+1]-'0')*10 + (s[i+2]-'0');
        if(mp1[{c, it}] == 1){
            cout << "GRESKA\n";
            return 0;
        }
        mp1[{c, it}] = 1;
        mp2[c]++;
    }
    cout << 13-mp2['P'] << " " << 13-mp2['K'] << " " << 13-mp2['H'] << " " << 13-mp2['T'] << "\n";
}
