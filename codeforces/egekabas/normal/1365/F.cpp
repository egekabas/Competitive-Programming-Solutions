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
int a[509];
int b[509];
int n;
map<ll, vector<ll>> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        mpp.clear();
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];
        if(n%2){
            if(a[n/2] != b[n/2]){
                cout << "No\n";
                continue;
            }
            for(ll i = n/2; i < n-1; ++i){
                a[i] = a[i+1];
                b[i] = b[i+1];
            }
            --n;
        }
        for(int i = 0; i < n; ++i)
            mpp[a[i]].pb(a[n-1-i]);
        int done = 1;
        for(int i = 0; i < n; ++i){
            int ok = 0;
            for(int j = 0; j < mpp[b[i]].size(); ++j){
                if(mpp[b[i]][j] == b[n-1-i]){
                    ok = 1;
                    mpp[b[i]].erase(mpp[b[i]].begin()+j);
                    break;
                }
            }
            if(ok == 0)
                done = 0;
        }
        if(done)
            cout << "Yes\n";
        else
            cout << "No\n";
    }    
}