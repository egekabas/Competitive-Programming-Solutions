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
int a[200009];
int ans[200009];
int vis[200009];
int pl[200009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i <= n; ++i)
            a[i] = ans[i] = vis[i] = pl[i] = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            pl[a[i]] = i;
        }
        int maxi = 1;
        int l = pl[1];
        int r = pl[1];
        vis[1] = 1;
        ans[1] = 1;
        for(int i = 2; i <= n; ++i){
            if(vis[i]){
                if(maxi == i)
                    ans[i] = 1;
                continue;
            }
            if(pl[i] < l){
                for(int j = l-1; j >= pl[i]; --j){
                    maxi = max(maxi, a[j]);
                    vis[a[j]] = 1;
                }
                l = pl[i];
            }
            if(pl[i] > r){
                for(int j = r+1; j <= pl[i]; ++j){
                    maxi = max(maxi, a[j]);
                    vis[a[j]] = 1;    
                }
                r = pl[i];
            }
            if(maxi == i)
                ans[i] = 1;
            
        }
        for(int i = 1; i <= n; ++i)
            cout << ans[i];
        cout << "\n";
    }
}