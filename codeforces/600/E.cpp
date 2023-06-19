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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
struct node{
    map<ll, ll> col;//Hangi renkten kac tane var
    map<ll, ll> times;//Belli sayidaki renklerin degerleri toplami
};
void add(node &a, node &b){
    ///////////////////////////////////////
    if(a.col.size() > b.col.size())
        swap(a, b);
    //////////////////////////////////////
    
    for(auto u : a.col){
        ll color = u.ff;
        ll colorcnt = u.ss;
        
        b.times[b.col[color]] -= color;
        b.col[color] += colorcnt;
        b.times[b.col[color]] += color;
    }
}


ll n;
ll c[100009];
vector<ll> g[100009];
ll ans[100009];
node nodes[100009];

void dfs(ll v, ll prt){
    nodes[v].col[c[v]] = 1;
    nodes[v].times[1] = c[v];

    for(auto u : g[v]){
        if(u == prt) continue;
        dfs(u, v);
        add(nodes[u], nodes[v]);
    }

    while(1){
        auto it = nodes[v].times.end();
        --it;
        if(it->ss == 0){
            nodes[v].times.erase(it);
            continue;
        }
        else{
            ans[v] = it->ss;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> c[i];
    for(ll i = 0; i < n-1; ++i){
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    dfs(1, 0);
    for(ll i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}