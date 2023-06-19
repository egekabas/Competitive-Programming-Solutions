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
typedef long double ld;
int n, k;
string s;
int lps[1000009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k >> s;
    int len = 0;
    for(int i = 1; i < n ; ++i){
        while(len > 0 && s[len] != s[i])
            len = lps[len-1];
        if(s[len] == s[i])
            ++len;
        lps[i] = len;
    }
    for(int i = 0; i < n ; ++i){
        ll sz = i+1;
        ll q = sz/(sz-lps[i]);
        if(sz % (sz-lps[i]) == 0)
            cout << (q-q%k*(k+1) >= 0);
        else
            cout << (q-q%k*(k+1) > 0);
    }
}