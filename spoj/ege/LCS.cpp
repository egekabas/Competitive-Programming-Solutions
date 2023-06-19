#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const int alph = 'z'-'a'+2;
string str;
int n;
int val[500009], nval[500009];
vector<int> vals[500009];
vector<int> suf;
    
int rval[500009], lcp[500009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    
    string a, b;
    cin >> a >> b;

    
    
    str = a;
    str.pb('z'+1);
    str += b;

    n = str.size();

    vector<int> alpcnt(alph);
    for(int i = 0; i < n; ++i){
        alpcnt[str[i]-'a'] = 1;
    }
    for(int i = 1; i < alph; ++i)
        alpcnt[i] += alpcnt[i-1];
    for(int i = 0; i < n; ++i)
        val[i] = alpcnt[str[i]-'a'];

    for(int i = 1; i <= alph; ++i)
        for(int j = 0; j < n; ++j)
            if(val[j] == i)
                suf.pb(j);
    

    for(int len = 1; (1<<(len-1)) < n; ++len){
        int k = (1<<(len-1));

        for(int i = 0; i <= n; ++i)
            vals[i].clear();
        for(int i = n-1; i+k >= n; --i)
            vals[val[i]].pb(i);
        for(auto u : suf)
            if(u-k >= 0){
                u -= k;
                vals[val[u]].pb(u);
            }
        suf.clear();
        for(int i = 0; i <= n; ++i)
            for(auto u : vals[i])
                suf.pb(u);

        pii befval = {-1, -1};
        int befrank = 0;
    
        for(int i : suf){
            if(pii(val[i], ((i+k < n) ? val[i+k] : 0)) == befval)
                nval[i] = befrank;
            else{
                befval = pii(val[i], ((i+k < n) ? val[i+k] : 0));
                nval[i] = ++befrank;
            }
        }
        for(int i = 0; i < n; ++i)
            val[i] = nval[i];
    }
    
    
    for(int i = 0; i < n; ++i)
        rval[suf[i]] = i;
    
    int len = 0;
    for(int i = 0; i < n; ++i){
        if(rval[i] == n-1){
            len = 0;
            continue;
        }
        int j = suf[rval[i]+1];
        while(i+len < n && j+len < n && str[i+len] == str[j+len])
            ++len;
        lcp[rval[i]] = len;
        if(len)
            --len;
    }
    int ans = 0;
    for(int i = 0; i < n-1; ++i)
        if((suf[i] < a.size()) != (suf[i+1] < a.size()))
            ans = max(ans, lcp[i]);
    cout << ans << '\n';
    //cout << (ld)clock()/CLOCKS_PER_SEC << '\n';
