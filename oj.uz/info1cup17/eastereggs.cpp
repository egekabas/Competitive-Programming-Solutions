#include <bits/stdc++.h>
#include "grader.h"
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
/*int query(vector < int > islands){
    cout << "-> ";
    for(auto u : islands)
        cout << u << ' ';
    cout << '\n';
    int ret;
    cin >> ret;
    return ret;
}*/
vector<int> g[600];
int nope[600];
int block[600];
vector<int> sel;
int lft;
void dfs(int v, int prt){
    if(block[v]) return;
    if(lft <= 0) return;
    sel.pb(v);
    if(nope[v] == 0)
        --lft;
    for(auto u : g[v]){
        if(u == prt) continue;
        dfs(u, v);
    }
}
int findEgg(int N, vector<pair<int, int>> bridges){
    sel.clear();
    for(int i = 1; i <= N; ++i){
        nope[i] = block[i] = 0;
        g[i].clear();
    }
    for(auto u : bridges){
        g[u.ff].pb(u.ss);
        g[u.ss].pb(u.ff);
    }
    while(1){
        int clean = 0;
        for(int i = 1; i <= N; ++i)
            if(nope[i] == 0 && block[i] == 0)
                ++clean;
        if(clean == 1){
            for(int i = 1; i <= N; ++i)
                if(nope[i] == 0 && block[i] == 0)
                    return i;
        }
        lft = clean/2;
        sel.clear();
        for(int i = 1; i <= N; ++i)
            if(block[i] == 0){
                dfs(i, 0);
                break;
            }
        if(query(sel)){
            for(int i = 1; i <= N; ++i)
                block[i] = 1;
            for(auto u : sel)
                block[u] = 0;    
        }
        else{
            for(auto u : sel)
                nope[u] = 1;
        }
    }
}
