#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

ll d[1000009];
vector<pii> g[1000009];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll n, m;
ll p[1000009];
vector<ll> ans;

void dijk(ll s){
    for(ll i = 0; i <= n; ++i)
        d[i] = (ll)1e13;
    d[s] = 0;
    pq.push(mp(0, s));
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(tmp.ff > d[tmp.ss])
            continue;
        for(pii u : g[tmp.ss]){
            if(d[u.ff] > u.ss + d[tmp.ss]){
                d[u.ff] = u.ss + d[tmp.ss];
                pq.push(mp(d[u.ff], u.ff));
                p[u.ff] = tmp.ss;
            }
        }
        //cout << "HEY\n";
    }
}
int main(){
    cin >> n >> m;
    ll x, y, z;
    for(ll i = 0; i < m; ++i){
        cin >> x >> y >> z;
        g[x].pb(mp(y, z));
        g[y].pb(mp(x, z));
    }
    dijk(1);
    if(p[n] == 0)
        cout << -1 << endl;
    else{
        ll tmp = n;
        while(1){
            ans.pb(tmp);
            if(tmp == 1)
                break;
            tmp = p[tmp];
        }
        reverse(ans.begin(), ans.end());
        for(auto u : ans)
            cout << u << " ";
    }
}