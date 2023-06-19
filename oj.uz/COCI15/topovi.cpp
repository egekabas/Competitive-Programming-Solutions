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
ll n, k, p;
map<ll, ll> rowval;
map<ll, ll> colval;
 
map<ll, ll> valrow;
map<ll, ll> valcol;
 
map<pll, ll> rooks;
ll rowsize = 0;
ll colsize = 0;
ll overlap = 0;
void add(ll x, ll y, ll val){
    if(rowval[x] == 0)
        ++rowsize;
    else
        overlap -= valcol[rowval[x]];
    
    if(colval[y] == 0)
        ++colsize;
    else
        overlap -= valrow[colval[y]];
 
    if(rowval[x] == colval[y] && rowval[x] != 0 && colval[y] != 0)
        ++overlap;
    
    valrow[rowval[x]]--;
    rowval[x] ^= val;
    valrow[rowval[x]]++;
 
    valcol[colval[y]]--;
    colval[y] ^= val;
    valcol[colval[y]]++;
 
    if(rowval[x] == 0)
        --rowsize;
    else
        overlap += valcol[rowval[x]];
    
    if(colval[y] == 0)
        --colsize;
    else
        overlap += valrow[colval[y]];
 
    if(rowval[x] == colval[y] && rowval[x] != 0 && colval[y] != 0)
        --overlap;
 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> k >> p;
    while(k--){
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        rowval[t1] ^= t3;
        colval[t2] ^= t3;
        rooks[{t1, t2}] = t3;
    }
 
    for(auto u : colval){
        if(u.ss == 0)
            continue;
        ++colsize;
        valcol[u.ss]++;
    }
    for(auto u : rowval){
        if(u.ss == 0)
            continue;
        ++rowsize;
        valrow[u.ss]++;
    }
    for(auto u : valcol){
        overlap += u.ss*valrow[u.ff];
    }
    while(p--){
        ll t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        add(t1, t2, rooks[{t1, t2}]);
        //cout << rowsize << " " << colsize << " " << overlap << " ";
        //cout << rowsize*n+colsize*n-rowsize*colsize-overlap << "\n";
        add(t3, t4, rooks[{t1, t2}]);
        rooks[{t3, t4}] = rooks[{t1, t2}];
        rooks[{t1, t2}] = 0;
        //cout << rowsize << " " << colsize << " " << overlap << " ";
        cout << rowsize*n+colsize*n-rowsize*colsize-overlap << "\n";
    }
}
