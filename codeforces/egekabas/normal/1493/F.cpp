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
int n, m;
int swp;
map<vector<int>, int> mppget;
int cnt = 0;
int get(int h, int w, int i1, int j1, int i2, int j2){
    
    
    vector<int> v;
    if(swp == 0)
        v = {h, w, i1, j1, i2, j2};
    else
        v = {w, h, j1, i1, j2, i2};

    if(mppget[v] == 1) return 1;
    if(mppget[v] == 2) return 0;
    
    cout << "? ";
    if(swp == 0)
        cout << h << ' ' << w << ' ' << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;
    else
        cout << w << ' ' << h << ' ' << j1 << ' ' << i1 << ' ' << j2 << ' ' << i2 << endl;
    int val;
    cin >> val;
    if(val == 0) mppget[v] = 2;
    if(val) mppget[v] = 1;
    return val;
}
map<int, int> dp[1009];
int possible(int len, int x){
    if(dp[len][x] == 1) return 1;
    if(dp[len][x] == 2) return 0;
    //cout << len << ' ' << x << '\n';
    if(x == 1) return 1;
    int val;
    if(x%2 == 0){
        if(get(n, len/2, 1, 1, 1, len/2+1))
            val = possible(len/2, x/2);
        else
            val = 0;
    }
    else if(x%3 == 0){
        if(get(n, len/3, 1, 1, 1, len/3+1) && get(n, len/3, 1, 1, 1, len-len/3+1))
            val = possible(len/3, x/3);
        else
            val = 0;
    }
    else{
        if(get(n, len/x, 1, 1, 1, len-len/x+1))
            val = possible(len-len/x, x-1);
        else
            val = 0;
    }
    if(val == 1) dp[len][x] = 1;
    if(val == 0) dp[len][x] = 2;
    return val;
}
int calc(){
    map<int, int> mpp;
    int tmp = m;
    for(int i = 2; i*i <= tmp; ++i)
        while(tmp%i == 0){
            ++mpp[i];
            tmp /= i;
        }
    if(tmp > 1)
        ++mpp[tmp];
    
    int ret = 1;
    for(auto u : mpp){
        int val = u.ff;
        int cnt = u.ss;
        int totn = m;
        int maxval = 0;
        for(int i = 1; i <= cnt; ++i){
            if(possible(totn, val)){
                totn /= val;
                maxval = i;
            }
            else
                break;
        }
        ret *= (maxval+1);
    }
    return ret;
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m;
    int ans = 1;
    ans *= calc();
    swap(n, m);
    swp = 1;
    for(int i = 0; i <= 1000; ++i)
        dp[i].clear();
    ans *= calc();
    cout << "! " << ans << '\n';
}