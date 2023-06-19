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
typedef pair<ll, ll>  pii;
typedef pair<ld, ld>  pld;
int n;
int a[200009];
vector<pii> ans;
int con[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        cin >> a[i];
    }
    int root = a[0], cur = a[0];
    int maxi = n;
    con[root] = 1;
    if(maxi == root)
        --maxi;
    for(int i = 1; i < n-1; ++i){
        if(con[a[i]] == 0){
            con[a[i]] = 1;
            ans.pb({cur, a[i]});
            cur = a[i];
            while(con[maxi])
                --maxi;
        }
        else{
            con[maxi] = 1;
            ans.pb({cur, maxi});
            cur = a[i];
            while(con[maxi])
                --maxi;
        }
    }
    ans.pb({cur, maxi});
    cout << root << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
}