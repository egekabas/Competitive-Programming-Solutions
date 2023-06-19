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
int a[1000009];
int go[2000009][2];
int prt[2000009];
int val[2000009];
int cur = 1;
int last = 1;
int n, k;
int extra = 0;
void print(int v){
    if(v == 0 || extra == 0){
        cout << v << ' ';
        return;
    }
    --extra;
    print(v-1);
    print(v-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    cin >> n >> k;
    val[cur] = 30;
    val[0] = 31;
    vector<pii> ans;
    int totcnt = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        while(a[i] >= val[cur] || go[cur][0] && go[cur][1]){
            if(!(go[cur][0] && go[cur][1])){
                ans.pb({1, val[cur]-1});
                totcnt++;
            }
            cur = prt[cur];
        }
        
        while(a[i] < val[cur]){
            int idx;
            if(go[cur][0] == 0)
                idx = 0;
            else
                idx = 1;
            ++last;
            go[cur][idx] = last;
            val[last] = val[cur]-1;
            prt[last] = cur;
            cur = last;
        }
        ans.pb({0, a[i]});
        
        if(a[i] == val[cur])
            cur = prt[cur];
        while(go[cur][0] && go[cur][1])
            cur = prt[cur];
    }
    while(cur != 0){
        if(!(go[cur][0] && go[cur][1])){
            ans.pb({1, val[cur]-1});
            totcnt++;
        }
        cur = prt[cur];
    }
    extra = k-totcnt;
    for(auto u : ans){
        if(u.ff == 0){
            cout << u.ss << ' ';
            continue;
        }
        print(u.ss);
    }
    
}
