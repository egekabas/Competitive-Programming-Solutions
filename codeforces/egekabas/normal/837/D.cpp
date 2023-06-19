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
ll n, k;
ll a[209];
ll b[209];
ll c[209];
const ll maxval = 3602;
ll cur[209][maxval];
ll nxt[209][maxval];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i){
        while(a[i]%5 == 0){
            a[i] /= 5;
            ++b[i];
        }
        while(a[i]%2 == 0){
            a[i] /= 2;
            ++c[i];
        }
    }
    for(ll i = 0; i <= k; ++i)
        for(ll j = 0; j < maxval; ++j)
            cur[i][j] = -1e18;
    cur[k][0] = 0;
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        for(ll i = 0; i <= k; ++i)
            for(ll j = 0; j < maxval; ++j)
                nxt[i][j] = -1e18;

        for(ll j = 0; j <= k; ++j)
            for(ll l = 0; l < maxval; ++l){

                nxt[j][l] = max(nxt[j][l], cur[j][l]);
                //cout << i << ' ' << j << ' ' << l << ' ' << cur[j][l] << '\n';
                if(j > 0){
                    nxt[j-1][min(maxval-1, l+b[i])] = max(nxt[j-1][min(maxval-1, l+b[i])], cur[j][l]+c[i]);
                    //cout << i << ' ' << j-1 << ' ' << l+b[i] << ' ' << nxt[j-1][l+b[i]] << '\n';
                }
            }
        for(ll i = 0; i <= k; ++i)
            for(ll j = 0; j < maxval; ++j){
                cur[i][j] = nxt[i][j];
                ans = max(ans, min(cur[i][j], j));
            }
    }
    cout << ans << '\n';
}