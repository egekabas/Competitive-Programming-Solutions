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
const ll mod = 998244353;
ll a[200009];
ll b[200009];
map<ll, ll> mpp;
ll n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;

    ll mini = 1e18;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mpp[a[i]] = i;
        mini = min(a[i], mini);
    }
    for(ll i = 1; i <= m; ++i){
        cin >> b[i];
        if(mpp[b[i]] == 0){
            cout << "0\n";
            return 0;
        }
    }
    if(mini != b[1]){
        cout << "0\n";
        return 0;
    }
    ll ans = 1;
    for(ll i = 2; i <= m; ++i){
        if(mpp[b[i]] < mpp[b[i-1]]){
            cout << "0\n";
            return 0;    
        }
        for(ll j = mpp[b[i-1]]; j <= mpp[b[i]]; ++j)
            if(a[j] < b[i-1]){
                cout << "0\n";
                return 0;        
            }
        ll j;
        for(j = mpp[b[i]]; a[j] >= b[i]; --j);
        ans = ans*(mpp[b[i]]-j)%mod;
    }
    for(ll i = mpp[b[m]]; i <= n; ++i)
        if(a[i] < b[m]){
            cout << "0\n";
            return 0;        
        }
    cout << ans << '\n';
}