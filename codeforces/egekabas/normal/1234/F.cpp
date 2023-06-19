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
int a[2000009];
string s;
int n;
vector<int> all;
int ok[2000009];
int dp[2000009];
int check(int a, int b){
    while(a > 0 && b > 0){
        if(a % 2 == 1 && b % 2 == 1)
            return 1;
        a /= 2;
        b /= 2;
    }
    return 0;
}
int size(int a){
    int ret = 0;
    while(a > 0){
        ret += a%2;
        a /= 2;
    }
    return ret;
}
int reverse(int x){
    return (1<<20)-1-x;
}
int mark(int x){
    return (1<<x);
}
int f(int bit){
    if(dp[bit] != -1)
        return dp[bit];
    if(ok[bit] == 1)
        return dp[bit] = size(bit);
    int ret = 0;
    int tmp = bit;
    int cur = 0;
    while(tmp > 0){
        if(tmp % 2)
            ret = max(ret, f(bit-mark(cur)));
        ++cur;
        tmp /= 2;
    }
    
    return dp[bit] = ret;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> s;
    n = s.size();
    for(int i = 0; i < n; ++i)
        a[i] = s[i]-'a';
    for(int i = 0; i <= (1<<20)+1; ++i)
        dp[i] = -1;
    int cur;
    ok[0] = 1;
    for(int i = 0; i < n; ++i){
        cur = 0;
        for(int j = i; j < n; ++j){
            if(check(cur, mark(a[j])))
                break;
            cur += mark(a[j]);
            if(ok[cur] == 0)
                all.pb(cur);
            ok[cur] = 1;
        }
    }
    int ans = 0;
    for(auto u : all){
        ans = max(ans, size(u)+f(reverse(u)));
    }
    cout << ans << "\n";
}