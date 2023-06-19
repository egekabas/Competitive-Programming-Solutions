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
int l, q;
string s;
const int n7 = 2187;
const int n13 = 1594323;
int val[1000009][2];
int av[n7][(1<<7)];
int child[n13][2];
int ans[1000009];
int dp[n13];
int a, b;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> l >> q;
    cin >> s;
    a = min(l, 7);
    b = l-a;
    for(int i = 0; i < q; ++i){
        string t;
        cin >> t;
        for(int j = 0; j < a; ++j){
            val[i][0] *= 3;
            if(t[j] != '?')
                val[i][0] += t[j]-'0';
            else
                val[i][0] += 2;
        }
        for(int j = a; j < l; ++j){
            val[i][1] *= 3;
            if(t[j] != '?')
                val[i][1] += t[j]-'0';
            else
                val[i][1] += 2;
        }
    }
    for(int i = 0; i < n7; ++i)
        for(int j = 0; j < (1<<7); ++j){
            av[i][j] = 1;
            int v1 = i, v2 = j;
            for(int k = 0; k < 7; ++k){
                if(v1%3 != 2 && v1%3 != v2%2)
                    av[i][j] = 0;
                v1 /= 3;
                v2 /= 2;
            }
        }
    for(int i = 0; i < n13; ++i){
        child[i][0] = child[i][1] = -1;
        int cur = 1;
        int val = i;
        for(int j = 0; j < 13; ++j){
            if(val%3 == 2){
                child[i][0] = i-cur;
                child[i][1] = i-2*cur;
                break;
            }
            cur *= 3;
            val /= 3;
        }
    }
    for(int i = 0; i < n13; ++i){
        
    }
    for(int i = 0; i < (1<<a); ++i){
        for(int j = 0; j < n13; ++j){
            if(child[j][0] == -1){
                dp[j] = 0;
                int val = j;
                int ret = 0;
                for(int k = 0; val > 0; ++k){
                    ret += (1<<k)*(val%3 > 0);
                    val /= 3;
                }
                if(ret + (1<<b)*i < s.size())
                    dp[j] = s[ret+(1<<b)*i]-'0';
            }
            else
                dp[j] = dp[child[j][0]]+dp[child[j][1]];
        }
        for(int j = 0; j < q; ++j){
            if(av[val[j][0]][i] == 0) continue;
            //cout << j << ' ' << i << '\n';
            ans[j] += dp[val[j][1]];
        }
    }
    for(int i = 0; i < q; ++i){
        //cout << tr[val[i][0]] << ' ';
        cout << ans[i] << '\n';
    
    }
} 
