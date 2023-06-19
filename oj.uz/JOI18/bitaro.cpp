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
int n, m, q;
int sq = 250;
vector<int> inc[200009];
vector<pii> far[200009];
int dist[200009];
int nono[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> m >> q;
    while(m--){
        int x, y;
        cin >> x >> y;
        inc[y].pb(x);
    }
    for(int i = 1; i <= n; ++i)
        dist[i] = -1;
    for(int i = 1; i <= n; ++i){
        far[i].pb({0, i});
        for(auto u1 : inc[i])
            for(auto u2 : far[u1])
                dist[u2.ss] = max(dist[u2.ss], u2.ff+1);
        for(auto u1 : inc[i])
            for(auto u2 : far[u1])
                if(dist[u2.ss] != -1){
                    far[i].pb({dist[u2.ss], u2.ss});
                    dist[u2.ss] = -1;
                }
        sort(far[i].begin(), far[i].end(), greater<pll>());
        while((int)far[i].size() > sq)
            far[i].pop_back();
    }
    while(q--){
        int root, k;
        cin >> root >> k;
        vector<int> busy(k);
        for(int i = 0; i < k; ++i){
            cin >> busy[i];
            nono[busy[i]] = 1;
        }
        if(k < sq){
            int neg = 1;
            for(auto u : far[root])
                if(nono[u.ss] == 0){
                    neg = 0;
                    cout << u.ff << "\n";
                    break;
                }
            if(neg)
                cout << "-1\n";
        }
        else{
            for(int i = 1; i < root; ++i)
                dist[i] = -1;
            dist[root] = 0;
            int ans = -1;
            for(int i = root; i >= 1; --i){
                if(dist[i] == -1)
                    continue;
                if(dist[i] > ans && nono[i] == 0)
                    ans = dist[i];
                for(auto u : inc[i])
                    dist[u] = max(dist[u], dist[i]+1);
            }
            cout << ans << "\n";
        }
        for(int i = 0; i < k; ++i){
            nono[busy[i]] = 0;
        }
    }
}
