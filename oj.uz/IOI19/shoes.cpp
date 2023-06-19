    #include "shoes.h"
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
    int bit[500009];
    int n;
    void upd(int idx, int val){
        for(++idx; idx <= n; idx += idx&(-idx))
            bit[idx] += val;
    }
    int get(int idx){
        int ret = 0;
        for(++idx; idx > 0; idx -= idx&(-idx))
            ret += bit[idx];
        return ret;
    }
    queue<int> lef[500009];
    queue<int> rig[500009];
    set<pii> v;
    long long count_swaps(vector<int> s) {
        ll ans = 0;
        n = s.size();
        for(int i = 0; i < n; ++i){
            v.insert({i, s[i]});
            if(s[i] < 0)
                lef[-s[i]].push(i);
            else
                rig[s[i]].push(i);
            upd(i, 1);
        }
        while(v.size()){
            pii cur = *v.begin();
            v.erase(v.begin());
            pii pair;
            if(cur.ss < 0){
                pair = {rig[-cur.ss].front(), -cur.ss};
                rig[-cur.ss].pop();
                lef[-cur.ss].pop();
            }
            else{
                pair = {lef[cur.ss].front(), -cur.ss};
                lef[cur.ss].pop();
                rig[cur.ss].pop();
            }
            v.erase(pair);
            ans += get(pair.ff)-1;
            upd(cur.ff, -1);
            upd(pair.ff, -1);
            if(cur.ss < 0)
                --ans;
        }
        return ans;
    }
