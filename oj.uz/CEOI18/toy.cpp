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
int n;
vector<pii> vec;
vector<int> val[1000009];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n;
 
    map<int, int> mpp;    
    for(int i = 2; i*i <= n; ++i)
        while(n%i == 0){
            n /= i;
            mpp[i]++;
        }
    if(n > 1) mpp[n]++;
    for(auto u : mpp){
        vec.pb(u);
        //cout << u.ff << ' ' << u.ss << '\n';
    }
    val[0] = {0};
    vector<int> cur(vec.size(), 0);
    int n = cur.size();
    int curcnt = 0;
    while(1){
        ++curcnt;
        int add = 1;
 
        for(int i = 0; i < n && add; ++i){
            cur[i]++;
            add = 0;
            if(cur[i] > vec[i].ss){
                cur[i] = 0;
                ++add;
            }
        }
        if(add) break;
        vector<int> nxt(n);
        while(1){
            int add = 1;
            for(int i = 0; i < n && add; ++i){
                nxt[i]++;
                add = 0;
                if(nxt[i] > cur[i]){
                    nxt[i] = 0;
                    ++add;
                }
            }
            if(add) break;
        
            int cursum = 1;
            int nxtval = curcnt;
            int totbef = 1;
 
            //for(int i = 0; i < n; ++i)
            //    cout << vec[i].ff << ' ' << nxt[i] << '\n';
            for(int i = 0; i < n; ++i){
                nxtval -= totbef*nxt[i];
                for(int j = 0; j < nxt[i]; ++j){
                    cursum *= vec[i].ff;
                    //cout << vec[i].ff << '\n';
                }
                totbef *= (vec[i].ss+1);
            }
            //cout << cursum-1 << "\n\n";
            //cout << nxtval << '\n';
            for(auto u : val[nxtval])
                val[curcnt].pb(u+cursum-1);
        }
        sort(all(val[curcnt]));
        val[curcnt].resize(unique(all(val[curcnt]))-val[curcnt].begin());
        //for(int i = 0; i < n; ++i)
        //    cout << vec[i].ff << ' ' << cur[i] << '\n';
        //cout << curcnt << '\n';
        //cout << val[curcnt][0] << "\n\n";
        
    }
    int idx = 0;
    int totbef = 1;
    for(auto u : vec){
        idx += u.ss*totbef;
        totbef *= u.ss+1;
    }
    cout << val[idx].size() << '\n';
    for(auto u : val[idx])
        cout << u << ' ';
}
