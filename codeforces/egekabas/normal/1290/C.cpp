#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<ull, ull>    pull;
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
ll n, k;
ll st[300009];
vector<ll> g[300009];
ll xxx = 0;
ll prt[300009];
ll col[300009];
ll one[300009];
ll two[300009];
ll must[300009];
vector<ll> child[300009];

ll findprt(ll x){
    if(prt[x] == x)
        return x;
    return prt[x] = findprt(prt[x]);
}
void flip(ll x){
    x = findprt(x);
    swap(one[x], two[x]);
    for(auto u : child[x]){
        if(col[u] == 1)
            col[u] = 2;
        else if(col[u] == 2)
            col[u] = 1;
    }
    if(must[x] == 1)
        must[x] = 2;
    else if(must[x] == 2)
        must[x] = 1;
}
void add1(ll x, ll y){
    ll same = (col[x] == col[y]);
    x = findprt(x);
    y = findprt(y);
    if(x == y)
        return;
    if(child[y].size() > child[x].size())
        swap(x, y);
    if(same)
        flip(y);
    for(auto u : child[y])
        child[x].pb(u);
    child[y].clear();
    one[x] += one[y];
    two[x] += two[y];
    if(must[y])
        must[x] = must[y];
    prt[y] = x;
}
void add2(ll x, ll y){
    ll same = (col[x] == col[y]);
    x = findprt(x);
    y = findprt(y);
    
    if(x == y) return;
    if(child[y].size() > child[x].size())
        swap(x, y);
    if(!same)
        flip(y);
    //cout << one[x] << two[x] << '\n';
    //cout << one[y] << two[y] << '\n';

    for(auto u : child[y])
        child[x].pb(u);
    child[y].clear();
    one[x] += one[y];
    two[x] += two[y];
    if(must[y])
        must[x] = must[y];
    prt[y] = x;

    //cout << one[x] << two[x] << must[x] << '\n';
}
ll getcost(ll x){
    x = findprt(x);
    if(must[x] == 0)
        return min(one[x], two[x]);
    else if(must[x] == 1)
        return one[x];
    else
        return two[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    //freopen("in.txt", "r", stdin);                                                                                             
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;

    for(ll i = 1; i <= n; ++i){
        char c;
        cin >> c;
        st[i] = c-'0';
    }
    for(ll i = 1; i <= k; ++i){
        ll cnt;
        cin >> cnt;
        while(cnt--){
            ll tmp;
            cin >> tmp;
            g[tmp].pb(i);
        }
        prt[i] = i;
        col[i] = 1;
        one[i] = 1;
        child[i].pb(i);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        if(st[i] == 0){
            if(g[i].size() == 2){
                ans -= getcost(g[i][0]);
                if(findprt(g[i][0]) != findprt(g[i][1]))
                    ans -= getcost(g[i][1]);
                add1(g[i][1], g[i][0]);
                ans += getcost(g[i][1]);          
            }
            else if(g[i].size() == 1){
                ans -= getcost(g[i][0]);
                must[findprt(g[i][0])] = col[g[i][0]];
                ans += getcost(g[i][0]);
            }
        }
        else if(st[i] == 1){
            if(g[i].size() == 2){
                ans -= getcost(g[i][0]);
                if(findprt(g[i][0]) != findprt(g[i][1]))
                    ans -= getcost(g[i][1]);
                add2(g[i][1], g[i][0]);
                ans += getcost(g[i][1]);          
            }
            else if(g[i].size() == 1){
                ans -= getcost(g[i][0]);
                if(col[g[i][0]] == 1)
                    must[findprt(g[i][0])] = 2;
                else
                    must[findprt(g[i][0])] = 1;
                ans += getcost(g[i][0]);
            }
        }
        //cout << col[1] << col[2] << col[4] << col[6] << '\n'; 
        cout << ans << '\n';
    }
}