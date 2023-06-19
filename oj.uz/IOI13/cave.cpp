#include "cave.h"
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
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
int s[5009], d[5009];
int done[5009];
int fin = 0;
int cur;
int inf = 1e9;
int binsearch(int l, int r){
    if(l == r)
        return l;
    int m = (l+r)/2;
    for(int i = l; i <= m; ++i)
        if(done[i] == 0){
            s[i] ^= 1;
        }
    int newcur = tryCombination(s);
    if(newcur == -1) newcur = inf;
    for(int i = l; i <= m; ++i)
        if(done[i] == 0)
            s[i] ^= 1;
    if(newcur != cur)
        return binsearch(l, m);
    else{
        //cout << "HEY\n";
        return binsearch(m+1, r);
    }
}
 
void exploreCave(int N) {
    cur = tryCombination(s);
    if(cur == -1) cur = inf;
    int cnt = N;
    while(cnt--){
 
        int idx = binsearch(0, N-1);
        s[idx] ^= 1;
        done[idx] = 1;
        
        int newcur = tryCombination(s);
        if(newcur == -1) newcur = inf;
        if(newcur < cur){
            s[idx] ^= 1;
            d[idx] = newcur;
        }
        else{        
 
            d[idx] = cur;
            cur = newcur;
 
        }
    }
    answer(s, d);
}
