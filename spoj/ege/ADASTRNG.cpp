#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const int alpsize = 'z'-'a'+1;
int fval[300009];
int sval[300009];
vector<int> vals1[300009];
vector<int> vals2[300009];
vector<int> sufsort;
int n;
void radixsort(){
    sufsort.clear();
    for(int i = 0; i <= max(n, alpsize); ++i){
        vals1[i].clear();
        vals2[i].clear();
    }
    
    for(int i = 0; i < n; ++i)
        vals1[sval[i]].pb(i);
    
    for(int i = 0; i <= max(n, alpsize); ++i)
        for(auto u : vals1[i])
            vals2[fval[u]].pb(u);
    
    for(int i = 0; i <= max(n, alpsize); ++i)
        for(auto u : vals2[i])
            sufsort.pb(u);
    
}
void createsuf(string &s){
    sufsort.clear();
    n = s.size();
    for(int i = 0; i < n; ++i)
        fval[i] = sval[i] = 0;
    
    for(int i = 0; i < n; ++i)
        fval[i] = s[i]-'a'+1;
    
    for(int len = 1; (1<<(len-1)) < n; ++len){
        for(int i = 0; i < n; ++i){
            if(i+(1<<(len-1)) < n)
                sval[i] = fval[i+(1<<(len-1))];
            else
                sval[i] = 0;
        }
        radixsort();
        pii befval = {-1e9, -1e9};
        int befrank = 0;
        for(int i = 0; i < n; ++i){
            if(pii(fval[sufsort[i]], sval[sufsort[i]]) == befval)
                fval[sufsort[i]] = befrank;
            else{
                befval = mp(fval[sufsort[i]], sval[sufsort[i]]);
                fval[sufsort[i]] = ++befrank;
            }
        }
    }
}
int lcp[300009];
void createlcp(string &str, vector<int> &suf){
    int n = str.size();
    vector<int> rank(n);
    for(int i = 0; i < n; ++i)
        rank[suf[i]] = i;
    
    int len = 0;
    for(int i = 0; i < n; ++i){
        if(rank[i] == n-1){
            len = 0;
            continue;
        }
        int j = suf[rank[i]+1];
        while(i+len < n && j+len < n && str[i+len] == str[j+len])
            ++len;
        
        lcp[rank[i]] = len;
        if(len)
            --len;
    }
}
    
    
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    string str;
    cin >> str;
    
    
    createsuf(str);
    createlcp(str, sufsort);
    
    
    vector<ll> ans(alpsize);
    for(int i = 0; i < n; ++i)
        ans[str[sufsort[i]]-'a'] += n-sufsort[i]-lcp[i];
        
    for(int i = 0; i < alpsize; ++i)
        cout << ans[i] << ' ';
