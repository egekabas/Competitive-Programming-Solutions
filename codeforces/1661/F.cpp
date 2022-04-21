#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n, a[200009], maxcost;

ll getcost(ll val, ll div){
    ll base = val/div;
    ll rem = val%div;

    return rem*(base+1)*(base+1)+(div-rem)*base*base;
}

ll getgain(ll val, ll div){
    return getcost(val, div-1)-getcost(val, div);
}

ll ext = 0;

pll calc(ll mingain){
    ext = 0;

    ll cost = 0;
    ll tel = 0;
    for(ll i = 0; i < n; ++i){

        ll l1 = 1, r1 = a[i]+1;
        while(l1 < r1){
            ll m = (l1+r1+1)/2;
            
            if(getgain(a[i], m) < mingain)
                r1 = m-1;
            else
                l1 = m;
        }

        ll l2 = 1, r2 = a[i]+1;
        while(l2 < r2){
            ll m = (l2+r2+1)/2;
            if(getgain(a[i], m) <= mingain)
                r2 = m-1;
            else
                l2 = m;
        }
        
        
        cost += getcost(a[i], l1);
        tel += l1-1;

        ext += l1-l2;
    }
    return {cost, tel};
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> maxcost;


    ll maxa = 0;
    for(ll i = 0; i < n; ++i){
        a[i] = a[i+1]-a[i];
        maxa = max(maxa, a[i]);
        //cout << a[i] << ' ';
    }
    //cout << '\n';

    //cout << calc(234209176).ff << '\n';
    //return 0;

    ll l = 0, r = getgain(maxa, 2)+2;


    while(l < r){
        ll m = (l+r+1)/2;

        if(calc(m).ff > maxcost)
            r = m-1;
        else
            l = m;
    }
    pll cur = calc(l);

    //cout << l << '\n';

    ll cost = cur.ff, tel = cur.ss;

    
    ll notneeded = (maxcost-cost)/l;
    tel -= min(notneeded, ext);

    cout << tel << '\n';
}