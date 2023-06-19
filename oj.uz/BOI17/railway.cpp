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
int n, m, k;
vector<pii> g[100009];
vector<int> s[100009];
 
int totcnt[100009];
struct node{
    map<int, int> cnt;
    int all = 0;
};
node nd[100009];
 
void merge(node &a, node &b){
    if(b.cnt.size() > a.cnt.size())
        swap(a, b);
    for(auto u : b.cnt){
        assert(u.ss);
        a.cnt[u.ff] += u.ss;
        if(a.cnt[u.ff] == totcnt[u.ff])
            a.all++;
    }
}
vector<int> ans;
void dfs(int v, int prt){
    for(auto u : s[v])
        nd[v].cnt[u]++;
    for(auto u : nd[v].cnt)
        if(u.ss == totcnt[u.ff])
            nd[v].all++;
    for(auto u : g[v]){
        if(u.ss == prt) continue;
        dfs(u.ff, u.ss);
        merge(nd[v], nd[u.ff]);
    }
    //cout << v << ' ' << prt << ' ' << nd[v].cnt.size() << '\n';
    if((int)nd[v].cnt.size()-nd[v].all >= k && prt)
        ans.pb(prt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m >> k;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    for(int i = 0; i < m; ++i){
        int num;
        cin >> num;
        totcnt[i] = num;
        while(num--){
            int tmp;
            cin >> tmp;
            s[tmp].pb(i);
        }
    }
    dfs(1, 0);
    cout << ans.size() << '\n';
    sort(all(ans));
    for(auto u : ans)
        cout << u << ' ';
}
