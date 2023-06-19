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
map<string, int> mpp;
map<int, string> getstr;
vector<int> g[200009];
map<int, int> edgecnt[200009];

int cur = 0;
int in[200009];
int out[200009];
vector<int> vec;
void dfs(int v){
    while(g[v].size()){
        int u = g[v].back();
        g[v].pop_back();
        if(edgecnt[v][u] == 0) continue;
        edgecnt[v][u]--;
        dfs(u);
    }
    vec.pb(v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if(mpp[s.substr(0, 2)] == 0){
            ++cur;
            mpp[s.substr(0, 2)] = cur;
            getstr[cur] = s.substr(0, 2);
        }
        if(mpp[s.substr(1, 2)] == 0){
            ++cur;
            mpp[s.substr(1, 2)] = cur;
            getstr[cur] = s.substr(1, 2);
        }
        int v1 = mpp[s.substr(0, 2)];
        int v2 = mpp[s.substr(1, 2)];
        g[v1].pb(v2);
        edgecnt[v1][v2]++;        
        out[v1]++;
        in[v2]++;
        //cout << v1 << ' ' << v2 << '\n';
    }
    int start = 0;
    int b1 = 0, b2 = 0;
    for(int i = 1; i <= cur; ++i)
        if(out[i] > in[i]){
            if(out[i]-in[i] != 1){
                cout << "NO\n";
                return 0;
            }
            start = i;
            b1++;
        }
        else if(out[i] < in[i]){
            ++b2;
            if(out[i]-in[i] != -1){
                cout << "NO\n";
                return 0;
            }
        }
    if(b1 > 1 || b2 > 1){
        cout << "NO\n";
        return 0;
    }
    if(start == 0) start = 1;
    dfs(start);
    string ans;
    reverse(all(vec));
    for(auto u : vec){
        if(ans.empty()) ans += getstr[u];
        else ans += getstr[u].back();
    }
    if(ans.size() != n+2){
        cout << "NO\n";  
        return 0;
    } 
    cout << "YES\n" << ans << '\n';
}