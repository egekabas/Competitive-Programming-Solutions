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
string s[20];
int precalc[20][30];
int dp[100009];
int n;
int f(int bit){
    if(bit == 0) return 0;
    if(dp[bit] != 0)
        return dp[bit];
    int totlet = 0;
    int cnt = __builtin_popcount(bit);
    for(int i = 0; i < n; ++i)
        if((1<<i)&bit)
            totlet += s[i].size();
    vector<int> com(30, 1e9);
    for(int i = 0; i < n; ++i)
        if((1<<i)&bit)
            for(int j = 0; j <= 'z'-'a'; ++j)
                com[j] = min(com[j], precalc[i][j]);
    int totcom = 0;
    for(int j = 0; j <= 'z'-'a'; ++j)
        totcom += com[j];
    dp[bit] = totlet -= totcom*(cnt-1);
    for(int nbit = ((bit-1)&bit); nbit > 0; nbit = ((nbit-1)&bit)){
        dp[bit] = min(dp[bit], f(nbit)+f(bit-nbit)-totcom);
    }
    //cout << bit << ' ' << dp[bit] << '\n';
    return dp[bit];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        for(auto u : s[i])
            precalc[i][u-'a']++;
    }
    cout << f((1<<n)-1)+1 << '\n';
}
