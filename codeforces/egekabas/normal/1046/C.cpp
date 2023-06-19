#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;
typedef long long   ll;

ll n, d;
ll a[200009];
vector <ll> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif
    cin >> n >> d;
    --d;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    ll tmp;
    for(ll i = 0; i < n; ++i){
        cin >> tmp;
        s.pb(tmp);
    }

    ll ans = d+1;
    ll x = a[d] + s[0];
    //cout << x << endl;

    for(ll j = 1; j < n; ++j){
        if(ans == 1)
            continue;
        //cout << a[ans-2] << endl;
        if(a[ans-2] + s[j] <= x)
            --ans;
    }

    cout << ans;
}