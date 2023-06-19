#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll>    pll;
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;

ll n, m;
ll num[200009];

vector<pll> snum;
vector<pair<ll, pll>> sedge;


ll func1(pll a, pll b){
    return a.ff < b.ff;
}
ll func2(pair<ll, pll> a, pair<ll, pll> b){
    return a.ff < b.ff;
}

ll prt[200009];
ll sz[200009];
ll findp(ll a){
    if(prt[a] == a)return a;
    else return findp(prt[a]);
}
void crt(ll a){
    prt[a] = a;
    sz[a] = 1;
}
void merge(ll a, ll b){
    a = findp(a);
    b = findp(b);
    if(sz[a] > sz[b])swap(a, b);
    prt[a] = b;
    sz[b] += sz[a];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("../IO/in.txt", "r", stdin);
    freopen("../IO/out.txt", "w", stdout);
#endif

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
        snum.pb({num[i], i});
    }

    ll t1, t2, t3;
    for(ll i = 0; i < m; ++i){
        cin >> t1 >> t2 >> t3;
        sedge.pb({t3, {t1, t2}});
    }

    for(ll i = 1; i <= n; ++i){
        crt(i);
    }

    sort(snum.begin(), snum.end(), func1);
    sort(sedge.begin(), sedge.end(), func2);

    auto itr1 = snum.begin();
    auto itr2 = itr1+1;
    auto itr3 = sedge.begin();
    ll ans = 0;
    ll edges = 0;

    while(edges < n-1){
        while(findp((*itr1).ss) == findp((*itr2).ss) ){
            ++itr2;
        }
        while(itr3 != sedge.end() && findp((*itr3).ss.ff) == findp((*itr3).ss.ss)){
            ++itr3;
        }
        if(itr3 == sedge.end() || (*itr1).ff + (*itr2).ff < (*itr3).ff){
            ans += (*itr1).ff + (*itr2).ff;
            merge((*itr1).ss,(*itr2).ss);
        }
        else{
            ans += (*itr3).ff;
            merge((*itr3).ss.ff, (*itr3).ss.ss);
        }
        ++edges;
    }
    cout << ans << endl;
}