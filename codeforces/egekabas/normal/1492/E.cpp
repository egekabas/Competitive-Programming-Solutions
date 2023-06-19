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
int n, m;
vector<vector<int>> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    int cur = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
        
    
    pii maxi = {0, 0};
    for(int i = 1; i < n; ++i){
        int dif = 0;
        for(int j = 0; j < m; ++j)
            if(a[i][j] != a[0][j])
                ++dif;
        maxi = max(maxi, {dif, i});
    }
    if(maxi.ff <= 2){
        cout << "Yes\n";
        for(auto u : a[0])
            cout << u << ' ';
        return 0;
    }
    if(maxi.ff > 4){
        cout << "No\n";
        return 0;
    }
    int idx = maxi.ss;
    vector<int> ans = a[0];
    vector<int> dif;
    for(int j = 0; j < m; ++j)
        if(a[0][j] != a[idx][j])
            dif.pb(j);
    if(dif.size() == 4){
        for(int bit = 0; bit < (1<<(int)dif.size()); ++bit){
            if(__builtin_popcount(bit) != 2) continue;
            
            for(int i = 0; i < dif.size(); ++i){
                if((1<<i)&bit)
                    ans[dif[i]] = a[0][dif[i]];
                else
                    ans[dif[i]] = a[idx][dif[i]];                
            }
            int ok = 1;
            for(int i = 0; i < n; ++i){
                int curdif = 0;
                for(int j = 0; j < m; ++j)
                    curdif += (ans[j] != a[i][j]);
                if(curdif > 2){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                cout << "Yes\n";
                for(auto u : ans)
                    cout << u << ' ';
                return 0;
            }
        }
    }
    else{
        for(int sp = 0; sp < 3; ++sp)
            for(int bit = 0; bit < 4; ++bit){
                if(__builtin_popcount(bit) != 1) continue;
                int tmpbit = bit;
                for(int i = 0; i < dif.size(); ++i){
                    if(i == sp) continue;
                    if(tmpbit%2)
                        ans[dif[i]] = a[0][dif[i]];
                    else
                        ans[dif[i]] = a[idx][dif[i]];
                    tmpbit /= 2;
                }
                ans[dif[sp]] = -1;
                int ok = 1;
                for(int i = 0; i < n; ++i){
                    int curdif = 0;
                    for(int j = 0; j < m; ++j){
                        if(ans[j] == -1) {
                            ++curdif;
                            continue;
                        }
                        curdif += (ans[j] != a[i][j]);
                    }
                    if(curdif > 2 && ans[dif[sp]] == -1){
                        ans[dif[sp]] = a[i][dif[sp]];
                        --curdif;
                    }
                    if(curdif > 2){
                        ok = 0;
                        break;
                    }
                }

                if(ok){
                    if(ans[dif[sp]] == -1)
                        ans[dif[sp]] = 1;
                    cout << "Yes\n";
                    for(auto u : ans)
                        cout << u << ' ';
                    return 0;
                }

            }
    }
    cout << "No\n";

}