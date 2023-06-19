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
int n, l, q;
int a[10009];
int ans[109][10009];
int k[109];
vector<int> val;
vector<int> st[10009];
ll tot[10009][109];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> l;
    vector<int> mpp;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> q;
    for(int i = 0; i < q; ++i){
        cin >> k[i];
        val.pb(k[i]);
    }
    sort(all(val));
    val.resize(unique(all(val))-val.begin());
    for(int dis = 1; dis < n; ++dis){
        vector<int> pre(n);
        for(int i = 0; i+dis < n; ++i)
            if(a[i] == a[i+dis]){
                pre[max(0, i-l+1)]++;
                pre[i+1]--;
            }
        for(int i = 0; i < n; ++i){
            if(i)
                pre[i] += pre[i-1];
            if(i+dis+l <= n){
                int idx = lower_bound(all(val), l-pre[i])-val.begin();
                tot[i][idx]++;
                tot[i+dis][idx]++;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 1; j < val.size(); ++j)
            tot[i][j] += tot[i][j-1];
    for(int i = 0; i < q; ++i){
        ll curval = lower_bound(all(val), k[i])-val.begin();
        for(int j = 0; j+l <= n; ++j)
            cout << tot[j][curval] << ' ';
        cout << '\n';
    }
}
