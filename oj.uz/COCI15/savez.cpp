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
ll n;
ll lps[100009];
map<string, ll> dp;
void func(string s){
    int len = 0;
    int i = 1;
    while(i < s.size()){
        if(s[i] == s[len]){
            ++len;
            lps[i] = len;
            ++i;
        }
        else if(len > 0)
            len = lps[len-1];
        else{
            lps[i] = 0;
            ++i;
        }
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        string s;
        cin >> s;
        func(s);
        ll cur = 1+dp[s];
        ll len = lps[s.size()-1];
        while(len > 0){
            cur = max(cur, 1+dp[s.substr(0, len)]);
            len = lps[len-1];
        }
        dp[s] = cur;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
