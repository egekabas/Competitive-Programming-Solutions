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
const ll sq = 205;
const ll mod = 998244353;
ll N;

ll n, k;
int block[500][100009];
pll val[500][210];
ll lazy[500];
void push(ll idx){
    for(int i = 0; i < sq; ++i){
        pll &u = val[idx][i];
        block[idx][u.ff] -= u.ss;
        block[idx][u.ff] %= mod;
        u.ff += lazy[idx];
        block[idx][u.ff] += u.ss;
        block[idx][u.ff] %= mod;
    }
    lazy[idx] = 0;
}
void segupd(ll idx, ll l, ll r, ll add){
    push(idx);

    l -= idx*sq;
    l = max(l, 0LL);
    r -= idx*sq;
    r = min(r, sq-1);
    for(int i = l; i <= r; ++i){
        block[idx][val[idx][i].ff] -= val[idx][i].ss;
        block[idx][val[idx][i].ff] %= mod;
        val[idx][i].ff += add;
        block[idx][val[idx][i].ff] += val[idx][i].ss;
        block[idx][val[idx][i].ff] %= mod;
    }
}
ll segget(ll idx, ll l, ll r, ll add){
    push(idx);
    ll ret = 0;
    l -= idx*sq;
    l = max(l, 0LL);
    r -= idx*sq;
    r = min(r, sq-1);

    for(int i = l; i <= r; ++i){
        if(val[idx][i].ff == add)
            ret = (ret+val[idx][i].ss)%mod;
    }
    return ret;
}
void upd(ll l, ll r, ll add){
    for(ll i = l/sq; i < N; ++i){
        ll beg = i*sq;
        ll end = min(n, (i+1)*sq-1);
        if(beg > r) break;
        else if(l <= beg && end <= r) lazy[i] += add;
        else
            segupd(i, l, r, add);
    }
}
ll get(ll l, ll r, ll add){
    ll ret = 0;
    for(ll i = l/sq; i < N; ++i){
        ll beg = i*sq;
        ll end = min(n, (i+1)*sq-1);
        if(beg > r)
            break;
        else if(l <= beg && end <= r){
            if(add-lazy[i] >= 0 && add-lazy[i] <= 100005){

                ret = (ret + block[i][add-lazy[i]])%mod;                
            }
        }
        else{
            ret = (ret+segget(i, l, r, add))%mod;
        }
    }
    return ret;
}
ll addval(ll idx, ll add){
    ll bidx = idx/sq;
    block[bidx][val[bidx][idx-bidx*sq].ff] -= val[bidx][idx-bidx*sq].ss;
    block[bidx][val[bidx][idx-bidx*sq].ff] %= mod;
    val[bidx][idx-bidx*sq].ss = add-lazy[bidx];
    block[bidx][val[bidx][idx-bidx*sq].ff] += val[bidx][idx-bidx*sq].ss;
    block[bidx][val[bidx][idx-bidx*sq].ff] %= mod;
}
vector<ll> mpp[100009];
ll a[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    N = (n+sq-1)/sq;
    ll curans = 1;
    addval(0, 1);
    for(ll i = 0; i < n; ++i){
        ll effbef = 0;
        if(!mpp[a[i]].empty())
            effbef = mpp[a[i]].back()+1;
        curans -= get(effbef, i, k);
        curans = (curans+mod)%mod;
        upd(effbef, i, 1);
        
        if(!mpp[a[i]].empty()){
            ll effbef = 0;
            if(mpp[a[i]].size() >= 2)
                effbef = mpp[a[i]][mpp[a[i]].size()-2]+1;
            curans += get(effbef, mpp[a[i]].back(), k+1);
            curans %= mod;
            upd(effbef, mpp[a[i]].back(), -1);
        
        }
        mpp[a[i]].pb(i);
        if(i != n-1){
            addval(i+1, curans);

            curans *= 2;
            curans %= mod;    
        }
        else
            cout << (curans+mod)%mod << '\n';
    }
}