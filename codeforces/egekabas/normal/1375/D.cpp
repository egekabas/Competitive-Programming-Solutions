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
int a[1009];
int used[1009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> ans;
        for(int i = 0; i < 2*n; ++i){
            for(int j = 0; j < n; ++j)
                used[a[j]] = 1;
            int val = -1;
            for(int j = 0; j <= n; ++j){
                if(used[j] == 0 && val == -1)
                    val = j;
                used[j] = 0;
            }
            if(val == n){
                pii mini = {1e9, 1e9};
                for(int j = 0; j < n; ++j)
                    if(a[j] != j){
                        mini = min(mini, {a[j], j});
                    }
                if(mini.ff != 1e9){
                    a[mini.ss] = n;
                    ans.pb(mini.ss);
                }      
            }
            else{
                a[val] = val;
                ans.pb(val);
            }
        }
        
        cout << ans.size() << '\n';
        for(auto u : ans)
            cout << u+1 << ' ';
        cout << '\n';
    }    
}