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
typedef pair<int, int>  pii;
typedef pair<ld, ld>  pld;
int n, m;
struct dish{
    int pri, st, bt, id;
};
struct per{
    int inc, pref, id;
};
int sortpri(dish a, dish b){return a.pri < b.pri;}
int sortst(dish a, dish b){return a.st < b.st;}
int sortbt(dish a, dish b){return a.bt < b.bt;}
int sortinc(per a, per b){return a.inc < b.inc;}

void upd(int idx, int val, vector<int> &bit){    
    for(++idx; idx < bit.size(); idx += idx&(-idx))
        bit[idx] += val;
}
int get(int idx, vector<int> &bit){
    int ret = 0;
    for(++idx; idx > 0; idx -= idx&(-idx))
        ret += bit[idx];
    return ret;
}
per people[100009];
dish pri[100009];
dish st[100009];
dish bt[100009];
int get(int v, int tl, int tr, int l, int r, int val, vector<int> seg[], vector<int> bit[]){
    if(tr < l || r < tl)
        return 0;
    if(l <= tl && tr <= r){
        int id = upper_bound(seg[v].begin(), seg[v].end(), val)-seg[v].begin();
        return get(id-1, bit[v]);
    }
    else{
        int tm = (tl+tr)/2;
        return get(2*v, tl, tm, l , r, val, seg, bit)+get(2*v+1, tm+1, tr, l , r, val, seg, bit);
    }
}
void build(int v, int tl, int tr, vector<int> seg[], vector<int> bit[], vector<int> &val){
    if(tl == tr)
        seg[v].pb(val[tl]);
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm, seg, bit, val);
        build(2*v+1, tm+1, tr, seg, bit, val);
        seg[v].resize(seg[2*v].size()+seg[2*v+1].size());
        merge(seg[2*v].begin(),seg[2*v].end(), seg[2*v+1].begin(),seg[2*v+1].end(), seg[v].begin());
    }
    bit[v].resize(seg[v].size()+1);
}
void upd(int v, int tl, int tr, int idx, int val, int change, vector<int> seg[], vector<int> bit[]){
    int id = lower_bound(seg[v].begin(), seg[v].end(), val)-seg[v].begin();
    upd(id, change, bit[v]);
    if(tl != tr){
        int tm = (tl + tr)/2;
        if(idx <= tm)
            upd(2*v, tl, tm, idx, val, change, seg, bit);
        else
            upd(2*v+1, tm+1, tr, idx, val, change, seg, bit);
    }
}
vector<int> seglow[400009];
vector<int> bitlow[400009];

vector<int> seghigh[400009];
vector<int> bithigh[400009];

vector<int> vallow;
vector<int> valhigh;

int place[100009];
int ans[100009];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> pri[i].pri;
    for(int i = 0; i < n; ++i)
        cin >> pri[i].st;
    for(int i = 0; i < n; ++i)
        cin >> pri[i].bt;
    for(int i = 0; i < n; ++i)
        st[i] = bt[i] = pri[i];
    for(int i = 0; i < m; ++i)
        cin >> people[i].inc;
    for(int i = 0; i < m; ++i){
        cin >> people[i].pref;
        people[i].id = i;
    }
    for(int i = 0; i < n; ++i){
        pri[i].id = i;
        st[i] = bt[i] = pri[i];
    }
    sort(pri, pri + n, sortpri);
    sort(st, st + n, sortst);
    sort(bt, bt + n, sortbt);
    sort(people, people + m, sortinc);
    for(int i = 0; i < n; ++i){
        place[bt[i].id] = i;
        valhigh.pb(bt[i].bt+bt[i].pri);
        vallow.pb(-bt[i].bt+bt[i].pri);
    }
    build(1, 0, n-1, seglow, bitlow, vallow);
    build(1, 0, n-1, seghigh, bithigh, valhigh);
    
    int priit = 0;
    int stit = 0;
    for(int i = 0; i < m; ++i){
        while(priit < n && pri[priit].pri <= people[i].inc){
            upd(1, 0, n-1, place[pri[priit].id], pri[priit].bt+pri[priit].pri, 1, seghigh, bithigh);
            upd(1, 0, n-1, place[pri[priit].id], -pri[priit].bt+pri[priit].pri, 1, seglow, bitlow);
            priit++;
        }
        while(stit < n && st[stit].st < people[i].inc){
            upd(1, 0, n-1, place[st[stit].id], st[stit].bt+st[stit].pri, -1, seghigh, bithigh);
            upd(1, 0, n-1, place[st[stit].id], -st[stit].bt+st[stit].pri, -1, seglow, bitlow);
            stit++;
        }
        int l = 0, r = n;
        while(l < r){
            int m = (l+r)/2;
            if(bt[m].bt < people[i].pref)
                l = m+1;
            else
                r = m;
        }
        ans[people[i].id] += get(1, 0, n-1, l, n-1, people[i].inc+people[i].pref, seghigh, bithigh);
        ans[people[i].id] += get(1, 0, n-1, 0, l-1, people[i].inc-people[i].pref, seglow, bitlow);
    }
    for(int i = 0; i < m; ++i)
        cout << ans[i] << ' ';
}