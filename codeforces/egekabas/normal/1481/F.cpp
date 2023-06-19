#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
int n, x;
int swp = 0;
vector<int> g[100009];
vector<int> d[100009];
int needed[100009];
int nd;
void dfs(int v, int depth){
    nd = max(nd, depth);
    d[depth].pb(v);
    for(auto u : g[v])
        dfs(u, depth+1);
}
int dp[650][50009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> x;
    if(x > n/2){
        x = n-x;
        swp = 1;
    }
    for(int i = 2; i <= n; ++i){
        int p;
        cin >> p;
        g[p].pb(i);
    }
    dfs(1, 1);
    map<int, int> mpp;
    for(int i = 1; i <= nd; ++i)
        mpp[d[i].size()]++;
    vector<pii> v;
    for(auto u : mpp)
        v.pb(u);
    for(int i = 0; i <= v.size(); ++i)
        for(int j = 0; j <= x; ++j)
            dp[i][j] = -1;
    dp[v.size()][0] = 0;
    for(int i = v.size()-1; i >= 0; --i)
        for(int j = 0; j <= x; ++j){
            if(dp[i+1][j] != -1)
                dp[i][j] = 0;
            else{
                if(j-v[i].ff >= 0 && dp[i][j-v[i].ff] != -1){
                    dp[i][j] = dp[i][j-v[i].ff]+1;
                    if(dp[i][j] > v[i].ss)
                        dp[i][j] = -1;
                } 
                else
                    dp[i][j] = -1;
            }
        }
    string s;
    s.resize(n);
    if(dp[0][x] != -1){
        cout << nd << '\n';
        int curval = x;
        for(int i = 0; i < v.size(); ++i){
            needed[v[i].ff] = dp[i][curval];
            curval -= dp[i][curval]*v[i].ff;
        }
        for(int i = 1; i <= nd; ++i){
            if(needed[d[i].size()]){
                needed[d[i].size()]--;
                for(auto u : d[i])
                    s[u-1] = 'a';
            }
            else
                for(auto u : d[i])
                    s[u-1] = 'b';
            }
        if(swp)
            for(auto &u : s){
                if(u == 'a') u = 'b';
                else if(u == 'b') u = 'a';
            }
    }
    else{
        cout << nd+1 << '\n';
        if(swp)
            x = n-x;
        int aneed = x;
        int bneed = n-x;
        int mark;
        for(int i = 1; i <= nd; ++i){
            if(d[i].size() <= aneed){
                aneed -= d[i].size();
                for(auto u : d[i])
                    s[u-1] = 'a';
            }
            else if(d[i].size() <= bneed){
                bneed -= d[i].size();
                for(auto u : d[i])
                    s[u-1] = 'b';
            }
            else
                mark = i;
        }
        int big = 0;
        if(bneed > aneed)
            big = 1;
        for(auto u : d[mark]){
            char cur;
            if(g[u].empty()){
                if(big){
                    if(aneed){
                        --aneed;
                        cur = 'a';
                    }
                    else{
                        --bneed;
                        cur = 'b';
                    }
                }
                else{
                    if(bneed){
                        --bneed;
                        cur = 'b';
                    }
                    else{
                        --aneed;
                        cur = 'a';
                    }
                }
            }
            else{
                if(big){
                    --bneed;
                    cur = 'b';
                }
                else{
                    --aneed;
                    cur = 'a';
                }
            }
            s[u-1] = cur;
        }
    }
    cout << s << '\n';
}