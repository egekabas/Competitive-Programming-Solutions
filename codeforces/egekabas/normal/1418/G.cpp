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
int n;
int a[500009];
vector<int> g[500009];
ll pre[500009];
ll pw[500009];
int cnt[500009];
unordered_map<ll, int> mpp;
const ll mod = 1e14+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    pw[0] = 1;
    for(int i = 1; i <= n; ++i){
        pw[i] = pw[i-1]*((ll)1e6+7)%mod;
    }
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1];
        cnt[a[i]]++;
        if(cnt[a[i]] != 3){
            pre[i] += pw[a[i]];
        }
        else{
            cnt[a[i]] -= 3;
            pre[i] -= 2*pw[a[i]]%mod;

        }
        pre[i] %= mod;
        pre[i] = (pre[i]+mod)%mod;
    }
    int ridx = n;
    ll ans = 0;
    for(int i = n; i >= 1; --i){
        mpp[pre[i]]++;
        g[a[i]].pb(i);
        while((int)g[a[i]].size()-4 >= 0 && ridx >= g[a[i]][g[a[i]].size()-4]){
            mpp[pre[ridx]]--;
            ridx--;
        }
        ans += mpp[pre[i-1]];
    }
    cout << ans << '\n';
}