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
map<string, int> mpp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        ++mpp[s];
    }
    for(int i = 1; i < n; ++i){
        cin >> s;
        ++mpp[s];
    }
    for(auto u : mpp){
        if(u.ss%2 == 1){
            cout << u.ff << "\n";
            return 0;
        }
    }
}
