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
ll mini[1000009];
ll maxi[1000009];
ll n, x;
ll ans = 0;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> x;
    ll tmp;
    for(ll i = 1; i <= n; ++i){
        cin >> tmp;
        if(mini[tmp] == 0) mini[tmp] = i;
        maxi[tmp] = max(maxi[tmp], i);
        mini[tmp] = min(mini[tmp], i);
    }
    ll last = 0;
    ll beg = 0;
    for(ll i = 1; i <= x; ++i){
        if(maxi[i] == 0){
            beg = i;
            continue;
        }
        if(mini[i] < last) break;
        beg = i; last = maxi[i];
    }
    ans += beg+1;
    ll first = 1e9;
    ll end = 1e9;
    for(ll i = x; i >= 1; --i){
        if(maxi[i] == 0){ 
            end = i;
            continue;
        }
        if(maxi[i] > first) break;
        end = i; first = mini[i];
    }
    for(ll i = 1; i <= x; ++i)
        if(maxi[i] == 0)
            maxi[i] = maxi[i-1];

    for(ll i = x; i >= end; --i){
        if(mini[i] == 0){
            while(beg >= i){
                --beg;
                if(beg == 0) last = 0;
                else last = maxi[beg];
            }
            ans += beg+1;
            continue;    
        }
        while(mini[i] < last || beg >= i){
            --beg;
            if(beg == 0) last = 0;
            else last = maxi[beg];
        }
        //cout << i << " " << beg+1 << endl;
        ans += beg+1;
    }
    if(end == 1){
        ans -= x+1;
    }
    cout << ans << endl;
}