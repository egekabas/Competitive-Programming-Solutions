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
ll n, m;
ll a[200009];
vector<ll> v[200009];
ll pre[200009];
ll base = 0;
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i){
        cin >> a[i];
        v[a[i]].pb(i);
    }
    for(ll i = 0; i < m-1; ++i){
        if(a[i] == a[i+1])
            continue;
        pre[min(a[i],a[i+1])+1]++;
        pre[max(a[i],a[i+1])]--;
        base += abs(a[i]-a[i+1]);
    }
    for(ll i = 1; i <= n+3; ++i){
        pre[i] += pre[i-1];
    }
    cout << base << " ";
    for(ll i = 2; i <= n; ++i){
        ll cur = base;
        cur -= pre[i];
        //cout << pre[i] << " ";
        for(auto u : v[i]){
            if(u != m-1 && a[u+1] != i){
                cur += a[u+1];
                if(a[u+1] > i)
                    --cur;
                cur -= abs(a[u]-a[u+1]);
            }
            if(u != 0 && a[u-1] != i){
                cur += a[u-1];
                if(a[u-1] > i)
                    --cur;
                cur -= abs(a[u]-a[u-1]);
            }
        }
        cout << cur << " ";
    }
}