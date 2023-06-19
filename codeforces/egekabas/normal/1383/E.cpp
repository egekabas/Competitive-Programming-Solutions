#include <bits/stdc++.h>
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
string s;
const ll mod = 1e9+7;
ll dp[1000009];

ll seg[4000009];
void upd(ll v, ll tl, ll tr, ll idx, ll val){
    if(tl == tr){
        seg[v] = val;
        return;
    }
    if(idx <= (tl+tr)/2)
        upd(2*v, tl, (tl+tr)/2, idx, val);
    else
        upd(2*v+1, (tl+tr)/2+1, tr, idx, val);
    seg[v] = max(seg[2*v], seg[2*v+1]);
}
ll get(ll v, ll tl, ll tr, ll val){
    if(seg[v] < val) return -1;
    if(tl == tr) return tl;
    if(seg[2*v+1] >= val)
        return get(2*v+1, (tl+tr)/2+1, tr, val);
    return get(2*v, tl, (tl+tr)/2, val);
}
vector<int> v;
ll bit[1000009];
ll dpsum;
void updbit(ll idx, ll val){
    dpsum = (dpsum+val)%mod;
    for(++idx; idx <= v.size(); idx += idx&(-idx))
        bit[idx] = (bit[idx]+val)%mod;
}
ll getbit(ll idx){
    ll ret = 0;
    for(++idx; idx; idx -= idx&(-idx))
        ret = (ret+bit[idx])%mod;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    cin >> s;
    int last = -1;
    ll mult = 1;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == '1'){
            if(last == -1){
                mult = i-last;
                last = i;
                continue;
            }
            v.pb(i-last);
            last = i;
        }
    mult = mult*(s.size()-last)%mod;
    if(v.empty()){
        if(last == -1)
            cout << mult-1 << '\n';
        else
            cout << mult << '\n';
        return 0;
    }
    for(ll i = 0; i < v.size(); ++i){
        for(ll j = v[i]; j > 0; --j){
            ll idx = get(1, 0, v.size()-1, j);
            if(idx == -1){
                dp[i] = (dp[i]+dpsum+1)%mod;
                //cout << i << ' ' << j << ' ' << idx << ' ' << dpsum+1 << '\n';
            }
            else{
                //cout << i << ' ' << j << ' ' << idx << ' ' << dpsum-getbit(idx-1)<< '\n';

                dp[i] = (dp[i]+dpsum-getbit(idx-1))%mod;
                dp[i] = (dp[i]+mod)%mod;
            }
        }
        updbit(i, dp[i]);

        upd(1, 0, v.size()-1, i, v[i]);
    }
    cout << mult*(dpsum+1)%mod << '\n';
}