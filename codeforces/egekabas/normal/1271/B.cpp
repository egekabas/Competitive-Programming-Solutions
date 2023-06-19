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
int wcnt;
int bcnt;
int n;
char a[209];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int beg = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 'W')
            ++wcnt;
        else
            ++bcnt;        
    }
    vector<int> ans;
    if(bcnt%2 && wcnt%2){
        cout << "-1\n";
        return 0;
    }
    if(bcnt % 2 == 0){
        for(int i = 0;i < n; ++i){
            if(a[i] == 'W')
                a[i] = 'B';
            else
                a[i] = 'W';
            
        }
    }
    if(1){
        for(int i = 0; i < n-1; ++i){
            if(a[i] == 'B' && a[i+1] == 'B'){
                ans.pb(i);
                a[i] = a[i+1] = 'W';
            }
            else if(a[i] == 'B' && a[i+1] == 'W'){
                ans.pb(i);
                swap(a[i], a[i+1]);
            }
        }
        for(int i = 0; i < n-1; ++i){
            if(a[i] == 'W' && a[i+1] == 'W'){
                ans.pb(i);
                a[i] = a[i+1] = 'B';    
            }
        }
        cout << ans.size() << "\n";
        for(auto u : ans)
            cout << u+1 << " ";
    }
}