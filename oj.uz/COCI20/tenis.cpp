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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
vector<vector<ll>> a;
ll n;
ll play[100009];
ll court[100009];
void manual(ll x, ll y){
    vector<vector<ll>> rnk;
    for(ll i = 0; i < 3; ++i){
        rnk.pb({min(a[x][i], a[y][i]), max(a[x][i], a[y][i]), i});
    }
    sort(all(rnk));
    ll cur = rnk[0][2];
    court[cur]++;
    if(a[x][cur] < a[y][cur])
        ++play[x];
    else
        ++play[y];
}
vector<ll> best[100009];
ll dp[(1<<3)][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n;
    a = vector<vector<ll>> (n, vector<ll>(3));
    for(ll i = 0; i < 3; ++i)
        for(ll j = 0; j < n; ++j){
            ll idx;
            cin >> idx;
            a[idx-1][i] = j;
        }
    for(ll i = 0; i < n; ++i){
        ll mini = 1e9;
        for(auto u : a[i])
            mini = min(mini, u);
        best[mini].pb(i);
    }
    for(ll i = n-1; i >= 0; --i){
        for(auto idx : best[i]){
            ll st = 0;
            for(ll j = 0; j < 3; ++j)
                if(a[idx][j] == i)
                    st += (1<<j);
            for(ll j = 0; j < 3; ++j){
                play[idx] += dp[st][j];
                court[j] += dp[st][j];
            }
        }
        for(ll j = 0; j < best[i].size(); ++j)
            for(ll k = j+1; k < best[i].size(); ++k)
                manual(best[i][j], best[i][k]);
        for(auto idx : best[i]){
            for(ll st = 1; st < (1<<3); ++st){
                vector<pii> rnk;
                for(ll j = 0; j < 3; ++j)
                    if(st&(1<<j))
                        rnk.pb({a[idx][j], j});
                sort(all(rnk));
                dp[st][rnk[0].ss]++;
            }
        }
    }
    cout << court[0] << ' ' << court[1] << ' ' << court[2] << '\n';
    for(ll i = 0; i < n; ++i)
        cout << play[i] << ' ';
}
