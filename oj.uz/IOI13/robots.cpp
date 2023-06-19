#include "robots.h"
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
int a, b, t;
vector<pii> v;
set<pii> y;
int cnty[50009];
int x[50009];
int check(int val){
    int curdix = 0;
    int pocket = 0;
    for(auto u : v){
        auto i1 = y.lower_bound(mp(u.ss, 1e9));
        if(i1 != y.end()){
            ++cnty[i1->ss];
            if(cnty[i1->ss] >= val)
                y.erase(i1);
            continue;
        }
        while(curdix < a && x[curdix] > u.ff){
            pocket += val;
            curdix++;
        }
        if(pocket == 0) return 0;
        --pocket;
    }
    return 1;
}
int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    a = A;
    b = B;
    t = T;
    for(int i = 0; i < t; ++i){
        v.pb({W[i], S[i]});
    }
    sort(all(v), greater<pii>());
    for(int i = 0; i < A; ++i)
        x[i] = X[i];
    sort(x, x+a, greater<int>());
    int l = 1, r = t+1;
    while(l < r){
        y.clear();
        for(int i = 0; i < b; ++i){
            cnty[i] = 0;
            y.insert({Y[i], i});
        }
        int m = (l+r)/2;
        int st = check(m);
        if(st){
            r = m;
        }
        else
            l = m+1;
    }
    if(l == t+1){
        return -1;
    }
    return l;
}
