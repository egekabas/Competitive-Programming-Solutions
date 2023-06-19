#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
int ans[100009];

int q(int x){
    cout << "? " << x << endl;
    int val;
    cin >> val;
    return val;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        ans[i] = 0;
    for(int i = 1; i <= n; ++i){
        if(ans[i]) continue;
        while(1){
            int cur = q(i);
            if(cur == i)
                break;
        }
        vector<int> vec = {i};
        while(1){
            int cur = q(i);
            if(cur == i)
                break;
            else
                vec.pb(cur);
        }
        for(int i = 0; i < vec.size(); ++i)
            ans[vec[i]] = vec[(i+1)%vec.size()];
    }
    cout << "! ";
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}