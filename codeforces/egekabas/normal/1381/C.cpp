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
int n, x, y;
vector<int> g[100009];
int ans[100009];
int a[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        for(int i = 0; i <= n+1; ++i){
            ans[i] = 0;
            g[i].clear();
        }
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            g[a[i]].pb(i);
        }
        int nonused;
        set<pii, greater<pii>> s;
        for(int i = 1; i <= n+1; ++i){
            if(g[i].empty())
                nonused = i;
            else
                s.insert({g[i].size(), i});
        }
        y -= x;
        int no = 0;
        while(x--){
            if(s.empty()){
                no = 1;
                break;
            }
            pii val = *s.begin();
            if(val.ff == 0){
                no = 1;
                break;
            }
            ans[g[val.ss].back()] = val.ss;
            g[val.ss].pop_back();
            s.erase(s.begin());
            s.insert({val.ff-1, val.ss});
        }
        if(no){
            cout << "NO\n";
            continue;
        }
        vector<pii> v;
        for(int i = 1; i <= n+1; ++i){
            if(g[i].size())
                v.pb({g[i].size(), i});
        }
        sort(v.begin(), v.end(), greater<pii>());
        int aft = 1;
        int bef = 0;
        for(int i = 0; i < v.size(); ++i){
            while(aft < v.size() && v[i].ff && y){
                while(g[v[aft].ss].size() && v[i].ff && y){
                    --v[i].ff;
                    --y;
                    ans[g[v[aft].ss].back()] = v[i].ss;
                    g[v[aft].ss].pop_back();
                }
                if(g[v[aft].ss].empty())
                    ++aft;
            }
            while(bef < i && v[i].ff && y){
                while(g[v[bef].ss].size() && v[i].ff && y){
                    --v[i].ff;
                    --y;
                    ans[g[v[bef].ss].back()] = v[i].ss;
                    g[v[bef].ss].pop_back();
                }
                if(g[v[bef].ss].empty())
                    ++bef;
            }
            
        }
        if(y){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            if(ans[i])
                cout << ans[i] << ' ';
            else
                cout << nonused << ' ';
        }
        cout << '\n';
    }    
}