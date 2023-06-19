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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pld;
ll n, q;
vector<ll> mpp;
pii todo[100009];
struct node{
    ll lval, rval, l, r, mid, midl, midr, midmid, empty = 1;
};
node merge(node a, node b){
    if(a.empty)
        return b;
    if(b.empty)
        return a;
    
    ll dis = b.lval-a.rval;
    node ret;
    ret.lval = a.lval;
    ret.rval = b.rval;
    ret.l = dis+b.l+a.l;
    ret.r = dis+a.r+b.r;
    ret.mid = dis+min(b.l+a.mid, a.r+b.mid);
    ret.midl = a.midl+dis+b.l;
    ret.midr = b.midr+dis+a.r;
    ret.midmid = min(a.midmid+dis+b.l, b.midmid+dis+a.r);
    ret.midmid = min(ret.midmid, a.mid+b.mid);
    ret.empty = 0;
    return ret;
}
node seg[800009];
ll st[200009];
void upd(ll v, ll tl, ll tr, ll idx, ll val){
    if(tl == idx && tr == idx){
        seg[v] = {mpp[idx], mpp[idx], 0, 0, 0, 0, 0, 0, 1};
        if(val)
            seg[v].empty = 0;
        return;
    }
    if(idx <= (tl+tr)/2)
        upd(2*v, tl, (tl+tr)/2, idx, val);
    else
        upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
    seg[v] = merge(seg[2*v], seg[2*v+1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> q;
    vector<ll> start(n);
    for(ll i = 0; i < n; ++i){
        cin >> start[i];
        mpp.pb(start[i]);
    }
    for(ll i = 0; i < q; ++i){
        cin >> todo[i].ff >> todo[i].ss;
        mpp.pb(todo[i].ss);
    }
    sort(all(mpp));
    mpp.resize(unique(all(mpp))-mpp.begin());

    for(auto u : start){
        st[lower_bound(all(mpp), u)-mpp.begin()] = 1;
    }
    for(ll i = 0; i < mpp.size(); ++i){
        upd(1, 0, mpp.size()-1, i, st[i]);
    }
    cout << seg[1].midmid << '\n';

    for(ll i = 0; i < q; ++i){
        ll idx = lower_bound(all(mpp), todo[i].ss)-mpp.begin();
        st[idx] = todo[i].ff;
        upd(1, 0, mpp.size()-1, idx, st[idx]);
        cout << seg[1].midmid << '\n';

    }
}