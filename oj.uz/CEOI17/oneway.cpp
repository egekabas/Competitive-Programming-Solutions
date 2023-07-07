#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define MAXN 100009
#define LOGN 21
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;


int n, m;#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define MAXN 100009
#define LOGN 21
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;


int n, m;
vector<pii> originalGraph[MAXN];
int edgeFirst[MAXN];

int noReach;
vector<int> reachFrom[MAXN], reachTo[MAXN];

bool bridgeVisited[MAXN], isBridge[MAXN];
int tin[MAXN], low[MAXN];
int curTime = 0;
void findBridges(int v, int p){
    bridgeVisited[v] = true;
    tin[v] = low[v] = ++curTime;

    for(auto edge : originalGraph[v]){
        int u = edge.ff;
        int edgeIdx = edge.ss;
        if(u == p){
            continue;
        } else if(bridgeVisited[u]){
            low[v] = min(low[v], tin[u]);
        } else{
            findBridges(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] > low[v]){
                isBridge[edgeIdx] = true;
            }
        }
    }
}

int nodeGroup[MAXN];
vector<pii> groupCon[MAXN];
int curGroup = 0;
void findGroup(int v){
    nodeGroup[v] = curGroup;
    for(auto edge : originalGraph[v]){
        int u = edge.ff;
        int edgeIdx = edge.ss;
        
        if(isBridge[edgeIdx]){
            if(nodeGroup[u] && nodeGroup[u] != nodeGroup[v]){
                groupCon[nodeGroup[v]].pb({nodeGroup[u], edgeIdx});
                groupCon[nodeGroup[u]].pb({nodeGroup[v], edgeIdx});
            }
        } else{
            if(!nodeGroup[u]){
                findGroup(u);
            }
        }
    }
}

bool finalVisited[MAXN];
int depth[MAXN];
int prt[MAXN][LOGN];
void createLCA(int v, int p){
    finalVisited[v] = true;
    depth[v] = depth[p]+1;
    prt[v][0] = p;
    for(int i = 1; i < LOGN; ++i){
        prt[v][i] = prt[prt[v][i-1]][i-1];
    }

    for(auto edge : groupCon[v]){
        int u = edge.ff;
        if(u != p){
            createLCA(u, v);
        }
    }
}

int lca(int x, int y){
    if(depth[y] > depth[x]){
        swap(x, y);
    }
    for(int i = LOGN-1; i >= 0; --i){
        if(depth[prt[x][i]] >= depth[y]){
            x = prt[x][i];
        }
    }
    if(x == y){
        return x;
    }
    for(int i = LOGN-1; i >= 0; --i){
        if(prt[x][i] != prt[y][i]){
            x = prt[x][i];
            y = prt[y][i];
        }
    }
    return prt[x][0];
}

char ans[MAXN];

int fromMin[MAXN];
int toMin[MAXN];

void calcAns(int v, int p){
    fromMin[v] = toMin[v] = INF;

    for(auto u : reachFrom[v]){
        fromMin[v] = min(fromMin[v], depth[lca(v, u)]);
    }
    for(auto u : reachTo[v]){
        toMin[v] = min(toMin[v], depth[lca(v, u)]);
    }
    
    for(auto edge : groupCon[v]){
        int u = edge.ff;
        int edgeIdx = edge.ss;
        if(u != p){
            calcAns(u, v);
            fromMin[v] = min(fromMin[v], fromMin[u]);
            toMin[v] = min(toMin[v], toMin[u]);
            
            if(fromMin[u] < depth[u]){
                ans[edgeIdx] = nodeGroup[edgeFirst[edgeIdx]] == u ? 'R' : 'L';
            } else if(toMin[u] < depth[u]){
                ans[edgeIdx] = nodeGroup[edgeFirst[edgeIdx]] == u ? 'L' : 'R';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        originalGraph[x].pb({y, i});
        originalGraph[y].pb({x, i});
        edgeFirst[i] = x;
        ans[i] = 'B';
    }

    for(int i = 1; i <= n; ++i){
        if(!bridgeVisited[i]){
            findBridges(i, 0);
        }
    }

    for(int i = 1; i <= n; ++i){
        if(!nodeGroup[i]){
            ++curGroup;
            findGroup(i);
        }
    }

    cin >> noReach;
    for(int i = 0; i < noReach; ++i){
        int x, y;
        cin >> x >> y;
        reachFrom[nodeGroup[x]].pb(nodeGroup[y]);
        reachTo[nodeGroup[y]].pb(nodeGroup[x]);
    }


    for(int i = 1; i <= curGroup; ++i){
        if(!finalVisited[i]){
            createLCA(i, 0);
            calcAns(i, 0);
        }
    }

    for(int i = 0; i < m; ++i){
        cout << ans[i];
    }
}
vector<pii> originalGraph[MAXN];
int edgeFirst[MAXN];

int noReach;
vector<int> reachFrom[MAXN], reachTo[MAXN];

bool bridgeVisited[MAXN], isBridge[MAXN];
int tin[MAXN], low[MAXN];
int curTime = 0;
void findBridges(int v, int p){
    bridgeVisited[v] = true;
    tin[v] = low[v] = ++curTime;

    for(auto edge : originalGraph[v]){
        int u = edge.ff;
        int edgeIdx = edge.ss;
        if(u == p){
            continue;
        } else if(bridgeVisited[u]){
            low[v] = min(low[v], tin[u]);
        } else{
            findBridges(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] > low[v]){
                isBridge[edgeIdx] = true;
            }
        }
    }
}

int nodeGroup[MAXN];
vector<pii> groupCon[MAXN];
int curGroup = 0;
void findGroup(int v){
    nodeGroup[v] = curGroup;
    for(auto edge : originalGraph[v]){
        int u = edge.ff;
        int edgeIdx = edge.ss;
        
        if(isBridge[edgeIdx]){
            if(nodeGroup[u] && nodeGroup[u] != nodeGroup[v]){
                groupCon[nodeGroup[v]].pb({nodeGroup[u], edgeIdx});
                groupCon[nodeGroup[u]].pb({nodeGroup[v], edgeIdx});
            }
        } else{
            if(!nodeGroup[u]){
                findGroup(u);
            }
        }
    }
}

bool finalVisited[MAXN];
int depth[MAXN];
int prt[MAXN][LOGN];
void createLCA(int v, int p){
    finalVisited[v] = true;
    depth[v] = depth[p]+1;
    prt[v][0] = p;
    for(int i = 1; i < LOGN; ++i){
        prt[v][i] = prt[prt[v][i-1]][i-1];
    }

    for(auto edge : groupCon[v]){
        int u = edge.ff;
        if(u != p){
            createLCA(u, v);
        }
    }
}

int lca(int x, int y){
    if(depth[y] > depth[x]){
        swap(x, y);
    }
    for(int i = LOGN-1; i >= 0; --i){
        if(depth[prt[x][i]] >= depth[y]){
            x = prt[x][i];
        }
    }
    if(x == y){
        return x;
    }
    for(int i = LOGN-1; i >= 0; --i){
        if(prt[x][i] != prt[y][i]){
            x = prt[x][i];
            y = prt[y][i];
        }
    }
    return prt[x][0];
}

char ans[MAXN];

int fromMin[MAXN];
int toMin[MAXN];

void calcAns(int v, int p){
    fromMin[v] = toMin[v] = INF;

    for(auto u : reachFrom[v]){
        fromMin[v] = min(fromMin[v], depth[lca(v, u)]);
    }
    for(auto u : reachTo[v]){
        toMin[v] = min(toMin[v], depth[lca(v, u)]);
    }
    
    for(auto edge : groupCon[v]){
        int u = edge.ff;
        int edgeIdx = edge.ss;
        if(u != p){
            calcAns(u, v);
            fromMin[v] = min(fromMin[v], fromMin[u]);
            toMin[v] = min(toMin[v], toMin[u]);
            
            if(fromMin[u] < depth[u]){
                ans[edgeIdx] = nodeGroup[edgeFirst[edgeIdx]] == u ? 'R' : 'L';
            } else if(toMin[u] < depth[u]){
                ans[edgeIdx] = nodeGroup[edgeFirst[edgeIdx]] == u ? 'L' : 'R';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        originalGraph[x].pb({y, i});
        originalGraph[y].pb({x, i});
        edgeFirst[i] = x;
        ans[i] = 'B';
    }

    for(int i = 1; i <= n; ++i){
        if(!bridgeVisited[i]){
            findBridges(i, 0);
        }
    }

    for(int i = 1; i <= n; ++i){
        if(!nodeGroup[i]){
            ++curGroup;
            findGroup(i);
        }
    }

    cin >> noReach;
    for(int i = 0; i < noReach; ++i){
        int x, y;
        cin >> x >> y;
        reachFrom[nodeGroup[x]].pb(nodeGroup[y]);
        reachTo[nodeGroup[y]].pb(nodeGroup[x]);
    }


    for(int i = 1; i <= curGroup; ++i){
        if(!finalVisited[i]){
            createLCA(i, 0);
            calcAns(i, 0);
        }
    }

    for(int i = 0; i < m; ++i){
        cout << ans[i];
    }
}
