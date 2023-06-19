#include "bits/stdc++.h"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
ll n, k;
ll c[300009];
ll a[300009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> c[i];
    multiset<pii> s;
    ll sum = 0;
    ll ans = 0;
    for(ll i = 0; i < k; ++i){
        s.insert({c[i], i});
        sum += c[i];
        
        ans += sum;
    }
    for(ll i = k; i < n+k-1; ++i){
        if(i < n){
            s.insert({c[i], i});
            sum += c[i];
        }
        
        auto it = s.end();
        --it;
        sum -= it->ff;
        a[it->ss] = i+1;
        s.erase(it);

        ans += sum;
    }
    auto it = s.end();
    --it;
    a[it->ss] = n+k;

    cout << ans << '\n';
    for(ll i = 0; i < n; ++i)
        cout << a[i] << ' ';
}