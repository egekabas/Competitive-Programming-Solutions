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
ll p = 221269;
ll pwr[200009];
ll mod = 1e9+7;
struct node{
    ll beg = 0, end = 0;
    ll size = 0, hsh = 0;
};
void print(node x){
    cout << x.beg << ' ' << x.end << ' ' << x.size << ' ' << x.hsh << '\n';
}
node merge(node a, node b){
    if(a.size == 0 && b.size == 0){
        a.end += b.end;
        a.end %= 2;
        a.beg = a.end;
        return a;
        
    }
    else if(b.size == 0){
        a.end += b.end;
        a.end %= 2;
        return a;
    }
    else if(a.size == 0){
        b.beg += a.end;
        b.beg %= 2;
        return b;
    }
    else if((a.end+b.beg)%2 == 0){
        a.hsh = (a.hsh*pwr[b.size-1])%mod;
        a.hsh = (a.hsh+b.hsh)%mod;
        a.end = b.end;
        a.size += b.size-1;
        return a;
    }
    else{
        a.hsh = (a.hsh*pwr[b.size])%mod;
        a.hsh = (a.hsh+b.hsh)%mod;
        a.end = b.end;
        a.size += b.size;
        return a;
    }
}
node seg[800009];
ll n;
string s;
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        if(s[tl] == '0'){
            seg[v].beg = seg[v].end = 0;
            seg[v].size = seg[v].hsh = 1;
        }
        else{
            seg[v].beg = seg[v].end = 1;
            seg[v].size = seg[v].hsh = 0;
        }
    }
    else{
        ll tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }
}
node get(ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || r < tl)
        return {0, 0, 0, 0};
    if(l <= tl && tr <= r)
        return seg[v];
    else{
        ll tm = (tl+tr)/2;
        return merge(get(2*v, tl, tm, l, r), get(2*v+1, tm+1, tr, l, r));
    }
}

ll same(node a, node b){
    return (a.beg%2 == b.beg%2 && a.end%2 == b.end%2 && a.hsh == b.hsh);
}
ll ones[200009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    pwr[0] = 1;
    for(ll i = 1; i <= 200001; ++i)
        pwr[i] = pwr[i-1]*p%mod;
    
    cin >> n >> s;
    //for(ll i = 0; i*sq < n; ++i){
    //    decomp[i] = create(s.substr(i*sq, min(sq, n-i*sq)));
    //}
    ll q;
    cin >> q;
    for(ll i = 1; i <= n; ++i){
        ones[i] = (s[i-1] == '1') + ones[i-1];
    }
    //print(merge({0, 0, 0, 0}, {0, 0, 0, 0}));
    build(1, 0, n-1);
    while(q--){
        ll l1, l2, len;
        cin >> l1 >> l2 >> len;
        --l1;
        --l2;
        node s1 = get(1, 0, n-1, l1, l1+len-1);
        node s2 = get(1, 0, n-1, l2, l2+len-1);
        
        
        if(same(s1, s2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}