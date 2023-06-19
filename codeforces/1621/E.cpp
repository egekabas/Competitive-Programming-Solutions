#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
ll val(pll x){
    return (x.ss+x.ff-1)/x.ff;
}
ll sf(pair<pll, ll> a, pair<pll, ll> b){
    return val(a.ff) < val(b.ff);
}

ll n, m;
ll a[100009];
ll gidx[100009];
pair<pll, ll> gr[100009];
ll bef[100009], cur[100009], aft[100009];
void solve(){
    cin >> n >> m;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n, greater<ll>());
    n = m;
    reverse(a, a+n);
    
    vector<pll> allval;
    for(ll i = 0; i < n; ++i){
        cin >> gr[i].ff.ff;
        gr[i].ss = i;
        gr[i].ff.ss = 0;
        for(ll j = 0; j < gr[i].ff.ff; ++j){
            ll val;
            cin >> val;
            gr[i].ff.ss += val;
            allval.pb({val, i});
        }
    }
    
    sort(gr, gr+n, sf);
    for(ll i = 0; i < n; ++i)
        gidx[gr[i].ss] = i;

    for(ll i = 0; i < n; ++i){
        if(i == 0)
            bef[i] = cur[i] = aft[i] = 0;
        else{
            bef[i] = bef[i-1];
            cur[i] = cur[i-1];
            aft[i] = aft[i-1];
        }
        if(i != 0 && val(gr[i].ff) <= a[i-1])
            bef[i]++;
        if(val(gr[i].ff) <= a[i])
            cur[i]++;
        if(i != n-1 && val(gr[i].ff) <= a[i+1])
            aft[i]++;
    }
    for(auto u : allval){
        ll idx = gidx[u.ss];
        pll ng = pll(gr[idx].ff.ff-1, gr[idx].ff.ss-u.ff);
        ll nidx = upper_bound(gr, gr+n, make_pair(ng, 0LL), sf)-gr;

        if(nidx > idx){
            --nidx;
            ll sum = 0;
            if(idx)
                sum += cur[idx-1];
            sum += bef[nidx]-bef[idx];
            sum += val(ng) <= a[nidx];
            sum += cur[n-1]-cur[nidx];
            cout << (sum == n);
        }
        else{
            ll sum = 0;
            if(nidx)
                sum += cur[nidx-1];
            sum += val(ng) <= a[nidx];
            if(idx){
                if(nidx)
                    sum += aft[idx-1]-aft[nidx-1];
                else
                    sum += aft[idx-1];
            }
            
            sum += cur[n-1]-cur[idx];
            cout << (sum == n);
        }
    }
    cout << '\n';
}
int main(){
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    ll t;
    cin >> t;
    while(t--)
        solve();
}
