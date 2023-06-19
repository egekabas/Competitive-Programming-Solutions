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
inline int getleft(int x, int y){
    return (x&((1<<y)-1));
}
vector<int> g[1000009];
int n;
pii a[1000009];
int vis[1000009];
int dfs(int v){
    vis[v] = 1;
    int ret = 1;
    for(auto u : g[v])
        if(vis[u] == 0)
            ret += dfs(u);
    return ret;
}
int check(int val){
    vector<int> hsh;
    for(int i = 0; i < n; ++i){
        hsh.pb(getleft(a[i].ff, val));
        hsh.pb(getleft(a[i].ss, val));
    }
    sort(hsh.begin(), hsh.end());
    hsh.resize(unique(hsh.begin(), hsh.end())-hsh.begin());
    for(int i = 0; i < n; ++i){
        int v = lower_bound(hsh.begin(), hsh.end(), getleft(a[i].ff, val))-hsh.begin()+1;
        int u = lower_bound(hsh.begin(), hsh.end(), getleft(a[i].ss, val))-hsh.begin()+1;
        g[v].pb(u);
        g[u].pb(v);
    }
    for(int i = 1; i < hsh.size(); ++i)
        if(g[i].size()%2){
            for(int i = 1; i <= hsh.size(); ++i){
                g[i].clear();
                vis[i] = 0;
            }
            return 0;
        }
    if(dfs(1) != hsh.size()){
        for(int i = 1; i <= hsh.size(); ++i){
            g[i].clear();
            vis[i] = 0;
        }
        return 0;
    }
    for(int i = 1; i <= hsh.size(); ++i){
        g[i].clear();
        vis[i] = 0;
    }
    return 1;
}
set<pair<int, pii>> s[1000009];
void print(int val){
    cout << val << '\n';
    vector<int> hsh;
    for(int i = 0; i < n; ++i){
        hsh.pb(getleft(a[i].ff, val));
        hsh.pb(getleft(a[i].ss, val));
    }
    sort(hsh.begin(), hsh.end());
    hsh.resize(unique(hsh.begin(), hsh.end())-hsh.begin());
    for(int i = 0; i < n; ++i){
        int v = lower_bound(hsh.begin(), hsh.end(), getleft(a[i].ff, val))-hsh.begin()+1;
        int u = lower_bound(hsh.begin(), hsh.end(), getleft(a[i].ss, val))-hsh.begin()+1;
        s[v].insert({u, {2*i+1, 2*i+2}});
        s[u].insert({v, {2*i+2, 2*i+1}});
    }
    pair<int, pii> cur = {1, {0, 0}};
    stack<pair<int, pii>> st;

    while(!st.empty() || !s[cur.ff].empty()){
        if(s[cur.ff].empty()){
            cur = st.top();
            cout << cur.ss.ff << ' ' << cur.ss.ss << ' ';            
            st.pop();
        }
        else{
            pair<int, pii> next = *s[cur.ff].begin();
            st.push({cur.ff, {next.ss.ss,next.ss.ff}});
            s[cur.ff].erase(next);
            s[next.ff].erase({cur.ff, {next.ss.ss, next.ss.ff}});
            cur = next;
            cur.ss = {0, 0};
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].ff >> a[i].ss;
        //cout << getleft(a[i].ff, 3) << ' ' << getleft(a[i].ss, 3) << '\n';
    }
    int l = 0, r = 20;
    while(l < r){
        int m = (l+r+1)/2;
        if(check(m))
            l = m;
        else
            r = m-1;
    }
    print(l);
}