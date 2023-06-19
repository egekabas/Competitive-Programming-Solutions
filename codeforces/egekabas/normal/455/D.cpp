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
const ll sq = 1800;

vector<ll> a;
struct node{
    vector<ll> mpp;
    vector<ll> ar;
    ll size(){
        return ar.size();
    }
    void addmpp(ll x){
        if(mpp.size() <= x)
            mpp.resize(x+1);
        mpp[x]++;
    }
    ll getmpp(int x){
        if(x < mpp.size())
            return mpp[x];
        return 0;
    }
    void init(ll l, ll r){
        mpp.clear();
        ar.clear();
        for(int i = l; i <= r; ++i){
            ar.pb(a[i]);
            addmpp(a[i]);
        }
    }
    void erase(ll idx){
        --mpp[ar[idx]];
        ar.erase(ar.begin()+idx);
    }
    void add(ll idx, ll val){
        addmpp(val);
        ar.insert(ar.begin()+idx, val);
    }
    ll get(ll l, ll r, ll k){
        if(l > r)
            return 0;
        if(l == 0 && r == ar.size()-1)
            return getmpp(k);
        ll tmp = 0;
        for(ll i = l; i <= r; ++i)
            tmp += (ar[i]==k);
        return tmp;    
    }
};
node dat[1009];
ll n, N;
void begin(){
    ll cur = 0;
    a.clear();
    for(ll i = 0; i < N; ++i)
        for(auto u : dat[i].ar)
            a.pb(u);
    
    for(ll i = 0; i < N; ++i){
        dat[i].init(cur, min(n-1, cur+sq-1));
        cur += sq;
    }
}
void shift(ll l, ll r){
    ll cur = 0;
    ll toadd = 0;
    for(ll i = 0; i < N; ++i){
        if(cur <= r && r < cur+dat[i].size()){
            toadd = dat[i].ar[r-cur];
            dat[i].erase(r-cur);
            break;
        }
        cur += dat[i].size();
    }
    cur = 0;
    for(ll i = 0; i < N; ++i){
        if(cur <= l && l <= cur+dat[i].size()){
            dat[i].add(l-cur, toadd);
            break;
        }
        cur += dat[i].size();
    }
}
ll quer(ll l, ll r, ll k){
    ll cur = 0;
    ll ret = 0;
    for(ll i = 0; i < N; ++i){
        ret += dat[i].get(max(l, cur)-cur, min(cur+dat[i].size()-1, r)-cur, k);
        cur += dat[i].size();
        //for(auto u : dat[i].ar)
        //    cout << u << ' ';
        //cout << '\n';
    }
    return ret;
}
ll lastans;
ll dec(ll x){
    return (x+lastans-1)%n+1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
                                                                                                                        
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);    
    
    cin >> n;
    N = (n+sq-1)/sq;
    for(ll i = 0; i < n; ++i){
        ll tmp;
        cin >> tmp;
        a.pb(tmp);
    }
    ll cur = 0;
    for(ll i = 0; i < N; ++i){
        dat[i].init(cur, min(n-1, cur+sq-1));
        cur += sq;
    }
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; ++i){
        if(i%(4*sq) == 0)
            begin();
        ll t, l, r, k;
        cin >> t >> l >> r;
        l = dec(l)-1;
        r = dec(r)-1;
        if(l > r)
            swap(l, r);
        if(t == 1){
            shift(l, r);
        }
        else{
            cin >> k;
            k = dec(k);
            lastans = quer(l, r, k);
            cout << lastans << '\n';
        }
    }
}