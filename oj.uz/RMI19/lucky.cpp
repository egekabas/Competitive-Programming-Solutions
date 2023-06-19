#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll mod = 1e9+7;
struct node{
    ll small = 0, small1 = 0, small3 = 0, small13 = 0;
    ll big = 0, big1 = 0, big3 = 0, big13 = 0;
    ll eq = 0, eq1 = 0, eq3 = 0, eq13 = 0;
    ll empty = 0;
    node(){
        empty = 1;
    }
    node(ll val){
        small = val;
        if(val > 1) small1 = 1;
        if(val > 3) small3 = 1;
        
        big = 9-val;
        if(val < 1) big1 = 1;
        if(val < 3) big3 = 1;
 
        eq = 1;
        if(val == 1) eq1 = 1;
        if(val == 3) eq3 = 1;
    }
};
node merge(node a, node b){
    if(a.empty) return b;
    if(b.empty) return a;
    node ret;
    ret.empty = 0;
    ret.small = a.small*(b.small+b.big+b.eq)%mod-a.small1*(b.small3+b.big3+b.eq3)%mod;
    ret.small1 = a.small*(b.small1+b.big1+b.eq1)%mod-a.small1*(b.small13+b.big13+b.eq13)%mod;
    ret.small3 = a.small3*(b.small+b.big+b.eq)%mod-a.small13*(b.small3+b.big3+b.eq3)%mod;
    ret.small13 = a.small3*(b.small1+b.big1+b.eq1)%mod-a.small13*(b.small13+b.big13+b.eq13)%mod;
    
    ret.small += a.eq*b.small%mod-a.eq1*b.small3%mod;
    ret.small1 += a.eq*b.small1%mod-a.eq1*b.small13%mod;
    ret.small3 += a.eq3*b.small%mod-a.eq13*b.small3%mod;
    ret.small13 += a.eq3*b.small1%mod-a.eq13*b.small13%mod;
 
    ret.big = a.big*(b.small+b.big+b.eq)%mod-a.big1*(b.small3+b.big3+b.eq3)%mod;
    ret.big1 = a.big*(b.small1+b.big1+b.eq1)%mod-a.big1*(b.small13+b.big13+b.eq13)%mod;
    ret.big3 = a.big3*(b.small+b.big+b.eq)%mod-a.big13*(b.small3+b.big3+b.eq3)%mod;
    ret.big13 = a.big3*(b.small1+b.big1+b.eq1)%mod-a.big13*(b.small13+b.big13+b.eq13)%mod;
    
    ret.big += a.eq*b.big%mod-a.eq1*b.big3%mod;
    ret.big1 += a.eq*b.big1%mod-a.eq1*b.big13%mod;
    ret.big3 += a.eq3*b.big%mod-a.eq13*b.big3%mod;
    ret.big13 += a.eq3*b.big1%mod-a.eq13*b.big13%mod;
    
    ret.eq = a.eq*b.eq%mod-a.eq1*b.eq3%mod;
    ret.eq1 = a.eq*b.eq1%mod-a.eq1*b.eq13%mod;
    ret.eq3 = a.eq3*b.eq%mod-a.eq13*b.eq3%mod;
    ret.eq13 = a.eq3*b.eq1%mod-a.eq13*b.eq13%mod;
    
 
    ret.small %= mod;
    ret.small1 %= mod;
    ret.small3 %= mod;
    ret.small13 %= mod;
    ret.big %= mod;
    ret.big1 %= mod;
    ret.big3 %= mod;
    ret.big13 %= mod;
    ret.eq %= mod;
    ret.eq1 %= mod;
    ret.eq3 %= mod;
    ret.eq13 %= mod;
 
    ret.small += mod;
    ret.small1 += mod;
    ret.small3 += mod;
    ret.small13 += mod;
    ret.big += mod;
    ret.big1 += mod;
    ret.big3 += mod;
    ret.big13 += mod;
    ret.eq += mod;
    ret.eq1 += mod;
    ret.eq3 += mod;
    ret.eq13 += mod;
    
    ret.small %= mod;
    ret.small1 %= mod;
    ret.small3 %= mod;
    ret.small13 %= mod;
    ret.big %= mod;
    ret.big1 %= mod;
    ret.big3 %= mod;
    ret.big13 %= mod;
    ret.eq %= mod;
    ret.eq1 %= mod;
    ret.eq3 %= mod;
    ret.eq13 %= mod;
    return ret; 
}
node seg[400009];
string s;
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        seg[v] = node(s[tl]-'0');
        //cout << tl << ' ' << s[tl]-'0' << '\n';
        return;
    }
    build(2*v, tl, (tl+tr)/2);
    build(2*v+1, (tl+tr)/2+1, tr);
    seg[v] = merge(seg[2*v], seg[2*v+1]);
}
void upd(ll v, ll tl, ll tr, ll idx, ll val){
    if(idx < tl || idx > tr) return;
    if(idx == tl && idx == tr)
        seg[v] = node(val);
    else{
        upd(2*v, tl, (tl+tr)/2, idx, val);
        upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
node get(ll v, ll tl, ll tr, ll l, ll r){
    if(r < tl || tr < l) return node();
    if(l <= tl && tr <= r){
        return seg[v];
    }
    else{
        return merge(
            get(2*v, tl, (tl+tr)/2, l, r),
            get(2*v+1, (tl+tr)/2+1, tr, l, r)  
        );
    }
}
 
ll n, q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> q;
    cin >> s;
    build(1, 0, n-1);
    cout << (seg[1].small+seg[1].eq)%mod << '\n';  
    while(q--){
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            --x;
            --y;
            //cout << x << ' ' << y << '\n';
            node cur = get(1, 0, n-1, x, y);
            cout << (cur.small+cur.eq)%mod << '\n';
        }
        else{
            --x;
            upd(1, 0, n-1, x, y);
        }
    }  
}
