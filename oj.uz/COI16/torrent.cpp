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
int n, a, b;
vector<int> g[300009];
bool oth[300009];
 
void dfs1(int v, int p){
    if(oth[v]) return;
    for(auto u : g[v]){
        if(u == p)
            continue;
        dfs1(u, v);
        if(oth[u]){
            oth[v] = 1;
            return;
        }
    }
}
int dp[300009];
void calc(int v, int p){
    vector<int> vec;
    for(auto u : g[v]){
        if(u == p)
            continue;
        calc(u, v);
        vec.pb(dp[u]);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for(int i = 0; i < vec.size(); ++i)
        dp[v] = max(dp[v], i+1+vec[i]);
}
int dis[300009];
priority_queue<pii> pq;
 
int check(int time){
    for(int i = 1; i <= n; ++i)
        dis[i] = 1e9;
    while(!pq.empty())pq.pop();
    pq.push({0, a});
    pq.push({0, b});
    dis[a] = dis[b] = 0;
    while(!pq.empty()){
        int v = pq.top().ss;
        int curdis = -pq.top().ff;
        pq.pop();
        
        if(curdis > dis[v])
            continue;
        if(curdis > time)
            return 0;
        vector<int> vec;
        for(auto u : g[v]){
            if(oth[u])
                continue;
            vec.pb(dp[u]);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int cur = 2;
        int ret = 1;
        for(auto u : vec){
            if(curdis + u + cur == time+1){
                ret = cur;
            }
            else if(curdis + u + cur > time)
                return 0;
            ++cur;
        }
        for(auto u : g[v])
            if(oth[u] && dis[u] > curdis+ret){
                dis[u] = curdis+ret;
                pq.push({-dis[u], u});
            }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> a >> b;
    for(int i = 1; i < n; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].pb(t2);
        g[t2].pb(t1);
    }
    oth[b] = 1;
    dfs1(a, -1);
 
    for(int i = 1; i <= n; ++i){
        if(oth[i] == 0) continue;
        for(auto u : g[i]){
            if(oth[u] == 0)
                calc(u, i);
        }
    }
    int l = 0, r = 300009;
 
    while(l < r){
        int m = l+(r-l)/2;
        if(check(m))
            r = m;
        else
            l = m+1;
    }
    cout << l << "\n";
}
