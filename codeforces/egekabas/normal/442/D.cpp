#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
int dp[1000009];
pii s[1000009];
int par[1000009];
pii goup(pii p, int x){
    if(x > p.ff){
        p.ss = p.ff;
        p.ff = x;
    }
    else if(x > p.ss)
        p.ss = x;
    return p;
}
void func(int v){
    if(v == 0)
        return;
    if(dp[v] == 0){
        dp[v] = 1;
        if(s[par[v]] != goup(s[par[v]], dp[v])){
            s[par[v]] = goup(s[par[v]], dp[v]);
            func(par[v]);
        }
    }
    else{
        int nval;
        if(v == 1)
            nval = s[v].ff;
        else
            nval = max(1 + s[v].ss, s[v].ff);
        if(nval > dp[v]){
            dp[v] = nval;
            if(s[par[v]] != goup(s[par[v]], dp[v])){
                s[par[v]] = goup(s[par[v]], dp[v]);
                func(par[v]);
            }
        }
    }
}
int main(){
    //ifstream cin("a.gir");
    //ofstream cout("a.cik");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 2; i <= n+1; ++i){
        cin >> par[i];
        func(i);
        cout << dp[1] << " ";            
    }

}