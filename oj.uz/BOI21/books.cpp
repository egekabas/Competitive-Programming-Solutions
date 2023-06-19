#include <bits/stdc++.h>
#include "books.h"
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
 
//
// --- Sample implementation for the task books ---
//
// To compile this program with the sample grader, place:
//     books.h books_sample.cpp sample_grader.cpp
// in a single folder and run:
//     g++ books_sample.cpp sample_grader.cpp
// in this folder.
//
void finish(multiset<pll> &ans){
    vector<int> v;
    for(auto u : ans)
        v.pb(u.ss);
    answer(v);
}
vector<ll> befask;
ll ask(ll x){
    if(befask[x]) return befask[x];
    return (befask[x] = skim(x));
}
void solve(int N, int K, long long A, int S) {
    befask.resize(N+1);
    multiset<pll> s;
    ll curval = 0;
    for(ll i = 1; i <= K; ++i){
        s.insert({ask(i), i});
        curval += ask(i);
    }
    if(curval > 2*A){
        impossible();
        return;
    }
    if(curval >= A){
        finish(s);
        return;
    }
    ll l = K+1, r = N;
    while(l < r){
        ll m = (l+r+1)/2;
        auto it = s.end();
        --it;
        ll largest = it->ff;
        if(curval-largest+ask(m) > 2*A)
            r = m-1;
        else
            l = m;
    }
    for(ll i = l; i > K && curval < A; --i){
        ll addval = ask(i);
        ll ermin = curval+addval-2*A;
        auto it = s.lower_bound({ermin, 0});
        if(it == s.end()) continue;
        if(it->ff >= addval) break;
        curval -= it->ff;
        s.erase(it);
        s.insert({addval, i});
        curval += addval;
    }
    if(curval >= A && 2*A >= curval)
        finish(s);
    else
        impossible();
}
