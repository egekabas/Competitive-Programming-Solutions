#include <bits/stdc++.h>
#include "library.h"
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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n1;
int q(vector<int> v){
    if(v.size() == 1)
        return 1;
    vector<int> mpp(n1);
    for(auto u : v)
        mpp[u-1] = 1;
    return Query(mpp);
}
vector<vector<int>> div(vector<int> v){
    if(v.empty())
        return vector<vector<int>>();
    vector<int> v2;
    vector<int> newv;
    for(auto u : v){
        v2.pb(u);
        if(q(v2) == v2.size())
            continue;
        newv.pb(u);
        v2.pop_back();
    }
    vector<vector<int>> ret = div(newv);
    sort(v2.begin(), v2.end());
    ret.pb(v2);
    return ret;
}
int binsearch(int val, vector<int> v){
    int l = 0, r = v.size()-1;
    while(l < r){
        int m = (l+r)/2;
        vector<int> tmp;
        for(int i = 0; i <= m; ++i)
            tmp.pb(v[i]);
        tmp.pb(val);
        if(q(tmp) == tmp.size())
            l = m+1;
        else
            r = m;
    }
    return v[l];
}
void Solve(int n){
    n1 = n;
    if(n == 1){
        Answer({1});return;
    }
    if(n == 2){
        Answer({1, 2});return;
    }
    vector<int> v;
    for(int i = 1; i <= n; ++i)
        v.pb(i);
    vector<vector<int>> divi = div(v);
    vector<int> ans;
    int cur = 0;
    for(int i = 1; i <= n; ++i){
        vector<int> tmp;
        for(int j = 1; j <= n; ++j)
            if(i != j)
                tmp.pb(j);
        if(q(tmp) == 1){
            cur = i;
            break;
        }
    }
    ans.pb(cur);
    int cnt = 0;
    while(ans.size() < n){
        for(auto &u : divi){
            auto it = lower_bound(u.begin(), u.end(), cur);
            if(*it == cur){
                u.erase(it);
                break;
            }
        }
        for(auto v : divi){
            v.pb(cur);
            if(q(v) == v.size()) continue;
            v.pop_back();
            cur = binsearch(cur, v);
            ans.pb(cur);
            break;
        }
    }
    
    Answer(ans);
}
